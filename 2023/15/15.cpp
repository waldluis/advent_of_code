#include <iostream>
#include <fstream>
#include <string>

int main()
{
    int sum = 0;
    std::ifstream is("input.txt");
    std::string line;
    std::getline(is, line);

    // line = "rn=1";

    // std::cout << line << std::endl;
    int sumHelp = 0;

    // std::cout << static_cast<int>('a') << std::endl;

    // loop through the string for commas
    for (int i = 0; i < int(line.size()); i++)
    {
        if (line.at(i) == ',')
        {
            sum += sumHelp;
            sumHelp = 0;
        }
        else
        {
            sumHelp += static_cast<int>(line.at(i));
            sumHelp = sumHelp * 17;
            sumHelp = sumHelp % 256;
        }
    }
    sum += sumHelp;

    std::cout << sum << std::endl;
}