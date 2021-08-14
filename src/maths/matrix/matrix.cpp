#include "matrix.h"
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <iterator>

using namespace Maths;
using namespace std;

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
  cout << "Row Index: " + to_string(index) << endl;

  return this->rows[index];
}


Matrix::Matrix(std::vector<std::vector<double>> matrixColumns)
{
  bool isValidSize = this->checkStlVectorIsValidMatrixSize(matrixColumns);

  if (isValidSize)
    this->convertStlVectorToColumns(matrixColumns);
}

Column Matrix::operator [] (int index)
{
  cout << "Column Index: " + to_string(index) << endl;
  
  return this->columns[index];
}

bool Matrix::checkStlVectorIsValidMatrixSize(
    std::vector<std::vector<double>> vector2D)
{
  auto vectorIterator = vector2D.begin();
  auto lastVector = vector2D.end();
  
  int sizeToCheck = (*vectorIterator).size();
  bool sizeMatches = true;

  for (; vectorIterator != lastVector; ++vectorIterator) {
    std::vector<double> vector = *vectorIterator;

    int vectorSize = vector.size();
    sizeMatches = (vectorSize == sizeToCheck);

    if (!sizeMatches)
      break;
  }

  return sizeMatches;
}

void Matrix::convertStlVectorToColumns(std::vector<std::vector<double>> vector2D)
{
  auto vectorIterator = vector2D.begin();
  auto lastVector = vector2D.end();
  
  for (; vectorIterator != lastVector; vectorIterator++) {
    std::vector<double> vector = *vectorIterator;
    Column column = Column(vector);

    this->columns.push_back(column);
  }
}