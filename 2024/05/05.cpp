#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <map>

void loadRules(const std::string &filename, std::map<int, std::vector<int>> &rules)
{
    std::ifstream file(filename);

    std::string line;
    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string key;
        while (getline(ss, key, '\n'))
        {
            size_t delimiterPos = key.find("|");
            if (delimiterPos != std::string::npos)
            {
                int first = std::stoi(key.substr(0, delimiterPos));
                int second = std::stoi(key.substr(delimiterPos + 1));
                rules[first].push_back(second);
            }
        }
    }
}

int main()
{
    std::string filename = "rules.txt";
    std::map<int, std::vector<int>> rulesGraph;

    loadRules(filename, rulesGraph);

    std::ifstream is("pages.txt");
    std::string str;
    int count = 0;

    while (std::getline(is, str))
    {
        std::vector<int> page;
        std::istringstream iss(str);
        
        std::string line;
        while(std::getline(iss, line))
        {
            std::stringstream ss(line);

            while(std::getline(ss, line, ','))
            {
                page.push_back(std::stoi(line));
            }
        }

        // loop through page
        int ok = 1;

        //print page
        for (int i = 0; i < page.size(); i++)
        {
            std::cout << page[i] << " ";
        }
        std::cout << std::endl;

        for(int i = 0; i < page.size() - 1; i++)
        {
            // check if number of the page is in the rules
            if(rulesGraph.find(page[i]) != rulesGraph.end())
            {
                // get index of the number in the page
                auto it = std::find(page.begin(), page.end(), page[i]);

                // check if all numbers of the rule are right to the one in the page
                for(int j = 0; j < rulesGraph[page[i]].size(); j++)
                {
                    auto it2 = std::find(page.begin(), page.end(), rulesGraph[page[i]][j]);
                    if(it2 < it)
                    {
                        ok = 0;
                        break;
                    }
                }
            }
        }

        if (ok == 1)
        {
            // find middle number of the page
            int middle = page.size() / 2;
            count += page[middle];
        }
    }
    std::cout << count << std::endl;
}