#include <iostream>
#include <string>
#include <fstream>

int checkCubes(std::string line);

int main()
{

    int sum = 0;

    std::ifstream is("input.txt");
    std::string line;
    while(std::getline(is, line))
    {
        sum += checkCubes(line);
    }

    std::cout << sum << std::endl;
}

int checkCubes(std::string line)
{
    int red = 0;
    int green = 0;
    int blue = 0;

    std::string game = line.substr(0, line.find(":"));

    std::string games = line.substr(line.find(":") + 2, line.length() - line.find(":") - 2);

    while (games.length() > 0)
    {
        std::string cube = games.substr(0, games.find(";"));
        if(games.find(";") == std::string::npos)
        {
            games = "";
        }
        else
        {
            games = games.substr(games.find(";") + 2, games.length() - games.find(";") - 2);
        }
        

        while (cube.length() > 0)
        {
            std::string color = cube.substr(cube.find(" ") + 1, cube.find(",") - cube.find(" ") - 1);
            int number = std::stoi(cube.substr(0, cube.find(" ")));
            if(cube.find(",") == std::string::npos)
            {
                cube = "";
            }
            else
            {
                cube = cube.substr(cube.find(",") + 2, cube.length() - cube.find(",") - 2);
            }

            if (color == "red")
            {
                if (number > red)
                {
                    red = number;
                }
            }
            else if (color == "green")
            {
                if (number > green)
                {
                    green = number;
                }
            }
            else if (color == "blue")
            {
                if (number > blue)
                {
                    blue = number;
                }
            }
        }
    }

    return red * green * blue;
}