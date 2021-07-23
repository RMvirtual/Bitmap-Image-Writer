#include "vector.h"
#include <iostream>
#include <cmath>
#include <string>

using namespace Vectorable;

Vector::Vector(double x, double y)
{
    double *array = new double[2];
    array[0] = x;
    array[1] = y;

    this->vectorArray = array;
}

int Vector::length()
{
    return 5;
}

double Vector::get(int index)
{
    return this->vectorArray[index]; 
}

double Vector::magnitude()
{
    double xSquared = pow(this->vectorArray[0], 2);
    double ySquared = pow(this->vectorArray[1], 2);

    return sqrt(xSquared + ySquared);
}