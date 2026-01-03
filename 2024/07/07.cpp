#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <map>


int main()
{
    std::string filename = "test.txt";
    std::map<int, std::vector<int>> instructions;

    std::ifstream file(filename);
    std::string line;
    while(std::getline(file, line))
    {
        std::stringstream ss(line);
        int key;
        char colon;
        if(!(ss >> key >> colon) || colon != ':')
        {
            std::cerr << "Error reading line: " << line << std::endl;
            continue;
        }

        std::vector<int> values;
        int value;
        while(ss >> value)
        {
            values.push_back(value);
        }

        instructions[key] = values;
    }    

    int count = 0;

    // loop through instructions
    for(auto &instruction : instructions)
    {
        // find length of instruction
        int length = instruction.second.size();


        // the first element can be calculated out of the second element
        // by adding or multiplying the elements
        // check all possible combinations for various lengths
        // start with all adding and increase the number of multiplications
        // until the length is reached
        for(int i = 1; i < length; i++)
        {
            
        }



    }


    return 0;
}