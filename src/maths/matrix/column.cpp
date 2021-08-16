#include <iostream>
#include <vector>
#include "src/maths/matrix/column.h"

Column::Column(std::vector<double> vector)
{
  this->vector = vector;
}

double Column::operator [] (int rowIndex)
{
  int indexRange = this->size() - 1;
  bool outOfRange = (rowIndex < 0 || rowIndex > indexRange);
  
  if (outOfRange)
    throw out_of_range("Row index is out of range.");

  double value = (*this).vector[rowIndex];

  return value;
}

int Column::size()
{
  return this->vector.size();
}

std::vector<double> Column::toVector()
{
    return this->vector;
}