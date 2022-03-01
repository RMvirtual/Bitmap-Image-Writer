#include <algorithm>
#include <cmath>
#include <cstdarg>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

#include "src/main/cpp/maths/vector/vector.h"
#include "src/main/cpp/maths/binary-ops/binary_ops.h"

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

Maths::Vector::Vector(const std::vector<double>& values)
{
  this->values = values;
}

Maths::Vector::Vector(double array[], int arrayLength)
{
  this->values = {array, array + arrayLength};
}

double Maths::Vector::dotProduct(const Maths::Vector& vector) const
{
  auto multiples = this->multiplyElements(vector);
  
  return std::accumulate(multiples.begin(), multiples.end(), 0.0);
}

Maths::Vector Maths::Vector::vectorProduct(const Maths::Vector& vector)
{
  return {this->crossProductValues(vector)};
}

std::vector<double> Maths::Vector::crossProductValues(
  const Maths::Vector& vector) const
{
  Maths::Vector self = *this;
  const int x = 0, y = 1, z = 2;

  double crossX = (self[y] * vector[z]) - (self[z] * vector[y]);
  double crossY = (self[z] * vector[x]) - (self[x] * vector[z]);
  double crossZ = (self[x] * vector[y]) - (self[y] * vector[x]);

  return {crossX, crossY, crossZ};
}

double Maths::Vector::angle(const Maths::Vector& vector) const
{
  return acos(
    this->dotProduct(vector) / (this->magnitude() * vector.magnitude()));
}

int Maths::Vector::length() const
{
  return this->values.size();
}

double Maths::Vector::magnitude() const
{
  double sum = 0;

  for (auto value : this->values)
    sum += pow(value, 2);

  return sqrt(sum);
}

double Maths::Vector::get(int index) const
{
  return this->values[index];
}

std::vector<double> Maths::Vector::multiplyElements(
  const Maths::Vector& vector) const
{
  std::vector<double> newElements;
  int numOfElements = this->length();
  
  for (int elementNo = 0; elementNo < numOfElements; elementNo++)
    newElements.push_back(this->values[elementNo] * vector[elementNo]);

  return newElements;
}

std::string Maths::Vector::getAllPointsAsString() const
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

std::string Maths::Vector::getPointAsString(int pointIndex) const
{
  auto pointIndexString = std::to_string(pointIndex);
  auto pointValue = std::to_string(this->get(pointIndex));

  return pointIndexString + ": " + pointValue;
}

template<class BinaryOperation>
Maths::Vector Maths::Vector::performBinaryOperation(
  const Maths::Vector& vector) const
{
  
  int numOfElements = this->length();
  BinaryOperation operation {};
  std::vector<double> newElements {};

  for (int elementNo = 0; elementNo < numOfElements; elementNo++) {
    auto result = operation.perform(
      this->values[elementNo], vector[elementNo]);
    
    newElements.push_back(result);
  }
  return Maths::Vector(newElements);
}

template<class BinaryOperation>
Maths::Vector Maths::Vector::performBinaryOperation(double scalar) const
{
  std::vector<double> newElements {};
  int numOfElements = this->length();
  BinaryOperation operation {};

  for (auto element : this->values)
    newElements.push_back(operation.perform(element, scalar));

  return Maths::Vector(newElements);
}

double Maths::Vector::operator [](int index) const
{
  return this->get(index);
}

Maths::Vector Maths::Vector::operator +(const Maths::Vector& rhsVector) const
{
  return this->performBinaryOperation<Addition>(rhsVector);
}

Maths::Vector Maths::Vector::operator -(const Maths::Vector& rhsVector) const
{
  return this->performBinaryOperation<Subtraction>(rhsVector);
}

double Maths::Vector::operator *(const Maths::Vector& rhsVector) const
{
  return this->dotProduct(rhsVector);
}

Maths::Vector Maths::Vector::operator *(double scalar) const
{
  return this->performBinaryOperation<Multiplication>(scalar);
}

Maths::Vector Maths::Vector::operator /(double scalar) const
{
  return this->performBinaryOperation<Division>(scalar);
}

Maths::Vector operator *(double scalarLHS, const Maths::Vector& vectorRHS)
{
  return vectorRHS * scalarLHS;
}

std::ostream& operator <<(std::ostream& outstream, const Maths::Vector& vector)
{
  return outstream << vector.toString();
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

std::string Maths::Vector::toString() const
{
  return "[" + this->getAllPointsAsString() + "]";
}