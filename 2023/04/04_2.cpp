#include <iostream>
#include <string>
#include <fstream>
#include <limits>
#include <cmath>

#define IMAX 201

void findWinning(std::string winning, std::string numbers, int i);

int array[202] = {};

int main()
{
    int index = 0;

    for(int i = 0; i <= IMAX; i++)
    {
        array[i] = 1;
    }

    std::ifstream is("input.txt");
    std::string line;
    std::string winning;
    std::string numbers;
    while (std::getline(is, line))
    {
        winning = line.substr(line.find(":")+2, line.find("|")-1-8);
        numbers = line.substr(line.find("|")+1, 75);            // test 23 char, input 74 char

        std::cout << winning << std::endl;
        std::cout << numbers << std::endl;
        findWinning(winning, numbers, index);
        index++;
    }

    int sum = 0;
    for(int j = 0; j <= IMAX; j++)
    {
        sum += array[j];
    }

    std::cout << sum << std::endl;

    return 0;
}

void findWinning(std::string winning, std::string numbers, int index)
{
    int exp = 0;
    for(int i = 0; i < 10; i++)
    {   
        std::string number = winning.substr(0+i*3, 2);
        std::string::size_type n = numbers.find(" "+number);
        if(n != std::string::npos)
        {
            exp++;
            if(exp+index <= IMAX)
            {
                array[index+exp]++;
                array[index+exp] += array[index]-1;
            }
            std::cout << "Found: " << number << std::endl;
        }
    }
}
