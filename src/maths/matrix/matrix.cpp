#include <cmath>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

#include "src/maths/matrix/column.h"
#include "src/maths/matrix/matrix.h"
#include "src/maths/vector/vector.h"

using namespace Maths;
using namespace std;

Matrix::Matrix()
{
  this->columns = {};
}

Matrix::Matrix(std::vector<std::vector<double>> matrixColumns)
{
  bool isValidSize = this->checkStlVectorIsValidMatrixSize(matrixColumns);

  if (isValidSize)
    this->convertStlVectorToColumns(matrixColumns);

  else
    throw runtime_error(
      "Arithmetic error: vectors are not a congruent size.");
}

int Matrix::width()
{
  return this->columns.size();
}

int Matrix::height()
{
  int height = 0;
  bool hasColumns = !this->columns.empty();

  if (hasColumns)
    height = this->columns[0].length();

  return height;
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
  for (auto vector : vector2D) {
    Column column = Column(vector);
    this->columns.push_back(column);
  }
}

bool Matrix::isVectorCongruentSize(Maths::Vector vector)
{
  int vectorHeight = vector.length();
  int matrixWidth = this->width();

  bool isVectorCongruentSize = (vectorHeight == matrixWidth);

  return isVectorCongruentSize;
}

Maths::Vector Matrix::operator * (Maths::Vector vectorRhs)
{
  bool vectorIsIncongruentSize = !this->isVectorCongruentSize(vectorRhs);

  if (vectorIsIncongruentSize)
    throw length_error(
      "Arithmetic error: Vector is incongruent size to the " \
      "to the Matrix it is being multiplied against."
    );
  
  std::vector<double> newVectorValues = {};

  for (int rowNo = 0; rowNo < this->height(); rowNo++) {
    double newValue = 0;
    
    for (int columnNo = 0; columnNo < this->width(); columnNo++) {
      Column column = this->columns[columnNo];
      
      double matrixValue = column[rowNo];
      double vectorValue = vectorRhs[columnNo];

      double product = matrixValue * vectorValue;
      newValue += product;
    }
    
    newVectorValues.push_back(newValue);
  }

  Maths::Vector newVector = Vector(newVectorValues);

  return newVector;
}

Column Matrix::operator [] (int index)
{
  int indexRange = this->width() - 1;
  bool outOfRange = (index < 0 || index > indexRange);
  
  if (outOfRange)
    throw out_of_range("Column index is out of range.");

  return this->columns[index];
}