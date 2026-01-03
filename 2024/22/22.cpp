#include <iostream>
#include <string>
#include <fstream>

void calculateSecretNumber(long long &number)
{
    long long temp = number * 64;
    number ^= temp;
    number = number % 16777216;

    temp = number / 32;
    number ^= temp;
    number = number % 16777216;

    temp = number * 2048;
    number ^= temp;
    number = number % 16777216;

}

int main()
{
    std::string fileName = "input.txt";
    std::ifstream file(fileName);
    std::string line;

    long long sum = 0;

    while (std::getline(file, line))
    {
        long long number = std::stoll(line);
        long long start = number;
        
        for(int i = 0; i < 2000; i++)
        {
            calculateSecretNumber(number);
        }

        sum += number;

        std::cout << "Start: " << start << " Number: " << number << std::endl;

    }

    std::cout << "Sum: " << sum << std::endl;


    return 0;
}