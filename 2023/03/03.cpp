#include <iostream>
#include <string>
#include <fstream>
#include <limits>

#define LINEMAX 139

int checkAdjacents(std::string line);

int main()
{
    int sum = 0;

    std::ifstream is("input.txt");
    std::string line;
    std::string text[140]; // test = 10, input = 140
    int i = 0;
    std::string stNumber = "0";
    bool b = false;
    while (std::getline(is, line))
    {
        text[i] = line;
        i++;
    }

    // find number in line
    char const *digits = "0123456789";
    char const *symbols = "*$%+/=@-#&";
    int start = 0;

    for (int i = 0; i <= LINEMAX; i++)
    {

        while (start < text[i].length())
        {
            std::string::size_type n = text[i].find_first_of(digits, start);
            start = n;
            if (n != std::string::npos)
            {
                int number = std::stoi(text[i].substr(n, text[i].find(symbols)));
                stNumber = std::to_string(number);
                start += stNumber.length();

                if (n != 0)
                {
                    n--;
                }

                // find symbol in line
                std::string::size_type m = text[i].find_first_of(symbols, n);
                if (m != std::string::npos)
                {
                    if (m == n || m == n + stNumber.length()+1 || m == n + stNumber.length())
                    {
                        b = true;
                    }
                }

                // find symbol in line above
                if (i != 0 && b == false)
                {
                    std::string hilf = text[i - 1].substr(n, stNumber.length() + 2);
                    std::string::size_type o = hilf.find_first_of(symbols);
                    if (o != std::string::npos)
                    {
                        o = o + n;
                        if (n <= o && o <= n + stNumber.length()+1)
                        {
                            b = true;
                        }
                    }
                }

                // find symbol in line below
                if (i != LINEMAX && b == false)
                {

                    std::string hilf = text[i + 1].substr(n, stNumber.length() + 2);
                    std::string::size_type o = hilf.find_first_of(symbols);
                    if (o != std::string::npos)
                    {
                        o = o + n;
                        if (n <= o && o <= n + stNumber.length()+1)
                        {
                            b = true;
                        }
                    }
                }

                if (b)
                {
                    std::cout << stNumber << std::endl;
                    sum += std::stoi(stNumber);
                }
                b = false;
            }
            else
            {
                start = text[i].length();
            }
        }
        start = 0;
    }
    std::cout << sum << std::endl;
    return 0;
}

int checkAdjacents(std::string line)
{
    return 0;
}
