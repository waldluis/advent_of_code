#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

int sumOfNumbers(std::string line);

int main()
{
    std::string test = "1abc2";
    int sum = 0;
    int i = 0;

    std::ifstream is("input.txt");
    std::string line;
    while(std::getline(is, line))
    {
        sum += sumOfNumbers(line);
        i++;
    }

    std::cout << sum << std::endl;
}

int sumOfNumbers(std::string line)
{
    int number =0;
    // get first number
    for(int i = 0; i < int(line.length()); i++)
    {
        if(isdigit(line[i]))
        {
            char c = line[i];
            number = 10* (int(c)-48);
            break;
        }
    }

    // get last number
    for(int i = line.length()-1; i >= 0; i--)
    {
        if(isdigit(line[i]))
        {
            char c = line[i];
            number += (int(c)-48);
            break;
        }
    }
    std::cout << number << std::endl;
    return number;
}