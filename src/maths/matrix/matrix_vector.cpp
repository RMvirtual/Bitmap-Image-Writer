#include <iostream>
#include <string>
#include <vector>
#include "matrix_vector.h"

using namespace Maths;
using namespace std;

MatrixVector::MatrixVector()
{
  // Empty constructor to allow an array of this class to be created.
}

MatrixVector::MatrixVector(std::vector<double> values)
{
  this->values = values;
}

MatrixVector::MatrixVector(double *values, int length)
{

}

double MatrixVector::operator [] (int index)
{
  int indexRange = this->length() - 1;
  bool outOfRange = (index < 0 || index > indexRange);

  if (outOfRange)
    throw out_of_range("Row index is out of range.");

  return this->values[index];
}

int MatrixVector::length()
{
  return this->values.size();
}