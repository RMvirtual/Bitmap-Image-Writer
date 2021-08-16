#include <cmath>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

#include "src/maths/matrix/matrix_vector.h"
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

void Matrix::convertStlVectorToColumns(std::vector<std::vector<double>> vector2D)
{ 
  for (auto vector : vector2D) {
    MatrixVector column = MatrixVector(vector);
    this->columns.push_back(column);
  }
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

bool Matrix::isVectorMultipliable(Maths::Vector vector)
{
  int vectorHeight = vector.length();
  int matrixWidth = this->width();

  bool isVectorCongruentSize = (vectorHeight == matrixWidth);

  return isVectorCongruentSize;
}

bool Matrix::isMatrixMultipliable(Matrix matrixRhs)
{
  int matrixLhsWidth = this->width();
  int matrixRhsHeight = this->height();

  bool isMatrixCongruentSize = (matrixLhsWidth == matrixRhsHeight);

  return isMatrixCongruentSize;
}

std::vector<double> Matrix::getColumn(int index)
{
  std::vector<double> columnValues = {};

  MatrixVector column = (*this)[index];

  for (int i = 0; i < column.length(); i++) {
    cout << "next value is: " + to_string(column[index]) << endl; 
    columnValues.push_back(column[index]);
  }
  return columnValues;
}

std::vector<double> Matrix::getRow(int index)
{
  std::vector<double> rowValues = {};

  for (auto column : this->columns)
    rowValues.push_back(column[index]);

  return rowValues;
}


Maths::Vector Matrix::operator * (Maths::Vector vectorRhs)
{
  bool vectorIsIncongruentSize = !this->isVectorMultipliable(vectorRhs);

  if (vectorIsIncongruentSize)
    throw length_error(
      "Arithmetic error: Vector is incongruent size to the " \
      "to the Matrix it is being multiplied against."
    );
  
  std::vector<double> newVectorValues = {};

  for (int rowNo = 0; rowNo < this->height(); rowNo++) {
    double newValue = 0;
    
    for (int columnNo = 0; columnNo < this->width(); columnNo++) {
      MatrixVector column = this->columns[columnNo];
      
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

Matrix Matrix::operator * (Matrix matrixRhs)
{
  bool matrixIsIncongruentSize = !this->isMatrixMultipliable(matrixRhs);

  if (matrixIsIncongruentSize)
    throw length_error(
      "Arithmetic error: Matrix has incongruent dimensions to the " \
      "to the Matrix it is being multiplied against."
    );
  
  std::vector<std::vector<double>> newMatrixValues = {};
  Matrix matrixLhs = *this;

  /* Schoolbook algorithm for matrix multiplication.
  for (int lhsColumnNo = 0; lhsColumnNo < matrixLhs.width(); lhsColumnNo++) {
    for (int rhsColumnNo = 0; rhsColumnNo < matrixRhs.width(); rhsColumnNo++) {
      
      
      double newValue = 0;
      
      for (int rhsMatrixColumnNo = 0; rhsMatrixColumnNo < matrixRhs.width(); rhsMatrixColumnNo++) {
        double lhsMatrixValue = matrixLhs[lhsColumnNo][rhsMatrixColumnNo];
        double rhsMatrixValue = matrixRhs[rhsMatrixColumnNo][lhsColumnNo];
        double product = lhsMatrixValue * rhsMatrixValue;

        cout << "lhsMatrixValue: " + to_string(lhsMatrixValue) << endl;
        cout << "rhsMatrixValue: " + to_string(rhsMatrixValue) << endl;
        cout << "product: " + to_string(product) << endl;
        
        newValue += product;

        cout << "New value now: " + to_string(newValue) << endl;
      }

      newRowValues.push_back(newValue);
    }

    newMatrixValues.push_back(newRowValues);
  }
  */

  Matrix newMatrix = Matrix();

  return newMatrix;
}

MatrixVector Matrix::operator [] (int index)
{
  int indexRange = this->width() - 1;
  bool outOfRange = (index < 0 || index > indexRange);
  
  if (outOfRange)
    throw out_of_range("Column index is out of range.");

  return this->columns[index];
}

Maths::Vector operator * (Maths::Vector vectorLhs, Matrix matrixRhs)
{
  return matrixRhs * vectorLhs;
}