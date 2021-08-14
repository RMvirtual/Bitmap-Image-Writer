#include "matrix.h"
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <iterator>

using namespace Maths;
using namespace std;

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
      throw runtime_error(
        "Arithmetic error: vectors are not a congruent size.");
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

