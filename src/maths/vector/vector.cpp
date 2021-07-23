#include "vector.h"
#include <iostream>
#include <cmath>
#include <string>

using namespace Vectorable;

Vector::Vector(double a, double b)
{
    double* array = new double[2];
    array[0] = a;
    array[1] = b;

    this->vectorArray = array;
    this->lengthOfVector = 2;
}

Vector::Vector(double a, double b, double c)
{
    double* array = new double[3];
    array[0] = a;
    array[1] = b;
    array[2] = c;

    // double array[] = {a, b, c};
    this->vectorArray = array;
    this->lengthOfVector = 3;
}

Vector::Vector(double a, double b, double c, double d)
{
    double* array = new double[4];
    array[0] = a;
    array[1] = b;
    array[2] = c;
    array[3] = d;

    this->vectorArray = array;
    this->lengthOfVector = 4;
}

Vector::Vector(double array[], int noOfArrayElements)
{
    this->vectorArray = array;
    this->lengthOfVector = noOfArrayElements;
}

int Vector::length()
{
    return this->lengthOfVector;
}

double Vector::get(int index)
{
    return this->vectorArray[index]; 
}

double Vector::magnitude()
{
    double sum = 0;

    for (int elementNo = 0; elementNo < this->lengthOfVector; elementNo++) {
        double currentElement = this->vectorArray[elementNo];
        double elementSquared = pow(currentElement, 2);
        sum += elementSquared;

        std::cout << "Current element: " + std::to_string(currentElement) + "\n";
    }

    return sqrt(sum);
}