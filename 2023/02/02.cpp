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
    int red = 12;
    int green = 13;
    int blue = 14;



    std::string gameLine = line.substr(0, line.find(":"));                                              // get games written in line
    int gameNumber = std::stoi(gameLine.substr(5, gameLine.length() - 5));                              // get game number

    std::string game = line.substr(line.find(":") + 2, line.length() - line.find(":") - 2);             // get cubes per take out of bag

    while (game.length() > 0)                                                                           // check cubes per take out of bag
    {
        std::string cube = game.substr(0, game.find(";"));                                              // get cube color and number

        if(game.find(";") == std::string::npos)                                                         // if no more cubes
        {
            game = "";
        }
        else
        {
            game = game.substr(game.find(";") + 2, game.length() - game.find(";") - 2);
        }
        

        while (cube.length() > 0)                                                                       // check cube color and number for each cube in take out of bag
        {
            std::string color = cube.substr(cube.find(" ") + 1, cube.find(",") - cube.find(" ") - 1);   // get cube color
            int number = std::stoi(cube.substr(0, cube.find(" ")));                                     // get cube number
            if(cube.find(",") == std::string::npos)                                                     // if no more cubes                                      
            {
                cube = "";
            }
            else
            {
                cube = cube.substr(cube.find(",") + 2, cube.length() - cube.find(",") - 2);
            }

            // check if number of cubes is higher than allowed
            if (color == "red")
            {
                if (number > red)
                {
                    return 0;
                }
            }
            else if (color == "green")
            {
                if (number > green)
                {
                    return 0;
                }
            }
            else if (color == "blue")
            {
                if (number > blue)
                {
                    return 0;
                }
            }
        }
    }

    return gameNumber;
}