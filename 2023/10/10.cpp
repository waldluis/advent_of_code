#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#define MAP_SIZE 140              // test 5, input 140

struct position
{
    int x;
    int y;
};

position getStart(std::vector<std::string> *map);
int getWayCount(std::vector<std::string> *map, position pos);

int main()
{
    int wayCount = 0;
    std::ifstream is("input.txt");
    std::string line;
    std::vector<std::string> map;
    position pos;
    pos.x = 0;
    pos.y = 0;

    while (std::getline(is, line))
    {
        map.push_back(line);
    }

    pos = getStart(&map);
    std::cout << "Start: " << pos.x << ", " << pos.y << std::endl;
    wayCount = getWayCount(&map, pos);
    std::cout << "WayCount: " << wayCount / 2 << std::endl;

    return 0;
}

position getStart(std::vector<std::string> *map)
{
    position pos;
    pos.x = 0;
    pos.y = 0;

    for (int i = 0; i < MAP_SIZE; i++)
    {
        for (int j = 0; j < MAP_SIZE; j++)
        {
            std::string hilf = map->at(i);
            if (hilf.at(j) == 'S')
            {
                pos.x = j;
                pos.y = i;
                return pos;
            }
        }
    }
    return pos;
}

int getWayCount(std::vector<std::string> *map, position pos)
{
    volatile position posNow = pos;
    int wayCount = 0;
    int nextMove = 0; // 1 = up, 2 = right, 3 = down, 4 = left

    do
    {
        std::string lineNow = map->at(posNow.y);
        std::string lineBelow = lineNow;
        std::string lineAbove = lineNow;
        if (posNow.y != MAP_SIZE - 1)
        {
            lineBelow = map->at(posNow.y + 1);
        }
        if (posNow.y != 0)
        {
            lineAbove = map->at(posNow.y - 1);
        }

        switch (nextMove)
        {
        // initial move
        case 0:
            if (posNow.y > 0 && lineAbove.at(posNow.x) == '|')
            {
                posNow.y--;
                wayCount++;
                nextMove = 1;
                break;
            }
            else if (posNow.y > 0 && lineAbove.at(posNow.x) == '7')
            {
                posNow.y--;
                wayCount++;
                nextMove = 4;
                break;
            }
            else if (posNow.y > 0 && lineAbove.at(posNow.x) == 'F')
            {
                posNow.y--;
                wayCount++;
                nextMove = 2;
                break;
            }
            else if (posNow.x < MAP_SIZE-1 && lineNow.at(posNow.x + 1) == '-')
            {
                posNow.x++;
                wayCount++;
                nextMove = 2;
                break;
            }
            else if (posNow.x < MAP_SIZE-1 && lineNow.at(posNow.x + 1) == 'J')
            {
                posNow.x++;
                wayCount++;
                nextMove = 1;
                break;
            }
            else if (posNow.x < MAP_SIZE-1 && lineNow.at(posNow.x + 1) == '7')
            {
                posNow.x++;
                wayCount++;
                nextMove = 3;
                break;
            }
            else if (posNow.x > 0 && lineNow.at(posNow.x - 1) == '-')
            {
                posNow.x--;
                wayCount++;
                nextMove = 4;
                break;
            }
            else if (posNow.x > 0 && lineNow.at(posNow.x - 1) == 'L')
            {
                posNow.x--;
                wayCount++;
                nextMove = 1;
                break;
            }
            else if (posNow.x > 0 && lineNow.at(posNow.x - 1) == 'F')
            {
                posNow.x--;
                wayCount++;
                nextMove = 3;
                break;
            }
            break;

        // moving up
        case 1:
            if (posNow.y > 0 && lineAbove.at(posNow.x) == '|')
            {
                posNow.y--;
                wayCount++;
                nextMove = 1;
                break;
            }
            else if (posNow.y > 0 && lineAbove.at(posNow.x) == '7')
            {
                posNow.y--;
                wayCount++;
                nextMove = 4;
                break;
            }
            else if (posNow.y > 0 && lineAbove.at(posNow.x) == 'F')
            {
                posNow.y--;
                wayCount++;
                nextMove = 2;
                break;
            }
            else if (posNow.y > 0 && lineAbove.at(posNow.x) == 'S')
            {
                posNow.y--;
                wayCount++;
                nextMove = 3;
                break;
            }
            break;
        // moving right
        case 2:
            if (posNow.x < MAP_SIZE -1 && lineNow.at(posNow.x + 1) == '-')
            {
                posNow.x++;
                wayCount++;
                nextMove = 2;
                break;
            }
            else if (posNow.x < MAP_SIZE-1 && lineNow.at(posNow.x + 1) == 'J')
            {
                posNow.x++;
                wayCount++;
                nextMove = 1;
                break;
            }
            else if (posNow.x < MAP_SIZE-1 && lineNow.at(posNow.x + 1) == '7')
            {
                posNow.x++;
                wayCount++;
                nextMove = 3;
                break;
            }
            else if (posNow.x < MAP_SIZE-1 && lineNow.at(posNow.x + 1) == 'S')
            {
                posNow.y--;
                wayCount++;
                nextMove = 3;
                break;
            }
            break;
        // moving down
        case 3:
            if (posNow.y < MAP_SIZE-1 && lineBelow.at(posNow.x) == '|')
            {
                posNow.y++;
                wayCount++;
                nextMove = 3;
                break;
            }
            else if (posNow.y < MAP_SIZE-1 && lineBelow.at(posNow.x) == 'J')
            {
                posNow.y++;
                wayCount++;
                nextMove = 4;
                break;
            }
            else if (posNow.y < MAP_SIZE-1 && lineBelow.at(posNow.x) == 'L')
            {
                posNow.y++;
                wayCount++;
                nextMove = 2;
                break;
            }
            else if (posNow.y < MAP_SIZE-1 && lineBelow.at(posNow.x) == 'S')
            {
                posNow.y--;
                wayCount++;
                nextMove = 3;
                break;
            }
            break;
        // moving left
        case 4:
            if (posNow.x > 0 && lineNow.at(posNow.x - 1) == '-')
            {
                posNow.x--;
                wayCount++;
                nextMove = 4;
                break;
            }
            else if (posNow.x > 0 && lineNow.at(posNow.x - 1) == 'L')
            {
                posNow.x--;
                wayCount++;
                nextMove = 1;
                break;
            }
            else if (posNow.x > 0 && lineNow.at(posNow.x - 1) == 'F')
            {
                posNow.x--;
                wayCount++;
                nextMove = 3;
                break;
            }
            else if (posNow.x > 0 && lineNow.at(posNow.x - 1) == 'S')
            {
                posNow.y--;
                wayCount++;
                nextMove = 3;
                break;
            }
            break;
        // default
        default:
            break;
        }

        if (map->at(posNow.y).at(posNow.x) == 'S')
        {
            return wayCount;
        }
    } while (map->at(posNow.y).at(posNow.x) != 'S');
    return 0;
}