#include <iostream>

int calculateDistance(int time, int distance);


int main()
{
    int time[4] = {61, 70, 90, 66};
    int distance[4] = {643, 1184, 1362, 1041};
    

    int broken = 1;
    for(int i = 0; i < 4; i++)
    {
        broken *= calculateDistance(time[i], distance[i]);
    }
    std::cout << "Broken: " << broken << std::endl;
}

int calculateDistance(int time, int distance)
{
    int broken = 0;

    for(int i = 0; i <= time; i++)
    {
        int traveled = 0;
        traveled = i * (time - i);
        if(traveled > distance)
        {
            broken++;
        }
    }

    return broken;
}
