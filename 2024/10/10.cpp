#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>

struct Point
{
    int x;
    int y;
};

// function
// depth first search
// start at 0 and go to 9 by always increasing the value by 1
// if the value is 9, then we have found the path
bool dfs(std::vector<std::vector<int>>& heightMap, std::vector<std::vector<bool>>& visited, int x, int y, int &count)
{
    int rows = heightMap.size();
    int cols = heightMap[0].size();

    if(heightMap[x][y] == 9)
    {
        count++;
        return true;
    }

    if(x < 0 || x >= rows || y < 0 || y >= cols || visited[x][y] )
    {
        return false;
    }

    visited[x][y] = true;

    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};

    for(int dir = 0; dir < 4; dir++)
    {
        int newX = x + dx[dir];
        int newY = y + dy[dir];

        if(newX >= 0 && newX < rows && newY >= 0 && newY < cols && heightMap[newX][newY] == heightMap[x][y] + 1)
        {
            if(dfs(heightMap, visited, newX, newY, count))
            {
                return true;
            }  
        }
    }
    return false;
}


int main()
{
    std::vector<std::vector<int>> heightMap;
   
    std::ifstream in("test.txt");
    std::string line;
    while(std::getline(in, line))
    {
        std::vector<int> row;
        for(char ch : line)
        {
            if(isdigit(ch))
            {
                row.push_back(ch - '0');    // convert char to int
            }
        }      
        if(!row.empty())
        {
            heightMap.push_back(row);
        }
    }

    in.close();

    // print the heightMap
    // for(auto row : heightMap)
    // {
    //     for(auto elem : row)
    //     {
    //         std::cout << elem << " ";
    //     }
    //     std::cout << std::endl;
    // }
    
    // find all 0s
    std::vector<Point> zeros;
    for(int i = 0; i < heightMap.size(); i++)
    {
        for(int j = 0; j < heightMap[i].size(); j++)
        {
            if(heightMap[i][j] == 0)
            {
                zeros.push_back({i, j});
            }
        }
    }

    // depth first search
    // start at 0 and go to 9 by always increasing the value by 1
    // if the value is 9, then we have found the path
    int count = 0;
    for(auto point : zeros)
    {
        std::vector<std::vector<bool>> visited(heightMap.size(), std::vector<bool>(heightMap[0].size(), false));
        if(dfs(heightMap, visited, point.x, point.y, count))
        {
            continue;
        }
    }

    std::cout << "Count: " << count << std::endl;

    return 0;
}