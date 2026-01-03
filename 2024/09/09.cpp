#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>

int main()
{
    // read input from file test.txt into a string
    std::ifstream file("input.txt");
    std::vector<std::string> vec;
    std::string line;

    while (std::getline(file, line))
    {
        for (char ch : line)
        {
            if (std::isdigit(ch))
            {                                         // Prüfen, ob das Zeichen eine Ziffer ist
                vec.push_back(std::string(1, ch)); // Zeichen in einen String umwandeln und hinzufügen
            }
        }
    }

    std::vector<std::string> storage;
    int fileNumber = 0;

    for (size_t i = 0; i < vec.size(); i++)
    {
        // if i is 0 or even
        if (i % 2 == 0)
        {
            for (int j = 0; j < std::stoi(vec[i]); j++)
            {
                storage.push_back(std::to_string(fileNumber));
            }
            fileNumber++;
        }
        else
        {
            for (int j = 0; j < std::stoi(vec[i]); j++)
            {
                storage.push_back(".");
            }
        }
    }

    // std::cout << "Output: ";
    // for (size_t i = 0; i < storage.size(); i++)
    // {
    //     std::cout << storage[i];
    // }
    // std::cout << std::endl;

    int left = 0;
    int right = storage.size() - 1;

    while (left < right)
    {
        if (storage[left] == ".")
        {
            while (storage[right] == ".")
            {
                right--;
            }
            std::swap(storage[left], storage[right]);
            left++;
            right--;
        }
        else
        {
            left++;
        }
    }

    // std::cout << "Output final: ";
    // for (size_t i = 0; i < storage.size(); i++)
    // {
    //     std::cout << storage[i];
    // }

    float count = 0;
    for (size_t i = 0; i < storage.size(); i++)
    {
        if (storage[i] != ".")
        {
            count += i * std::stoi(storage[i]);
        }
    }
    std::cout.precision(15);
    std::cout << std::endl << "Count: " << count << std::endl;

    return 0;
}