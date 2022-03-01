#include <algorithm>
#include <cmath>
#include <cstdarg>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
#include <functional>

#include "src/main/cpp/maths/vector/vector.h"

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
  Maths::Vector self = *this;
  const int x = 0, y = 1, z = 2;

  double crossX = (self[y] * vector[z]) - (self[z] * vector[y]);
  double crossY = (self[z] * vector[x]) - (self[x] * vector[z]);
  double crossZ = (self[x] * vector[y]) - (self[y] * vector[x]);

  return {crossX, crossY, crossZ};
}

double Maths::Vector::angle(const Maths::Vector& vector) const
{
  auto magnitudeProduct = this->magnitude() * vector.magnitude();

  return acos(this->dotProduct(vector) / magnitudeProduct);
}

int Maths::Vector::length() const
{
  return this->values.size();
}

double Maths::Vector::magnitude() const
{
  auto sumSquareNumbers = [](double sumAccumulator, double value) {
    return sumAccumulator + pow(value, 2.0);
  };

  auto sum = std::accumulate(
    this->values.begin(), this->values.end(), 0.0, sumSquareNumbers);
  
  return sqrt(sum);
}

double Maths::Vector::at(int index) const
{
  return this->values[index];
}

std::vector<double> Maths::Vector::multiplyElements(
  const Maths::Vector& vector) const
{
  auto multiplyFunction = std::multiplies<double>();
  std::vector<double> newElements (this->length());

  std::transform(
    this->begin(), this->end(), vector.begin(),
    newElements.begin(), multiplyFunction
  );

  return newElements;
}

double Maths::Vector::operator [](int index) const
{
  return this->at(index);
}

Maths::Vector Maths::Vector::operator +(const Maths::Vector& rhsVector) const
{
  std::vector<double> newElements (this->length());

  std::transform(
    this->begin(), this->end(), rhsVector.begin(), newElements.begin(), std::plus<double>()
  );

  return {newElements};

  /* vector op.
  int numOfElements = this->length();
  BinaryOperation operation {};
  std::vector<double> newElements {};

  for (int elementNo = 0; elementNo < numOfElements; elementNo++) {
    auto result = operation.perform(
      this->values[elementNo], vector[elementNo]);
    
    newElements.push_back(result);
  }
  return Maths::Vector(newElements);
  */
}

Maths::Vector Maths::Vector::operator -(const Maths::Vector& rhsVector) const
{
  auto multiplyFunction = std::minus<double>();
  std::vector<double> newElements (this->length());

  std::transform(
    this->begin(), this->end(), rhsVector.begin(), newElements.begin(), multiplyFunction
  );

  return {newElements};
}

double Maths::Vector::operator *(const Maths::Vector& rhsVector) const
{
  return this->dotProduct(rhsVector);
}

Maths::Vector Maths::Vector::operator *(double scalar) const
{
  auto multiplyOperation = [scalar](double value) {
    return scalar * value;
  };

  // scalar op.
  std::vector<double> newElements(this->length());

  std::transform(
    this->begin(), this->end(), newElements.begin(), multiplyOperation);

  return {newElements};
}

Maths::Vector Maths::Vector::operator /(double scalar) const
{
  auto multiplyOperation = [scalar](double value) {
    return value / scalar;
  };

  // scalar op.
  std::vector<double> newElements(this->length());

  std::transform(
    this->begin(), this->end(), newElements.begin(), multiplyOperation);

  return {newElements};
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
  return "[" + this->allPointsToString() + "]";
}

std::string Maths::Vector::allPointsToString() const
{
  std::string pointsString = "";
  int noOfPoints = this->length();

  for (int pointNo = 0; pointNo < noOfPoints; pointNo++) {
    pointsString += this->pointToString(pointNo);
    bool morePointsRemaining = (pointNo < noOfPoints - 1);

    if (morePointsRemaining)
      pointsString += ", ";
  }

  return pointsString;
}

std::string Maths::Vector::pointToString(int pointIndex) const
{
  auto pointIndexString = std::to_string(pointIndex);
  auto pointValue = std::to_string(this->at(pointIndex));

  return pointIndexString + ": " + pointValue;
}

Maths::Vector operator *(double scalar, const Maths::Vector& vector)
{
  return vector * scalar;
}

std::ostream& operator <<(std::ostream& outstream, const Maths::Vector& vector)
{
  return outstream << vector.toString();
}
