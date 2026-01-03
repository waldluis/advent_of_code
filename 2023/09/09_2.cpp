#include <iostream>
#include <string>
#include <fstream>
#include <limits>
#include <vector>
#include <sstream>
#include <algorithm>

#define LINE_LENGTH 21 // test: 6, input: 21

std::vector<int> getLine(const std::string &input);
int interpolate(const std::vector<int> &numbers);

int main()
{
    int sum = 0;
    std::ifstream is("input.txt");
    std::string line;

    while (std::getline(is, line))
    {
        std::vector<int> numbers = getLine(line);
        sum += interpolate(numbers);
    }

    std::cout << "Sum: " << sum << std::endl;

    return 0;
}

std::vector<int> getLine(const std::string &input)
{
    std::vector<int> result;
    std::istringstream iss(input);
    int number;

    while (iss >> number)
    {
        result.push_back(number);

        // Ignoriere Leerzeichen oder andere Nicht-Ziffern-Zeichen
        iss.ignore();
    }

    return result;
}

int interpolate(const std::vector<int> &numbers)
{
    std::vector<int> result;

    for (int i = 0; i < int(numbers.size()) - 1; i++)
    {
        result.push_back(numbers[i + 1] - numbers[i]);
    }

    if (std::all_of(result.begin(), result.end(), [](int i)
                    { return i == 0; }))
    {
        return numbers.front();
    }

    return numbers.front() - interpolate(result);
}
