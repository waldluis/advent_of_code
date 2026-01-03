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

    // Vektoren aufsteigend sortieren
    std::sort(left.begin(), left.end());
    std::sort(right.begin(), right.end());

    int sum = 0;

    // Summe der Differenzen berechnen
    for (int i = 0; i < left.size(); i++) {
        sum += std::abs(left[i] - right[i]);
    }

    std::cout << sum << std::endl;

}