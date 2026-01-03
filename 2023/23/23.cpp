#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#define SIZE 141 // test 23, input 141

int longestPath = 0;
bool visited[SIZE][SIZE] = {false};

struct Point
{
    int x;
    int y;
};

void findPath(const std::vector<std::string> &field, Point position, int steps);

int main()
{
    std::ifstream file("input.txt");
    std::vector<std::string> field;
    std::string line;
    while (std::getline(file, line))
    {
        field.push_back(line);
    }

    Point position = {1, 0};

    // part 2
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (field[i][j] == 'v' || field[i][j] == '^' || field[i][j] == '<' || field[i][j] == '>')
            {
                field[i][j] = '.';
            }
        }
    }

    findPath(field, position, 0);

    std::cout << longestPath << std::endl;

    // for(int i = 0; i < SIZE; i++)
    // {
    //     std::cout << field[i] << std::endl;
    // }
}

void findPath(const std::vector<std::string> &field, Point position, int steps)
{
    visited[position.y][position.x] = true;

    if (position.y == SIZE - 1 && position.x == SIZE - 2)
    {
        if (steps > longestPath)
        {
            longestPath = steps;
        }
        visited[position.y][position.x] = false;
        return;
    }

    // check right
    if ((field[position.y][position.x + 1] == '.' || field[position.y][position.x + 1] == '>') && !visited[position.y][position.x + 1])
    {
        findPath(field, Point{position.x + 1, position.y}, steps + 1);
    }
    // check down
    if ((field[position.y + 1][position.x] == '.' || field[position.y + 1][position.x] == 'v') && !visited[position.y + 1][position.x])
    {
        findPath(field, Point{position.x, position.y + 1}, steps + 1);
    }
    // check left
    if ((field[position.y][position.x - 1] == '.' || field[position.y][position.x - 1] == '<') && !visited[position.y][position.x - 1])
    {
        findPath(field, Point{position.x - 1, position.y}, steps + 1);
    }
    // check up
    if ((position.y != 0 && (field[position.y - 1][position.x] == '.' || field[position.y - 1][position.x] == '^')) && !visited[position.y - 1][position.x])
    {
        findPath(field, Point{position.x, position.y - 1}, steps + 1);
    }

    visited[position.y][position.x] = false;
}
