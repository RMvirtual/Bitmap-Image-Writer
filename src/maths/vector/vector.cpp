#include "vector.h"
#include <vector>
#include <iostream>
#include <cmath>
#include <string>
#include <cstdarg>

using namespace Maths;
using namespace std;

Vector::Vector(double a, double b)
{
  this->values = {a, b};
}

Vector::Vector(double a, double b, double c)
{
  this->values = {a, b, c};
}

Vector::Vector(double a, double b, double c, double d)
{
  this->values = {a, b, c, d};
}

Vector::Vector(double numberOfValues...)
{
  getNumberOfParameters(1, 2, 3, 4, 5, 6);
  std::va_list args;
  va_start(args, numberOfValues);

  for (int i = 0; i < numberOfValues; ++i) {
    double value = va_arg(args, double);
    cout << "Got arg" + to_string(i) + ": " + to_string(value) << endl;
  }

  va_end(args);

  this->values = {numberOfValues};
}

Vector::Vector(std::vector<double> myVector)
{
  this->values = myVector;
}

Vector::Vector(double array[], int noOfArrayElements)
{
  this->createVectorFromArray(array, noOfArrayElements);
}

void Vector::createVectorFromArray(double *array, int length)
{
  std::vector<double> vectorFromArray = this->createStlVectorFromArray(
      array, length);

  this->values = vectorFromArray;
}

std::vector<double> Vector::createStlVectorFromArray(
    double *array, int length)
{
  std::vector<double> newVector = {};

  for (int i = 0; i < length; i++)
    newVector.push_back(array[i]);

  return newVector;
}

double Vector::dotProduct(Vector vector)
{
  int numOfElements = this->length();
  std::vector<double> newElements = this->multiplyElements(vector);

  double dotProduct = 0;

  for (auto element : newElements)
    dotProduct += element;

  return dotProduct;
}

Vector Vector::vectorProduct(Vector vector)
{
  std::vector<double> coordinates =
      this->calculateCrossProductValues(vector);

  Vector crossProductVector = Vector(coordinates);

  return crossProductVector;
}

std::vector<double> Vector::calculateCrossProductValues(Vector vector)
{
  Vector self = *this;
  int x = 0, y = 1, z = 2;

  double crossX = (self[y] * vector[z]) - (self[z] * vector[y]);
  double crossY = (self[z] * vector[x]) - (self[x] * vector[z]);
  double crossZ = (self[x] * vector[y]) - (self[y] * vector[x]);

  std::vector<double> coordinates = {crossX, crossY, crossZ};

  return coordinates;
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
  return this->values.size();
}

double Vector::magnitude()
{
  double sum = 0;

  for (auto vectorElement : this->values)
    sum = this->squareNumberAndAddToSum(vectorElement, sum);

  return sqrt(sum);
}

double Vector::squareNumberAndAddToSum(double number, double sum)
{
  double numberSquared = pow(number, 2);
  sum += numberSquared;

  return sum;
}

double Vector::get(int index)
{
  return this->values[index];
}

double Vector::operator[](int index)
{
  return this->get(index);
}

Vector Vector::operator+(Vector rhsVector)
{
  Addition *additionOp = new Addition();

  Vector newVector = this->performBinaryOperationWithVector(
      rhsVector, additionOp);

  delete additionOp;

  return newVector;
}

Vector Vector::operator-(Vector rhsVector)
{
  Subtraction *subtractionOp = new Subtraction();

  Vector newVector = this->performBinaryOperationWithVector(
      rhsVector, subtractionOp);

  delete subtractionOp;

  return newVector;
}

double Vector::operator*(Vector rhsVector)
{
  return this->dotProduct(rhsVector);
}

std::vector<double> Vector::multiplyElements(Vector vector)
{
  int numOfElements = this->length();

  std::vector<double> newElements;

  for (int elementNo = 0; elementNo < numOfElements; elementNo++) {
    double lhsElement = this->values[elementNo];
    double rhsElement = vector[elementNo];

    double multipliedResult = lhsElement * rhsElement;
    newElements.push_back(multipliedResult);
  }

  return newElements;
}

Vector Vector::operator*(double scalar)
{
  Multiplication *multiplicationOp = new Multiplication();

  Vector newVector = this->performBinaryOperationWithScalar(
      scalar, multiplicationOp);

  delete multiplicationOp;

  return newVector;
}

Vector Vector::operator/(double scalar)
{
  Division *divisionOp = new Division();

  Vector newVector = this->performBinaryOperationWithScalar(
      scalar, divisionOp);

  delete divisionOp;

  return newVector;
}

Vector operator*(double scalarLHS, Vector vectorRHS)
{
  Vector newVector = vectorRHS * scalarLHS;

  return newVector;
}

ostream &operator<<(ostream &strm, Vector vector)
{
  string string = vector.toString();

  return strm << string;
}

string Vector::toString()
{
  string allPoints = this->getAllPointsAsString();
  string vectorRepresentation = "[" + allPoints + "]";

  return vectorRepresentation;
}

std::vector<double>::iterator Vector::begin()
{
  return this->values.begin();
}

std::vector<double>::iterator Vector::end()
{
  return this->values.end();
}

std::vector<double>::const_iterator Vector::begin() const
{
  return this->values.begin();
}

std::vector<double>::const_iterator Vector::end() const
{
  return this->values.end();
}

string Vector::getAllPointsAsString()
{
  string pointsRepresentation = "";
  int noOfPoints = this->length();

  for (int pointNo = 0; pointNo < noOfPoints; pointNo++) {
    string point = this->getPointAsString(pointNo);
    pointsRepresentation += point;

    bool morePointsToAdd = (pointNo < noOfPoints - 1);

    if (morePointsToAdd)
      pointsRepresentation += ", ";
  }

  return pointsRepresentation;
}

string Vector::getPointAsString(int pointIndex)
{
  string pointIndexAsString = to_string(pointIndex);
  string pointValue = to_string(this->get(pointIndex));

  string pointRepresentation = pointIndexAsString + ": " + pointValue;

  return pointRepresentation;
}

Vector Vector::performBinaryOperationWithVector(
    Vector rhsVector, BinaryOperation *operation)
{
  int numOfElements = this->length();
  std::vector<double> newElements = {};

  for (int elementNo = 0; elementNo < numOfElements; elementNo++) {
    double lhsElement = this->values[elementNo];
    double rhsElement = rhsVector[elementNo];

    double newElement = operation->perform(lhsElement, rhsElement);
    newElements.push_back(newElement);
  }

  Vector newVector = Vector(newElements);

  return newVector;
}

Vector Vector::performBinaryOperationWithScalar(
    double scalar, BinaryOperation *operation)
{
  int numOfElements = this->length();
  std::vector<double> newElements = {};

  for (auto element : this->values) {
    double newElement = operation->perform(element, scalar);
    newElements.push_back(newElement);
  }

  Vector newVector = Vector(newElements);

  return newVector;
}