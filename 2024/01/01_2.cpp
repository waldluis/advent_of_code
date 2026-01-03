#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
#include <sstream>


int main()
{
    std::vector<int> left;
    std::vector<int> right;

    std::ifstream is("input.txt");
    std::string line;

    while (std::getline(is, line)) {
        std::istringstream iss(line);
        int zahl1, zahl2;
        // Zwei Zahlen aus jeder Zeile einlesen
        if (iss >> zahl1 >> zahl2) {
            left.push_back(zahl1);
            right.push_back(zahl2);
        }
    }

    // Wie oft kommen rechts die Zahlen aus links vor?
    
    int sum = 0;

    for(int i = 0; i < left.size(); i++)
    {
        int count = 0;
        for(int j = 0; j < right.size(); j++)
        {
            if(left[i] == right[j])
            {
                count++;
            }
        }
        sum += count * left[i];
    }
    
    std::cout << sum << std::endl;

}