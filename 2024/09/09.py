# Day 9 - https://adventofcode.com/2024/day/9
#
###############################################################################

data = open("input.txt").read()

# Part 1
#
# The data is interleaved 'block then gap'
# We move the block to our 'nogaps' list, then try to fill the gap. 
# we do this by repeatedly popping a block off the end of the block list, 
# and using as much of it as we can.

from collections import deque
def part1(data):
    # parse data into a list of (block_id, block_size), and a list of gap lengths
    blocks = deque(enumerate(int(n) for n in data[::2]))
    gaps = deque(int(n) for n in data[1::2])

    # Remove all the gaps
    nogaps = []
    while blocks:
        front_block = blocks.popleft()
        nogaps.append(front_block)
        if gaps:
            front_gap = gaps.popleft()
            while blocks and front_gap:
                bid, bsize = blocks.pop()
                if bsize <= front_gap:
                    nogaps.append((bid, bsize))
                    front_gap -= bsize
                else:
                    nogaps.append((bid, front_gap))
                    blocks.append((bid, bsize-front_gap))
                    front_gap = 0

    # calculates the required checksum
    total = 0
    i = 0
    for bid, bsize in nogaps:
        total += bid*bsize*(2*i + bsize-1)//2
        i += bsize
    return total

# Part 2
#
# Now we are moving whole files at a time.
# We make a priority queue for each gap size, sorted by gap position.
# For each block, we look at all the gaps it will fit in, keeping the earlier
# and pushing all the others back. We put the file in that gap if it exists,
# and if it's *to the left of the current position*
# This means we're going to have to recreate our block and gap list, keeping
# track of the initial positions this time.

import heapq
def part2(data):
    # parse data into a list of blocks, and separate lists of gaps
    is_block = True
    blocks = []
    gaps = [[] for i in range(10)]
    pos, b_id = 0, 0
    for d in data:
        d = int(d)
        if is_block:
            blocks.append([pos, b_id, d])
            b_id += 1
        else:
            heapq.heappush(gaps[d], pos)
        pos += d
        is_block = not is_block

    # now process each block in reverse order, updating position if possible
    checksum = 0
    for b in range(len(blocks))[::-1]:
        bpos, bid, bsize = blocks[b]

        best_pos = bpos
        candidates = [(heapq.heappop(gaps[i]), i) for i in range(10) if gaps[i] and i>=bsize]
        if candidates:
            gpos, glen = min(candidates)
            if gpos < bpos:
                best_pos = gpos
                candidates.remove((gpos, glen))
                heapq.heappush(gaps[glen-bsize], gpos+bsize)
            for gpos, glen in candidates:
                heapq.heappush(gaps[glen], gpos)
            blocks[b][0] = best_pos

        checksum += bid*bsize*(2*best_pos + bsize-1)//2
    return checksum

print("Part 1:", part1(data))
# print("Part 2:", part2(data))