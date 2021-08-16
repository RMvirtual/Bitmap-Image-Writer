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

  for (int i = 0; i < column.length(); i++)
    columnValues.push_back(column[i]);

  return columnValues;
}

std::vector<double> Matrix::getRow(int index)
{
  std::vector<double> rowValues = {};

  for (auto column : this->columns)
    rowValues.push_back(column[index]);

  return rowValues;
}

std::vector<std::vector<double>> Matrix::getColumns()
{
  std::vector<std::vector<double>> columns = {};

  for (int i = 0; i < this->width(); i++) {
    std::vector<double> column = this->getColumn(i);
    columns.push_back(column);
  }

  return columns;
}

std::vector<std::vector<double>> Matrix::getRows()
{
  std::vector<std::vector<double>> rows = {};

  for (int i = 0; i < this->height(); i++) {
    std::vector<double> row = this->getRow(i);
    rows.push_back(row);
  }

  return rows;
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
  
  Matrix newMatrix = multiplyMatrix(matrixRhs);

  return newMatrix;
}

Matrix Matrix::multiplyMatrix(Matrix matrix)
{
  std::vector<std::vector<double>> newMatrixValues = {};
  Matrix matrixLhs = *this;
  Matrix matrixRhs = matrix;

  // Schoolbook algorithm for matrix multiplication.

  std::vector<std::vector<double>> matrixRhsColumns = matrixRhs.getColumns();

  for (auto rhsColumn : matrixRhsColumns) {
    std::vector<double> newColumn = 
      this->getNewColumnWithMatrixProduct(rhsColumn);

    newMatrixValues.push_back(newColumn);
  }

  Matrix newMatrix = Matrix(newMatrixValues);

  return newMatrix;
}

std::vector<double> Matrix::getNewColumnWithMatrixProduct(
  std::vector<double> rhsColumn)
{
  Matrix matrixLhs = *this;
  std::vector<double> newColumn = {};

  std::vector<std::vector<double>> matrixLhsRows = matrixLhs.getRows();

  for (auto lhsRow : matrixLhsRows) {
    double newColumnValueToAdd = 0;
    
    for (int commonIndex = 0; commonIndex < rhsColumn.size(); commonIndex++) {
      double product = this->getProductBetweenTwoVectorsAtSameIndex(
        lhsRow, rhsColumn, commonIndex);
      
      newColumnValueToAdd += product;
    }

    newColumn.push_back(newColumnValueToAdd);
  }

  return newColumn; 
}

double Matrix::getProductBetweenTwoMatrixVectors(
    std::vector<double> lhsRow, std::vector<double> rhsColumn)
{
  double newColumnValueToAdd = 0;

  for (int commonIndex = 0; commonIndex < rhsColumn.size(); commonIndex++) {
    double product = this->getProductBetweenTwoVectorsAtSameIndex(
      lhsRow, rhsColumn, commonIndex);
    
    newColumnValueToAdd += product;
  }

  return newColumnValueToAdd;
}

double Matrix::getProductBetweenTwoVectorsAtSameIndex(
    std::vector<double> vector1, std::vector<double> vector2, int commonIndex)
{
  double value1 = vector1[commonIndex];
  double value2 = vector2[commonIndex];

  double product = value1 * value2;

  return product;
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

string Matrix::toString()
{
  string allValues = this->getAllValuesAsString();

  return allValues;
}

string Matrix::getAllValuesAsString()
{
  string pointsRepresentation = "";
  int noOfRows = this->height();
  int noOfColumns = this->width();

  for (int rowNo = 0; rowNo < noOfRows; rowNo++) {
    string rowOfValues = "| ";

    for (int columnNo = 0; columnNo < noOfColumns; columnNo++) {
      string point = this->getValueAsString(columnNo, rowNo);
      rowOfValues += point;

      rowOfValues += " ";
    }

    rowOfValues += "|";

    bool moreRows = (rowNo < noOfRows - 1);
    
    if (moreRows)
      rowOfValues += "\n";

    pointsRepresentation += rowOfValues;
  }

  return pointsRepresentation;
}

string Matrix::getValueAsString(int columnNo, int rowNo)
{
  string point = to_string((*this)[columnNo][rowNo]);
  
  return point;
}