#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#define STEPS 64                 // test 6, real 64   
#define SIZE 131             // test 11, real 131

struct Point
{
    int x;
    int y;
};

int calcSteps(const std::vector<std::string>& field);
Point findStart(const std::vector<std::string>& field);


int main()
{
    std::ifstream file("input.txt");
    std::vector<std::string> field;
    std::string line;
    while (std::getline(file, line))
    {
        field.push_back(line);
    }

    std::cout << calcSteps(field) << std::endl;


}

int calcSteps(const std::vector<std::string> &field)
{
    std::vector<Point> reached;

    // find start
    reached.push_back(findStart(field));

    for(int i = 0; i < STEPS; i++)
    {
        std::vector<Point> newReached;
        for(int j = 0; j < int(reached.size()); ++j)
        {
            // check up
            if(field[reached[j].y - 1][reached[j].x] == '.' || field[reached[j].y - 1][reached[j].x] == 'S')
            {
                if(reached[j].y != 0)
                {
                    newReached.push_back(Point{reached[j].x, reached[j].y - 1});
                }
            }
            // check down
            if(field[reached[j].y + 1][reached[j].x] == '.' || field[reached[j].y + 1][reached[j].x] == 'S')
            {
                if(reached[j].y != SIZE - 1)
                {
                    newReached.push_back(Point{reached[j].x, reached[j].y +1});
                }
            }
            // check left
            if(field[reached[j].y][reached[j].x - 1] == '.' || field[reached[j].y][reached[j].x - 1] == 'S')
            {
                if(reached[j].x != 0)
                {
                    newReached.push_back(Point{reached[j].x - 1, reached[j].y});
                }
            }
            // check right
            if(field[reached[j].y][reached[j].x + 1] == '.' || field[reached[j].y][reached[j].x + 1] == 'S')
            {
                if(reached[j].x != SIZE - 1)
                {
                    newReached.push_back(Point{reached[j].x + 1, reached[j].y});
                }
            }
        }
        // remove duplicates
        for(int j = 0; j < int(newReached.size()); ++j)
        {
            for(int k = j + 1; k < int(newReached.size()); ++k)
            {
                if(newReached[j].x == newReached[k].x && newReached[j].y == newReached[k].y)
                {
                    newReached.erase(newReached.begin() + k);
                    --k;
                }
            }
        }
        reached = newReached;
    }

    return reached.size();
}

Point findStart(const std::vector<std::string> &field)
{
    for(int i = 0; i < int(field.size()); ++i)
    {
        for(int j = 0; j < int(field[i].size()); ++j)
        {
            if(field[i][j] == 'S')
            {
                return Point{j, i};
            }
        }
    }
}
