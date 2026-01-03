#include <iostream>

int calculateDistance(double time, double distance);


int main()
{  
    // int broken = calculateDistance(71530, 940200);
    int broken = calculateDistance(61709066, 643118413621041);
    int records = 61709066 - 2*broken +1;
    std::cout << "Records: " << records << std::endl;
}

int calculateDistance(double time, double distance)
{
    for(int i = 0; i <= time; i++)
    {
        double traveled = 0;
        traveled = i * (time - i);
        if(traveled > distance)
        {
            return i;
        }
    }
    return 0;
}
