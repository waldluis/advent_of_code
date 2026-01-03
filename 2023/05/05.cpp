#include <iostream>
#include <string>
#include <fstream>
#include <limits>
#include <cmath>

#define SIZE 18                     // test 18, input 230
#define LENGTH 4                     // test 4, input 20

void getSeeds(int seeds[LENGTH], std::ifstream* is);

void getMaps(int map[SIZE][3], std::ifstream* is);

int getLocation(int plant, int map[SIZE][3]);


int main()
{
    int lowest = 999999999;

    std::ifstream is("test.txt");
    int seeds[LENGTH] = {0};
    int map[SIZE][3];        
    
    getSeeds(seeds, &is);
    getMaps(map, &is);

    lowest = getLocation(13, map);
    std::cout << lowest << std::endl;

    // for(int i = 0; i < 18; i++)
    // {
    //     std::cout << maps[i] << std::endl;
    // }
    // std::cout << seeds << std::endl;
    return 0;
}

void getSeeds(int seeds[LENGTH], std::ifstream* is)
{
    std::string line;
    std::getline(*is, line);
    seeds[0] = std::stoi(line.substr(line.find(" "),line.find(" ")+1));
    for(int i = 1; i < LENGTH-1; i++)
    {
        seeds[i] = std::stoi(line.substr(line.find(" ")+i, line.find(" ", line.find(" ")+i+1)));
    }
    seeds[LENGTH-1] = std::stoi(line.substr(line.find_last_of(" ")+1, line.length()));
    
}

void getMaps(int maps[SIZE][3], std::ifstream *is)
{
    std::string line;
    int i = 0;
    while(std::getline(*is, line))
    {
        if(line == "")
        {
            continue;
        }
        else if(isdigit(line.at(0)))
        {
            
            maps[i][0] = std::stoi(line.substr(0,line.find(" ")));
            maps[i][1] = std::stoi(line.substr(line.find(" ")+1, line.find(" ", line.find(" ")+1)));
            maps[i][2] = std::stoi(line.substr(line.find_last_of(" ")+1, line.length()));
            i++;
        }
    }
}

int getLocation(int plant, int map[SIZE][3])
{
    for(int i = 0; i < SIZE; i++)
    {
        int source = map[i][1];
        int dest = map[i][0];
        int range = map[i][2];

        if((plant >= source) && (plant < (source + range)))
        {
            plant = plant + (dest - source);
        }
    }
    return plant;
}
