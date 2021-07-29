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
        double element = this->vectorArray[elementNo];
        double elementSquared = pow(element, 2);
        sum += elementSquared;
    }

    return sqrt(sum);
}

double Vector::operator[](int index)
{
    return this->vectorArray[index];
}

Vector Vector::operator+(Vector rhsVector)
{
    int numOfElements = this->length();
    double* newElements = new double[numOfElements];

    for (int elementNo = 0; elementNo < numOfElements; elementNo++) {
        double lhsElement = this->vectorArray[elementNo];
        double rhsElement = rhsVector[elementNo];

        double newElement = lhsElement + rhsElement;
        newElements[elementNo] = newElement;
    }

    Vector newVector = Vector(newElements, numOfElements);

    return newVector;
}

Vector Vector::operator-(Vector rhsVector)
{
    int numOfElements = this->length();
    double* newElements = new double[numOfElements];

    for (int elementNo = 0; elementNo < numOfElements; elementNo++) {
        double lhsElement = this->vectorArray[elementNo];
        double rhsElement = rhsVector[elementNo];

        double newElement = lhsElement - rhsElement;
        newElements[elementNo] = newElement;
    }

    Vector newVector = Vector(newElements, numOfElements);

    return newVector;
}

double Vector::operator*(Vector rhsVector)
{
    int numOfElements = this->length();
    double* newElements = new double[numOfElements];

    for (int elementNo = 0; elementNo < numOfElements; elementNo++) {
        double lhsElement = this->vectorArray[elementNo];
        double rhsElement = rhsVector[elementNo];

        double newElement = lhsElement * rhsElement;
        newElements[elementNo] = newElement;
    }

    double dotProduct = 0;

    for (int elementNo = 0; elementNo < numOfElements; elementNo++)
        dotProduct += newElements[elementNo];
    
    return dotProduct;
}

Vector Vector::operator/(double scalar)
{
    int numOfElements = this->length();
    double* newElements = new double[numOfElements];

    for (int elementNo = 0; elementNo < numOfElements; elementNo++) {
        double element = this->vectorArray[elementNo];
        double newElement = element / scalar;
        newElements[elementNo] = newElement;
    }

    Vector newVector = Vector(newElements, numOfElements);

    return newVector;
}

Vector Vector::operator*(double scalarRHS)
{
    int numOfElements = this->length();
    double* newElements = new double[numOfElements];

    for (int elementNo = 0; elementNo < numOfElements; elementNo++) {
        double element = this->vectorArray[elementNo];
        double newElement = scalarRHS * element;
        newElements[elementNo] = newElement;
    }

    Vector newVector = Vector(newElements, numOfElements);

    return newVector;
}

Vector operator*(const double scalarLHS, const Vector& vectorRHS)
{
    Vector newVector = (Vector) vectorRHS * scalarLHS;

    return newVector;
}

char operator+(double lhs, Vector rhs)
{
    if (lhs == 1)
        std::cout << "found a global operator.";

    return 'a';
}