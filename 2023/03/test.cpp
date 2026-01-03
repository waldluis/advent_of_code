#include <iostream>
#include <string>
#include <fstream>
#include <limits>

#define LINE 9
#define LENGTH 10

int main()
{
    // int sum = 0;

    std::ifstream is("test.txt");
    std::string line;
    std::string text[10]; // test = 10, input = 140
    int i = 0;
    std::string stNumber = "0";
    while (std::getline(is, line))
    {
        text[i] = line;
        i++;
    }

    // find number in line
    char const *digits = "0123456789";
    char const *symbols = "*$%+/=@-";
    int start = 0;

    while (start < text[LINE].length())
    {
        std::string::size_type n = text[LINE].find_first_of(digits, start);
        start = n;
        if (n != std::string::npos)
        {
            int number = std::stoi(text[LINE].substr(n, text[LINE].find(symbols)));
            stNumber = std::to_string(number);
            std::cout << stNumber << std::endl;

            start += stNumber.length();
        }
        else
        {
            start = text[LINE].length();
        }
    }
    return 0;
}