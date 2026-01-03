#include <iostream>
#include <vector>
#include <string>
#include <fstream>

struct Point
{
    int x;
    int y;
};

Point findStart(const std::vector<std::string> &field)
{
    for (int i = 0; i < int(field.size()); ++i)
    {
        for (int j = 0; j < int(field[i].size()); ++j)
        {
            if (field[i][j] == '^')
            {
                return Point{j, i};
            }
        }
    }
    return Point{-1, -1};
}

int checkBorders(const std::vector<std::string> &field, const Point &p)
{
    if (p.y < 0)
    {
        return 0;
    }
    if (p.y > int(field.size()) - 2)
    {
        return 0;
    }
    if (p.x < 0)
    {
        return 0;
    }
    if (p.x > int(field[0].size()) - 2)
    {
        return 0;
    }
    return 1;
}

int main()
{
    std::cout << "Hello, World!" << std::endl;
    
    std::ifstream file("input.txt");
    std::vector<std::string> field;
    std::string line;
    while (std::getline(file, line))
    {
        field.push_back(line);
    }

    std::vector<Point> reached;

    // find start
    reached.push_back(findStart(field));

    std::cout << "Size:" << reached.size() << std::endl;

    std::cout << "Start: " << reached[0].x << " " << reached[0].y << std::endl;

    int upDown = -1;   // -1 up, 1 down
    int leftRight = 0; // 1 right, -1 left

    while (1)
    {
        Point currentPos = reached[reached.size() - 1];	

        // check if out of bounds
        if (!checkBorders(field, currentPos))
        {
            break;
        }

        // check field in moving direction
        if (field[currentPos.y + upDown][currentPos.x + leftRight] != '#')
        {
            reached.push_back(Point{currentPos.x + leftRight, currentPos.y + upDown});
        }
        else if (field[currentPos.y + upDown][currentPos.x + leftRight] == '#')
        {
            // turn right
            if (leftRight == 0)
            {
                leftRight = -upDown;
                upDown = 0;
            }
            else
            {
                upDown = leftRight;
                leftRight = 0;
            }
        }

        
    }

    // remove duplicates in reached
    std::vector<Point> reachedNoDuplicates;
    for (int i = 0; i < int(reached.size()); ++i)
    {
        int duplicate = 0;
        for (int j = 0; j < int(reachedNoDuplicates.size()); ++j)
        {
            if (reached[i].x == reachedNoDuplicates[j].x && reached[i].y == reachedNoDuplicates[j].y)
            {
                duplicate = 1;
            }
        }
        if (!duplicate)
        {
            reachedNoDuplicates.push_back(reached[i]);
        }
    }

    std::cout << "Reached: " << std::endl;
    std::cout << reachedNoDuplicates.size() << std::endl;

    return 0;
}