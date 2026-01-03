#include <iostream>
#include <string>
#include <fstream>
#include <limits>
#include <cmath>
#include <vector>
#include <algorithm>

#define N_NODES 750 // test: 7, input: 750

int calcSteps(std::string* node, std::string* left, std::string* right, std::string way);
void getArrays(std::ifstream *is, std::string* node, std::string* left, std::string* right);

int main()
{
    int sum = 0;
    std::string way;

    std::ifstream is("input.txt");
    std::string node[N_NODES];
    std::string left[N_NODES];
    std::string right[N_NODES];

    std::getline(is, way);

    getArrays(&is, node, left, right);

    sum = calcSteps(node, left, right, way);

    std::cout << sum << std::endl;

    return 0;
}

int calcSteps(std::string* node, std::string* left, std::string* right, std::string way)
{
    int sum = 0;
    int wayCount = 0;
    volatile int index = 0;

    for (int i = 0; i < N_NODES; i++)
    {
        if (node[i] == "AAA")
        {
            index = i;
            break;
        }
    }

    while (1)
    {
        std::string test = node[index];
        if (node[index] == "ZZZ")
        {
            return sum;
        }

        if (way.at(wayCount) == 'L')
        {
            std::string help = left[index];
            for (int i = 0; i < N_NODES; i++)
            {
                if (node[i] == help)
                {
                    index = i;
                    break;
                }
            }
        }
        else if (way.at(wayCount) == 'R')
        {
            std::string help = right[index];
            for (int i = 0; i < N_NODES; i++)
            {
                if (node[i] == help)
                {
                    index = i;
                    break;
                }
            }
        }

        sum++;
        wayCount++;
        if (wayCount == int(way.size()))
        {
            wayCount = 0;
        }
    }
}

void getArrays(std::ifstream *is, std::string* node, std::string* left, std::string* right)
{
    int i = 0;
    int n = 0;
    std::string line;
    while (std::getline(*is, line))
    {
        if (n < 1)
        {
            n++;
            continue;
        }
        else
        {
            std::string::size_type n = line.find(" ");
            if (n != std::string::npos)
            {
                node[i] = line.substr(0, 3);
                left[i] = line.substr(line.find("(") + 1, 3);
                right[i] = line.substr(line.find(",") + 2, 3);
                i++;
            }
        }
    }
}
