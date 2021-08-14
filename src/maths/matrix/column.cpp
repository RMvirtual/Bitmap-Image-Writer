#include "column.h"
#include <vector>

using namespace Maths;

Column::Column()
{
  // Empty constructor to allow an array of this class to be created.
}

Column::Column(std::vector<double> columnValues)
{
  this->rows = columnValues;  
}

Column::Column(double* values, int length)
{

}

double Column::operator [] (int index)
{
  return this->rows[index];
}

int Column::length()
{
    return this->rows.size();
}