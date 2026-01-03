#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#define SIZE 600

void digBorder(std::vector<std::string> *input, std::vector<std::string> *field);
void digField(std::vector<std::string> *field);
int countVolume(std::vector<std::string> *field);

int main()
{
    std::ifstream is("input.txt");
    std::string line;
    std::vector<std::string> input;
    while (std::getline(is, line))
    {
        input.push_back(line);
    }

    std::vector<std::string> field;

    // init field
    for (int i = 0; i < SIZE; i++)
    {
        std::string row;
        for (int j = 0; j < SIZE; j++)
        {
            row.push_back('0');
        }
        field.push_back(row);
    }

    digBorder(&input, &field);
    digField(&field);

    // print field
    std::ofstream os("output.pbm");
    os << "P1" << std::endl;
    os << SIZE << " " << SIZE << std::endl;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            os << field[i][j];
        }
        os << std::endl;
    }
    os.close();

    std::cout << countVolume(&field) << std::endl;
}

void digBorder(std::vector<std::string> *input, std::vector<std::string> *field)
{
    int start = SIZE / 2;

    int x = start;
    int y = start;

    for (int i = 0; i < int(input->size()); i++)
    {
        std::string line = input->at(i);
        int num = line.at(2) - '0';
        char dir = line.at(0);
        for (int j = 0; j < num; j++)
        {
            switch (dir)
            {
            case 'U':
                y--;
                break;
            case 'D':
                y++;
                break;
            case 'L':
                x--;
                break;
            case 'R':
                x++;
                break;
            }
            field->at(y).at(x) = '1';
        }
    }
}

void digField(std::vector<std::string> *field)
{

    for (int i = 0; i < SIZE; i++)
    {
        bool infield = false;
        int found = field->at(i).find_last_of('1');
        if (found == std::string::npos)
        {
            continue;
        }
        else
        {
            for (int j = 0; j < found + 1; j++)
            {
                char c = field->at(i).at(j);
                char cBefore;
                char cAfter = field->at(i).at(j + 1);
                if (j > 0)
                {
                    cBefore = field->at(i).at(j - 1);
                }
                else
                {
                    cBefore = '0';
                }

                if (c == '1' && !infield && cAfter == '0')
                {
                    infield = true;
                }
                else if (c == '1' && infield && cAfter == '0')
                {
                    infield = false;
                }
                else if (c == '0' && infield)
                {
                    field->at(i).at(j) = '1';
                }
                // else if( c == '.' && infield && cBefore == '#')
                // {
                //     field->at(i).at(j) = 'X';
                //     infield = true;
                // }
            }
        }
    }
}

int countVolume(std::vector<std::string> *field)
{
    int volume = 0;

    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {
            if(field->at(i).at(j) == '1')
            {
                volume++;
            }
        }
    }

    return volume;
}
