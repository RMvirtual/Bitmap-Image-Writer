#include "vector.h"
#include <vector>
#include <iostream>
#include <cmath>
#include <string>
#include <cstdarg>

Maths::Vector::Vector()
{
  this->values = {};
}

Maths::Vector::Vector(double a, double b)
{
  this->values = {a, b};
}

Maths::Vector::Vector(double a, double b, double c)
{
  this->values = {a, b, c};
}

Maths::Vector::Vector(double a, double b, double c, double d)
{
  this->values = {a, b, c, d};
}

Maths::Vector::Vector(std::vector<double> myVector)
{
  this->values = myVector;
}

Maths::Vector::Vector(double array[], int noOfArrayElements)
{
  this->createVectorFromArray(array, noOfArrayElements);
}

void Maths::Vector::createVectorFromArray(double *array, int length)
{
  std::vector<double> vectorFromArray = this->createStlVectorFromArray(
    array, length);

  this->values = vectorFromArray;
}

std::vector<double> Maths::Vector::createStlVectorFromArray(
  double *array, int length)
{
  std::vector<double> newVector = {};

  for (int i = 0; i < length; i++)
    newVector.push_back(array[i]);

  return newVector;
}

double Maths::Vector::dotProduct(Maths::Vector vector)
{
  int numOfElements = this->length();
  std::vector<double> newElements = this->multiplyElements(vector);

  double dotProduct = 0;

  for (auto element : newElements)
    dotProduct += element;

  return dotProduct;
}

Maths::Vector Maths::Vector::vectorProduct(Maths::Vector vector)
{
  std::vector<double> coordinates =
    this->calculateCrossProductValues(vector);

  Maths::Vector crossProductVector = Maths::Vector(coordinates);

  return crossProductVector;
}

std::vector<double> Maths::Vector::calculateCrossProductValues(
  Maths::Vector vector)
{
  Maths::Vector self = *this;
  int x = 0, y = 1, z = 2;

  double crossX = (self[y] * vector[z]) - (self[z] * vector[y]);
  double crossY = (self[z] * vector[x]) - (self[x] * vector[z]);
  double crossZ = (self[x] * vector[y]) - (self[y] * vector[x]);

  std::vector<double> coordinates = {crossX, crossY, crossZ};

  return coordinates;
}

double Maths::Vector::angle(Maths::Vector vector)
{
  double dotProduct = this->dotProduct(vector);
  double magnitudeOf1stVector = this->magnitude();
  double magnitudeOf2ndVector = vector.magnitude();

  double angle = acos(
    dotProduct / (magnitudeOf1stVector * magnitudeOf2ndVector));

  return angle;
}

int Maths::Vector::length()
{
  return this->values.size();
}

double Maths::Vector::magnitude()
{
  double sum = 0;

  for (auto vectorElement : this->values)
    sum = this->squareNumberAndAddToSum(vectorElement, sum);

  return sqrt(sum);
}

double Maths::Vector::squareNumberAndAddToSum(double number, double sum)
{
  double numberSquared = pow(number, 2);
  sum += numberSquared;

  return sum;
}

double Maths::Vector::get(int index)
{
  return this->values[index];
}

double Maths::Vector::operator[](int index)
{
  return this->get(index);
}

Maths::Vector Maths::Vector::operator+(Maths::Vector rhsVector)
{
  Addition *additionOp = new Addition();

  Vector newVector = this->performBinaryOperationWithVector(
      rhsVector, additionOp);

  delete additionOp;

  return newVector;
}

Maths::Vector Maths::Vector::operator-(Maths::Vector rhsVector)
{
  Subtraction *subtractionOp = new Subtraction();

  Vector newVector = this->performBinaryOperationWithVector(
    rhsVector, subtractionOp);

  delete subtractionOp;

  return newVector;
}

double Maths::Vector::operator*(Maths::Vector rhsVector)
{
  return this->dotProduct(rhsVector);
}

std::vector<double> Maths::Vector::multiplyElements(Maths::Vector vector)
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

Maths::Vector Maths::Vector::operator*(double scalar)
{
  Maths::Multiplication *multiplicationOp = new Maths::Multiplication();

  Maths::Vector newVector = this->performBinaryOperationWithScalar(
    scalar, multiplicationOp);

  delete multiplicationOp;

  return newVector;
}

Maths::Vector Maths::Vector::operator/(double scalar)
{
  Maths::Division *divisionOp = new Maths::Division();

  Maths::Vector newVector = this->performBinaryOperationWithScalar(
      scalar, divisionOp);

  delete divisionOp;

  return newVector;
}

Maths::Vector operator*(double scalarLHS, Maths::Vector vectorRHS)
{
  Maths::Vector newVector = vectorRHS * scalarLHS;

  return newVector;
}

std::ostream &operator<<(std::ostream &strm, Maths::Vector vector)
{
  std::string string = vector.toString();

  return strm << string;
}

std::string Maths::Vector::toString()
{
  std::string allPoints = this->getAllPointsAsString();
  std::string vectorRepresentation = "[" + allPoints + "]";

  return vectorRepresentation;
}

std::vector<double>::iterator Maths::Vector::begin()
{
  return this->values.begin();
}

std::vector<double>::iterator Maths::Vector::end()
{
  return this->values.end();
}

std::vector<double>::const_iterator Maths::Vector::begin() const
{
  return this->values.begin();
}

std::vector<double>::const_iterator Maths::Vector::end() const
{
  return this->values.end();
}

std::string Maths::Vector::getAllPointsAsString()
{
  std::string pointsRepresentation = "";
  int noOfPoints = this->length();

  for (int pointNo = 0; pointNo < noOfPoints; pointNo++) {
    std::string point = this->getPointAsString(pointNo);
    pointsRepresentation += point;

    bool morePointsToAdd = (pointNo < noOfPoints - 1);

    if (morePointsToAdd)
      pointsRepresentation += ", ";
  }

  return pointsRepresentation;
}

std::string Maths::Vector::getPointAsString(int pointIndex)
{
  std::string pointIndexAsString = std::to_string(pointIndex);
  std::string pointValue = std::to_string(this->get(pointIndex));

  std::string pointRepresentation = pointIndexAsString + ": " + pointValue;

  return pointRepresentation;
}

Maths::Vector Maths::Vector::performBinaryOperationWithVector(
    Maths::Vector rhsVector, Maths::BinaryOperation *operation)
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

Maths::Vector Maths::Vector::performBinaryOperationWithScalar(
    double scalar, Maths::BinaryOperation *operation)
{
  int numOfElements = this->length();
  std::vector<double> newElements = {};

  for (auto element : this->values) {
    double newElement = operation->perform(element, scalar);
    newElements.push_back(newElement);
  }

  Maths::Vector newVector = Maths::Vector(newElements);

  return newVector;
}