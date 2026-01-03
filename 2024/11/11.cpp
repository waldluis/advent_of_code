#include <iostream>
#include <vector>
#include <cmath>

void evaluateStones(std::vector<long long> &stones)
{
    std::vector<long long> newStones;

    for(int i = 0; i < stones.size(); i++)
    {
        // count number of digits
        int count = 0;
        long long stone = stones[i];
        while(stone != 0)
        {
            stone /= 10;
            count++;
        }

        if(stones[i] == 0)
        {
            newStones.push_back(1);
        }
        // if amount of digits is even number, split it into two
        else if(count % 2 == 0)
        {
            long long exp = pow(10, count/2);
            long long firstHalf = stones[i] / exp;
            long long secondHalf = stones[i] % exp;

            newStones.push_back(firstHalf);
            newStones.push_back(secondHalf);
        }
        else
        {
            newStones.push_back(stones[i] * 2024);
        }
        
    }

    stones = newStones;
}

int main()
{
    std::vector<long long> stones = {5, 89749, 6061, 43, 867, 1965860, 0, 206250};

    for(int i = 0; i < 25; i++)
    {
       evaluateStones(stones);
    }

    // // print stones
    // for(int i = 0; i < stones.size(); i++)
    // {
    //     std::cout << stones[i] << " ";
    // }

    std::cout << "Amount of stones: " << stones.size() << std::endl;

    return 0;
}