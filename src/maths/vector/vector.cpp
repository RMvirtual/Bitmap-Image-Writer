#include "vector.h"
#include <iostream>
#include <cmath>

using namespace Vectorable;
using namespace std;

Vector::Vector(double x, double y)
{
    this->x = x;
    this->y = y;
}

int Vector::length()
{
    return 5;
}

double Vector::magnitude()
{
    double xSquared = pow(this->x, 2);
    double ySquared = pow(this->y, 2);

    return sqrt(xSquared + ySquared);
}