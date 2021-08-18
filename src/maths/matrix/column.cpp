#include <iostream>
#include <vector>
#include "src/maths/matrix/column.h"

using namespace Maths;

Column::Column(std::vector<double> vector)
{
  this->values = vector;
}

double Column::operator [] (int rowIndex)
{
  int indexRange = this->size() - 1;
  bool outOfRange = (rowIndex < 0 || rowIndex > indexRange);
  
  if (outOfRange)
    throw out_of_range("Row index is out of range.");

  double value = (*this).values[rowIndex];

  return value;
}

int Column::size()
{
  return this->values.size();
}

std::vector<double>::iterator Column::begin()
{
  return this->values.begin();
}

std::vector<double>::iterator Column::end()
{
  return this->values.end();
}

std::vector<double>::const_iterator Column::begin() const
{
  return this->values.begin();
}

std::vector<double>::const_iterator Column::end() const
{
  return this->values.end();
}