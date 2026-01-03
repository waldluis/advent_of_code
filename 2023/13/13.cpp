#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cmath>

// Function to find symmetric line horizontally
// Erste Zeile mit allen anderen vergleichen, wenn gleich line = (nRow - 0)/2 + 1 -> Achse nach 4
int findSymmetricHorizontal(std::vector<std::string> *matrix);

// Function to find symmetric line vertically
int findSymmetricVertical(std::vector<std::string> *matrix);

// Function to transpose the matrix
void transpose(std::vector<std::string> *matrix);

int main()
{
    int sum = 0;
    std::vector<std::vector<std::string>> matrix;
    std::ifstream is("test.txt");
    std::string line;
    std::vector<std::string> block;
    while (std::getline(is, line))
    {
        if (line.empty())
        {
            matrix.push_back(block);
            block.clear();
        }
        else
        {
            block.push_back(line);
        }
    }
    matrix.push_back(block);
    int i = 0;
    i++;
    std::cout << i << std::endl;

    transpose(&matrix.at(0));
    sum += findSymmetricHorizontal(&matrix.at(0));

    std::cout << sum << std::endl;

    return 0;
}

int findSymmetricHorizontal(std::vector<std::string> *matrix)
{
    int nRow = 0;
    int nRow2 = matrix->size();

    for (int i = nRow2 - 1; i >= 0; i--)
    {
        for (int j = 0; j < nRow2; j++)
        {
            if (matrix->at(i) == matrix->at(j) && i != j)
            {
                int rowSym = (std::ceil((nRow2  - (j)) / 2));

                for(int k = 0; k < rowSym; k++){
                    if(matrix->at(k) == matrix->at(nRow2 - k - 1)){
                        rowSym = 0;
                        break;
                    }
                }
            }
        }
    }
    return 100 * nRow;
}

int findSymmetricVertical(std::vector<std::string> *matrix)
{
    int nRow = matrix->size();
    transpose(matrix);
    nRow = findSymmetricHorizontal(matrix);
    return nRow / 100;
}

void transpose(std::vector<std::string> *matrix)
{
    int nRow = matrix->size();
    int nCol = matrix->at(0).size();

    std::vector<std::string> transposedMatrix;

    for (int i = 0; i < nCol; i++)
    {
        std::string col;
        for (int j = 0; j < nRow; j++)
        {
            col += matrix->at(j).at(i);
        }
        transposedMatrix.push_back(col);
    }
    matrix->clear();
    for (int i = 0; i < nCol; i++)
    {

        matrix->push_back(transposedMatrix.at(i));
    }
}
