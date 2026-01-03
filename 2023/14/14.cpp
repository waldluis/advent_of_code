#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void tiltNorth(std::vector<std::string> *field);
int getLoad(std::vector<std::string> *field);


int main()
{
    std::ifstream is("input.txt");
    std::string line;
    std::vector<std::string> field;
    while (std::getline(is, line))
    {
        field.push_back(line);
    }

    tiltNorth(&field);

    std::cout << getLoad(&field) << std::endl;

    return 0;
}

/// @brief Tilts the field to the north by moving all 'O' up if the fields above are empty
/// @param field 
void tiltNorth(std::vector<std::string> *field)
{
    for (int i = 0; i < int(field->at(0).size()); i++)      // iterate through colums
    {
        for (int j = 0; j < int(field->size()); j++)  // iterate through rows
        {
            if (j != 0)
            {
                if (field->at(j).at(i) == 'O' && field->at(j - 1).at(i) == '.')
                {
                    field->at(j).at(i) = '.';
                    field->at(j - 1).at(i) = 'O';
                    j = 0;
                }
            }
        }
    }
}

/// @brief Calculates the load on the north side of the field by counting the number of 'O' in the field
/// @param field 
/// @return Number of load on the north side
int getLoad(std::vector<std::string> *field)
{
    int load = 0;
    int maxLoad = int(field->size());

    for(int i = 0; i < int(field->size()); i++)
    {
        for(int j = 0; j < int(field->at(i).size()); j++)
        {
            if(field->at(i).at(j) == 'O')
            {
                load = load + (maxLoad - i);
            }
        }
    } 

    return load;
}
