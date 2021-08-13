#include "matrix.h"
#include <iostream>
#include <cmath>
#include <string>
#include <vector>

using namespace Maths;
using namespace std;

Matrix::Matrix(vector<vector<double>>)
{
  this->matrixWidth = arraylist.size();
  this->matrixHeight = arraylist.get(0).size();

  this->columns = new Column[this->matrixWidth];

  for (int i = 0; i < this->matrixWidth; i++) {
    vector<double> columnArray = arraylist.get(i);
    double* array = columnArray.toArray();
    Column column = Column(array, this->matrixHeight);

    this->columns[i] = column;
  }
}

Column::Column(double* values, int length)
{
  this->values = values;
  this->length = length;
}

Column::Column()
{
  // Empty constructor to allow an array of this class to be created.
}

double Matrix::operator [] (int index)
{
  return this->columns[index][index];
}

double Column::operator [] (int index)
{
  return this->values[index];
}