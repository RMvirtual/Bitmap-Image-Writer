#include "matrix.h"
#include <iostream>
#include <cmath>
#include <string>
#include "src/common/arrays.h"

using namespace Maths;
using namespace std;

Matrix::Matrix(ArrayList<ArrayList<double>> arraylist)
{
  this->matrixWidth = arraylist.size();
  this->matrixHeight = arraylist.get(0).size();

  this->columns = new Column[this->matrixWidth];

  for (int i = 0; i < this->matrixWidth; i++) {
    ArrayList<double> columnArray = arraylist.get(i);
    Column column = Column(columnArray.toArray(), this->matrixHeight);

    this->columns[i] = column;
  }
}

Matrix::Column::Column(double* values, int length)
{
  this->values = values;
  this->length = length;
}

Matrix::Column::Column()
{
  // Empty constructor to allow an array of this class to be created.
}


double Matrix::Column::operator[](int index)
{
  return this->values[index];
}