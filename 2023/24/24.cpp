#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

#define MINAREA 7
#define MAXAREA 27
#define STEPS 100

struct Point
{
    double x;
    double y;
    double z;
};

int checkCollision(const std::vector<Point> &positions, const std::vector<Point> &velocities);

int main()
{
    std::ifstream file("test.txt");
    std::vector<Point> positions;
    std::vector<Point> velocities;
    std::string line;
    while (std::getline(file, line))
    {
        Point position;
        Point velocity;

        std::istringstream iss(line);
        std::string positionStr, velocityStr;
        std::getline(iss, positionStr, '@');
        std::getline(iss, velocityStr);
        char separator;

        std::istringstream positionIss(positionStr);
        std::istringstream velocityIss(velocityStr);

        positionIss >> position.x >> separator >> position.y >> separator >> position.z;
        velocityIss >> velocity.x >> separator >> velocity.y >> separator >> velocity.z;

        positions.push_back(position);
        velocities.push_back(velocity);
    }

    std::cout << checkCollision(positions, velocities) << std::endl;

    // std::cout << velocities[3].x << " " << velocities[3].y << " " << velocities[3].z << std::endl;

    return 0;
}

int checkCollision(const std::vector<Point> &positions, const std::vector<Point> &velocities)
{
    // Calculate path of each particle
    int collisions = 0;
    std::vector<std::vector<Point>> paths;
    for (size_t i = 0; i < positions.size(); i++)
    {
        std::vector<Point> path;
        Point currentPosition = positions[i];
        Point currentVelocity = velocities[i];

        // Add initial position to the path
        path.push_back(currentPosition);

        // Calculate the path by updating the position based on velocity
        for (int step = 0; step < STEPS; step++)
        {
            currentPosition.x += currentVelocity.x;
            currentPosition.y += currentVelocity.y;
            currentPosition.z += currentVelocity.z;
            path.push_back(currentPosition);
        }

        paths.push_back(path);
    }

    // Check if any two paths intersect
    for (size_t i = 0; i < paths.size(); i++)
    {
        for (size_t j = i + 1; j < paths.size(); j++)
        {
            for (size_t k = 0; k < paths[i].size(); k++)
            {
                for (size_t l = 0; l < paths[j].size(); l++)
                {
                    if (paths[i][k].x == paths[j][l].x && paths[i][k].y == paths[j][l].y && paths[i][k].z == paths[j][l].z)
                    {
                        collisions++;
                    }
                }
            }
        }
    }

    return collisions;
}
