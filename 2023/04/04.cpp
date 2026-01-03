#include <iostream>
#include <string>
#include <fstream>
#include <limits>
#include <cmath>

int findWinning(std::string winning, std::string numbers);


int main()
{
    int sum = 0;

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
        sum += findWinning(winning, numbers);
    }

    std::cout << sum << std::endl;

    return 0;
}

int findWinning(std::string winning, std::string numbers)
{
    int exp = -1;
    for(int i = 0; i < 10; i++)
    {   
        std::string number = winning.substr(0+i*3, 2);
        std::string::size_type n = numbers.find(" "+number);
        if(n != std::string::npos)
        {
            std::cout << "Found: " << number << std::endl;
            exp++;
        }
    }

    if(exp > -1)
    {
        std::cout << "Value: " << pow(2, exp) << std::endl;
        return pow(2, exp);
    }
    else
    {
        return 0;
    }
}
