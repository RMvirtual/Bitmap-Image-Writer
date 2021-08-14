#include <iostream>
#include <string>
#include <vector>
#include "column.h"

using namespace Maths;
using namespace std;

Column::Column()
{
  // Empty constructor to allow an array of this class to be created.
}

Column::Column(std::vector<double> rowValues)
{
  this->rows = rowValues;
}

Column::Column(double *values, int length)
{

}

double Column::operator [] (int index)
{
  int indexRange = this->length() - 1;
  bool outOfRange = (index < 0 || index > indexRange);

  if (outOfRange)
    throw out_of_range("Row index is out of range.");

  return this->rows[index];
}

int Column::length()
{
  return this->rows.size();
}