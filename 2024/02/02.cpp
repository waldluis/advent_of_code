#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
#include <sstream>

int sameSign(int a, int b)
{
    return (a >= 0) ^ (b < 0);
}


int main()
{

    std::ifstream is("input.txt");
    std::string str;
    int count = 0;

    while (std::getline(is, str))
    {

        std::vector<int> line;
        std::istringstream iss(str);

        // Zahlen aus jeder Zeile einlesen
        int zahl;
        int ok = 1;
        while (iss >> zahl)
        {
            line.push_back(zahl);
        }

        int now = 0;

        int old = line[0] - line[1];

        if(abs(old) < 1 || abs(old) > 3)
        {
            ok = 0;
        }
        else
        {

            for (int i = 1; i < line.size() - 1; i++)
            {
                now = line[i] - line[i + 1];

                if(abs(now) < 1 || abs(now) > 3)
                {
                    ok = 0;
                    break;
                }

                if(sameSign(old, now) == 0)
                {
                    ok = 0;
                    break;
                }
                old = now;
            }
        }

        if(ok == 1)
        {
            count++;
        }
    }

    std::cout << count << std::endl;
    return 0;
}