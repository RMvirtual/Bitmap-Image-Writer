#include <iostream>
#include <vector>

#include "src/main/cpp/maths/matrix/column.h"

Maths::Column::Column(std::vector<double> vector)
{
  this->values = vector;
}

double Maths::Column::operator [](int rowIndex) const
{
  int indexRange = this->size() - 1;
  bool outOfRange = (rowIndex < 0 || rowIndex > indexRange);
  
  if (outOfRange)
    throw std::out_of_range("Row index is out of range.");

  return (*this).values[rowIndex];
}

int Maths::Column::size() const
{
  return this->values.size();
}

std::vector<double>::iterator Maths::Column::begin()
{
  return this->values.begin();
}

std::vector<double>::iterator Maths::Column::end()
{
  return this->values.end();
}

std::vector<double>::const_iterator Maths::Column::begin() const
{
  return this->values.begin();
}

std::vector<double>::const_iterator Maths::Column::end() const
{
  return this->values.end();
}