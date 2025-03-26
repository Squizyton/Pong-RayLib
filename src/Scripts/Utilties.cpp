#include "Utilties.h"
#include <ctime>
#include <iostream>


Color* Utilties::GenerateRandomColor()
{
    return new Color{
        static_cast<unsigned char>(GetRandomValue(0, 255)),
        static_cast<unsigned char>(GetRandomValue(0, 255)),
        static_cast<unsigned char>(GetRandomValue(0, 255)),
        255
    };
}

float randomFloat()
{
    return (float)(rand()) / (float)(RAND_MAX);
}


int randomInt(int a, int b)
{
    if (a > b)
        return randomInt(b, a);
    if (a == b)
        return a;
    return a + (rand() % (b - a));
}
 
float Utilties::GetRandomFloat(float min, float max)
{
    if (min > max)
        return GetRandomFloat(max, min);
    if (min == max)
        return min;
 
    return (float)randomInt(min, max) + randomFloat();
}

