#include <iostream>
#include <string>
#include <fstream>
#include <limits>
#include <cmath>
#include <vector>
#include <algorithm>
#include <list>

#define N_NODES 750 // test: 8, input: 750

int64_t calcSteps(std::string* node, std::string* left, std::string* right, std::string way);
void getArrays(std::ifstream *is, std::string* node, std::string* left, std::string* right);
std::vector<int> getNodes(std::string *node, char c);
bool checkLastChar(std::string node, char c);

int main()
{
    int64_t sum = 0;
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

int64_t calcSteps(std::string* node, std::string* left, std::string* right, std::string way)
{
    int64_t sum = 0;
    int wayCount = 0;

    std::vector<int> indexes = getNodes(node, 'A');
    const int NODES_SIZE = indexes.size();

    while (1)
    {
        bool isZ = true;
        for (int i = 0; i < NODES_SIZE; i++)
        {
            isZ = checkLastChar(node[indexes.at(i)], 'Z');
        }

        if (isZ == true)
        {
            return sum * NODES_SIZE;
        }

        if (way.at(wayCount) == 'L')
        {
            for (int i = 0; i < NODES_SIZE; i++)
            {
                std::string help = left[indexes.at(i)];
                for (int j = 0; j < N_NODES; j++)
                {
                    if (node[j] == help)
                    {
                        indexes.at(i) = j;
                        j = N_NODES;
                    }
                }
            }
        }
        else if (way.at(wayCount) == 'R')
        {
            for (int i = 0; i < NODES_SIZE; i++)
            {
                std::string help = right[indexes.at(i)];
                for (int j = 0; j < N_NODES; j++)
                {
                    if (node[j] == help)
                    {
                        indexes.at(i) = j;
                        j = N_NODES;
                    }
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

std::vector<int> getNodes(std::string *node, char c)
{
    std::vector<int> numbers;
    int j = 0;
    for (int i = 0; i < N_NODES; i++)
    {
        if (node[i].at(2) == c)
        {
            numbers.push_back(i);
            j++;
        }
    }
    return numbers;
}

bool checkLastChar(std::string node, char c)
{
    if (node.at(2) == c)
    {
        return true;
    }
    return false;
}
