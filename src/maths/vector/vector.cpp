#include "vector.h"
#include <iostream>
#include <cmath>
#include <string>
#include "../../common/arrays.h"

using namespace Vectorable;
using namespace std;

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

double Vector::dotProduct(Vector vector)
{
  int numOfElements = this->length();
  ArrayList<double> newElements = this->multiplyElements(vector);

  double dotProduct = 0;

  for (int elementNo = 0; elementNo < newElements.size(); elementNo++)
    dotProduct += newElements.get(elementNo);

  return dotProduct;
}

Vector Vector::vectorProduct(Vector vector)
{
  // Prep for the clever way to calculate the cross product.
  double angleBetweenVectors = this->angle(vector);
  double magnitudeOf1stVector = this->magnitude();
  double magnitudeOf2ndVector = vector.magnitude();
  double thing = sin(angleBetweenVectors);
  double unitVector = 1;

  // Simpler way to calculate cross product.
  Vector self = *this;
  
  double crossX = (self[1] * vector[2]) - (self[2] * vector[1]);
  double crossY = (self[2] * vector[0]) - (self[0] * vector[2]);
  double crossZ = (self[0] * vector[1]) - (self[1] * vector[0]);

  Vector crossProductVector = Vector(crossX, crossY, crossZ);

  return crossProductVector;
}

double Vector::angle(Vector vector)
{
  double dotProduct = this->dotProduct(vector);
  double magnitudeOf1stVector = this->magnitude();
  double magnitudeOf2ndVector = vector.magnitude();

  double angle = acos(
    dotProduct / (magnitudeOf1stVector * magnitudeOf2ndVector));

  return angle;
}

int Vector::length()
{
  return this->lengthOfVector;
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

double Vector::get(int index)
{
  return this->vectorArray[index];
}

double Vector::operator [] (int index)
{
  return this->vectorArray[index];
}

Vector Vector::operator + (Vector rhsVector)
{
  Addition *additionOp = new Addition();
  Vector newVector = this->performBinaryOperationWithVector(
    rhsVector, additionOp);

  delete additionOp;

  return newVector;
}

Vector Vector::operator - (Vector rhsVector)
{
  Subtraction *subtractionOp = new Subtraction();
  Vector newVector = this->performBinaryOperationWithVector(
    rhsVector, subtractionOp);

  delete subtractionOp;

  return newVector;
}

double Vector::operator * (Vector rhsVector)
{
  return this->dotProduct(rhsVector);
}

ArrayList<double> Vector::multiplyElements(Vector vector)
{
  int numOfElements = this->length();

  ArrayList<double> newElements;

  for (int elementNo = 0; elementNo < numOfElements; elementNo++) {
      double lhsElement = this->vectorArray[elementNo];
      double rhsElement = vector[elementNo];

      double newElement = lhsElement * rhsElement;
      newElements.add(newElement);
  }

  return newElements;
}

Vector Vector::operator * (double scalar)
{
  Multiplication *multiplicationOp = new Multiplication();

  Vector newVector = this->performBinaryOperationWithScalar(
      scalar, multiplicationOp);

  delete multiplicationOp;

  return newVector;
}

Vector Vector::operator / (double scalar)
{
  Division *divisionOp = new Division();

  Vector newVector = this->performBinaryOperationWithScalar(
    scalar, divisionOp);

  delete divisionOp;

  return newVector;
}

Vector operator * (double scalarLHS, Vector vectorRHS)
{
  Vector newVector = vectorRHS * scalarLHS;

  return newVector;
}

ostream& operator << (ostream &strm, Vector vector)
{
  string string = vector.toString();

  return strm << string;
}

string Vector::toString()
{
  Vector vector = *this;
  string vectorRepresentation = "[";
  int noOfPoints = this->length();

  for (int pointNo = 0; pointNo < noOfPoints; pointNo++) {
    string pointToAdd = (
      to_string(pointNo) + ": " + to_string(vector[pointNo]));

    bool morePointsToAdd = (pointNo < noOfPoints);

    if (morePointsToAdd)
      pointToAdd += ", ";

    vectorRepresentation += pointToAdd;
  }

  vectorRepresentation += "]";

  return vectorRepresentation;
}

Vector Vector::performBinaryOperationWithVector(
    Vector rhsVector, BinaryOperation *operation)
{
  int numOfElements = this->length();
  double* newElements = new double[numOfElements];

  for (int elementNo = 0; elementNo < numOfElements; elementNo++) {
    double lhsElement = this->vectorArray[elementNo];
    double rhsElement = rhsVector[elementNo];

    double newElement = operation->perform(lhsElement, rhsElement);
    newElements[elementNo] = newElement;
  }

  Vector newVector = Vector(newElements, numOfElements);

  return newVector;
}

Vector Vector::performBinaryOperationWithScalar(
    double scalar, BinaryOperation *operation)
{
  int numOfElements = this->length();
  double* newElements = new double[numOfElements];

  for (int elementNo = 0; elementNo < numOfElements; elementNo++) {
    double element = this->vectorArray[elementNo];

    double newElement = operation->perform(element, scalar);
    newElements[elementNo] = newElement;
  }

  Vector newVector = Vector(newElements, numOfElements);

  return newVector;
}
