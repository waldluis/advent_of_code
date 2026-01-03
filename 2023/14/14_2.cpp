#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// input.txt repeats seven outcomes after 100 spins

void tiltNorth(std::vector<std::string> *field);
void tiltWest(std::vector<std::string> *field);
void tiltSouth(std::vector<std::string> *field);
void tiltEast(std::vector<std::string> *field);
void spinCircle(std::vector<std::string> *field, int n);
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

    // take forever
    // spinCircle(&field, 1000000000);
    spinCircle(&field, 1000);

    std::cout << getLoad(&field) << std::endl;

    return 0;
}

/// @brief Tilts the field to the north by moving all 'O' up if the fields above are empty
/// @param field 
void tiltNorth(std::vector<std::string> *field)
{
    for (int i = 0; i < int(field->at(0).size()); i++) // iterate through colums
    {
        for (int j = 0; j < int(field->size()); j++) // iterate through rows
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

    for (int i = 0; i < int(field->size()); i++)
    {
        for (int j = 0; j < int(field->at(i).size()); j++)
        {
            if (field->at(i).at(j) == 'O')
            {
                load = load + (maxLoad - i);
            }
        }
    }

    return load;
}

/// @brief Tilts the field to the west by moving all 'O' left if the fields left are empty
/// @param field 
void tiltWest(std::vector<std::string> *field)
{
    for (int i = 0; i < int(field->size()); i++) // iterate through rows
    {
        for (int j = 0; j < int(field->at(0).size()); j++) // iterate through colums
        {
            if (j != 0)
            {
                if (field->at(i).at(j) == 'O' && field->at(i).at(j - 1) == '.')
                {
                    field->at(i).at(j) = '.';
                    field->at(i).at(j - 1) = 'O';
                    j = 0;
                }
            }
        }
    }
}

/// @brief Tilts the field to the south by moving all 'O' down if the fields below are empty
/// @param field 
void tiltSouth(std::vector<std::string> *field)
{
    for (int i = 0; i < int(field->at(0).size()); i++) // iterate through colums
    {
        for (int j = int(field->size()) - 1; j > -1; j--) // iterate through rows
        {
            if (j != int(field->size()) - 1)
            {
                if (field->at(j).at(i) == 'O' && field->at(j + 1).at(i) == '.')
                {
                    field->at(j).at(i) = '.';
                    field->at(j + 1).at(i) = 'O';
                    j = int(field->size() - 1);
                }
            }
        }
    }
}

/// @brief Tilts the field to the east by moving all 'O' right if the fields right are empty
/// @param field 
void tiltEast(std::vector<std::string> *field)
{
    for (int i = 0; i < int(field->size()); i++) // iterate through rows
    {
        for (int j = int(field->at(0).size()) - 1; j > -1; j--) // iterate through colums
        {
            if (j != int(field->at(0).size()) - 1)
            {
                if (field->at(i).at(j) == 'O' && field->at(i).at(j + 1) == '.')
                {
                    field->at(i).at(j) = '.';
                    field->at(i).at(j + 1) = 'O';
                    j = int(field->at(0).size()) - 1;
                }
            }
        }
    }
}


/// @brief Spins the field for n times in north, west, south, east order
/// @param field 
/// @param n Number of spins
void spinCircle(std::vector<std::string> *field, int n)
{
    for (int i = 0; i < n; i++)
    {
        std::vector<std::string> tempField = *field;
        tiltNorth(field);
        tiltWest(field);
        tiltSouth(field);
        tiltEast(field);

        if (tempField == *field)
        {
            break;
        }
        std::cout << "N: " << i << " Load: " << getLoad(field) << std::endl;
    }
}
