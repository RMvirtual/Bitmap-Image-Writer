#include <algorithm>
#include <cmath>
#include <cstdarg>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

#include "vector.h"

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

Maths::Vector::Vector(double array[], int arrayLength)
{
  this->values = {array, array + arrayLength};
}

double Maths::Vector::dotProduct(Maths::Vector vector)
{
  std::vector<double> multiples = this->multiplyElements(vector);
  
  return std::accumulate(multiples.begin(), multiples.end(), 0.0);
}

Maths::Vector Maths::Vector::vectorProduct(Maths::Vector vector)
{
  return Maths::Vector(this->calculateCrossProductValues(vector));
}

std::vector<double> Maths::Vector::calculateCrossProductValues(
  Maths::Vector vector)
{
  Maths::Vector self = *this;
  const int x = 0, y = 1, z = 2;

  double crossX = (self[y] * vector[z]) - (self[z] * vector[y]);
  double crossY = (self[z] * vector[x]) - (self[x] * vector[z]);
  double crossZ = (self[x] * vector[y]) - (self[y] * vector[x]);

  return std::vector<double> {crossX, crossY, crossZ};
}

double Maths::Vector::angle(Maths::Vector vector)
{
  return acos(
    this->dotProduct(vector) / (this->magnitude() * vector.magnitude()));
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
  return sum += pow(number, 2);
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
  Addition *addition = new Addition();

  Vector newVector = this->performBinaryOperation(
    rhsVector, addition);

  delete addition;

  return newVector;
}

Maths::Vector Maths::Vector::operator-(Maths::Vector rhsVector)
{
  Subtraction *subtractionOp = new Subtraction();

  Vector newVector = this->performBinaryOperation(
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
    double multipliedResult = this->values[elementNo] * vector[elementNo];
    newElements.push_back(multipliedResult);
  }

  return newElements;
}

Maths::Vector Maths::Vector::operator*(double scalar)
{
  Maths::Multiplication *multiplication = new Maths::Multiplication();

  Maths::Vector newVector = this->performBinaryOperation(
    scalar, multiplication);

  delete multiplication;

  return newVector;
}

Maths::Vector Maths::Vector::operator/(double scalar)
{
  Maths::Division *division = new Maths::Division();
  Maths::Vector newVector = this->performBinaryOperation(scalar, division);

  delete division;

  return newVector;
}

Maths::Vector operator*(double scalarLHS, Maths::Vector vectorRHS)
{
  Maths::Vector newVector = vectorRHS * scalarLHS;

  return newVector;
}

std::ostream &operator<<(std::ostream& outstream, Maths::Vector vector)
{
  return outstream << vector.toString();
}

std::string Maths::Vector::toString()
{
  return "[" + this->getAllPointsAsString() + "]";
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
  std::string pointsString = "";
  int noOfPoints = this->length();

  for (int pointNo = 0; pointNo < noOfPoints; pointNo++) {
    pointsString += this->getPointAsString(pointNo);
    bool morePointsRemaining = (pointNo < noOfPoints - 1);

    if (morePointsRemaining)
      pointsString += ", ";
  }

  return pointsString;
}

std::string Maths::Vector::getPointAsString(int pointIndex)
{
  std::string pointIndexString = std::to_string(pointIndex);
  std::string pointValue = std::to_string(this->get(pointIndex));

  return pointIndexString + ": " + pointValue;
}

Maths::Vector Maths::Vector::performBinaryOperation(
  Maths::Vector rhsVector, Maths::BinaryOperation* operation)
{
  std::vector<double> newElements = {};
  int numOfElements = this->length();

  for (int elementNo = 0; elementNo < numOfElements; elementNo++)
    newElements.push_back(
      operation->perform(this->values[elementNo], rhsVector[elementNo]));

  return Maths::Vector(newElements);
}

Maths::Vector Maths::Vector::performBinaryOperation(
  double scalar, Maths::BinaryOperation* operation)
{
  std::vector<double> newElements = {};
  int numOfElements = this->length();

  for (auto element : this->values)
    newElements.push_back(operation->perform(element, scalar));

  return Maths::Vector(newElements);
}