#include <cmath>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

#include "src/maths/matrix/matrix.h"
#include "src/maths/vector/vector.h"

using namespace Maths;
using namespace std;

Matrix::Matrix()
{
  this->columns = {};
}

Matrix::Matrix(std::vector<double> column)
{
  this->columns = {column};
}

Matrix::Matrix(std::vector<std::vector<double>> matrixColumns)
{
  bool isValidSize = this->check2DStlVectorIsValidMatrixSize(matrixColumns);

  if (isValidSize)
    this->convert2DStlVectorToColumns(matrixColumns);

  else
    throw runtime_error(
      "Arithmetic error: vectors are not a congruent size.");
}

void Matrix::convert2DStlVectorToColumns(std::vector<std::vector<double>> vector2D)
{
  for (auto vector : vector2D)
    this->columns.push_back(vector);
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
    height = this->columns.front().size();

  return height;
}

bool Matrix::check2DStlVectorIsValidMatrixSize(
    std::vector<std::vector<double>> vector2D)
{
  int sizeToCheck = vector2D.front().size();
  bool sizeMatches = true;

  for (auto vector : vector2D) {
    sizeMatches = (vector.size() == sizeToCheck);

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

bool Matrix::isMatrixMultipliable(Matrix otherMatrix)
{
  int matrixLhsWidth = this->width();
  int matrixRhsHeight = otherMatrix.height();

  bool isMatrixCongruentSize = (matrixLhsWidth == matrixRhsHeight);

  return isMatrixCongruentSize;
}

std::vector<double> Matrix::getColumn(int index)
{
  std::vector<double> columnValues = {};
  std::vector<double> column = (*this)[index];

  for (auto value : column)
    columnValues.push_back(value);

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
      std::vector<double> column = this->columns[columnNo];
      
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

Matrix Matrix::multiplyMatrix(Matrix matrixToMultiply)
{
  std::vector<std::vector<double>> newMatrixValues = 
    this->getValuesFromMatrixMultiplication(matrixToMultiply);
  
  Matrix newMatrix = Matrix(newMatrixValues);

  return newMatrix;
}

std::vector<std::vector<double>> Matrix::getValuesFromMatrixMultiplication(
    Matrix matrixToMultiply)
{
  std::vector<std::vector<double>> newMatrixValues = {};
  
  std::vector<std::vector<double>> otherMatrixColumns =
    matrixToMultiply.getColumns();

  for (auto otherMatrixColumn : otherMatrixColumns) {
    std::vector<double> newColumn =
      this->getProductAgainstAllRowsWithColumn(otherMatrixColumn);

    newMatrixValues.push_back(newColumn);
  }

  return newMatrixValues;
}

std::vector<double> Matrix::getProductAgainstAllRowsWithColumn(
  std::vector<double> column)
{
  std::vector<double> newColumn = {};
  std::vector<std::vector<double>> matrixRows = this->getRows();

  for (auto row : matrixRows) {
    double newColumnValue = this->getProductBetweenTwoStlVectors(
      row, column);

    newColumn.push_back(newColumnValue);
  }

  return newColumn; 
}

double Matrix::getProductBetweenTwoStlVectors(
    std::vector<double> vector1, std::vector<double> vector2)
{
  double totalProduct = 0;

  for (int commonIndex = 0; commonIndex < vector2.size(); commonIndex++) {
    double product = this->getProductBetweenTwoStlVectorsAtSameIndex(
      vector1, vector2, commonIndex);
    
    totalProduct += product;
  }

  return totalProduct;
}

double Matrix::getProductBetweenTwoStlVectorsAtSameIndex(
    std::vector<double> vector1, std::vector<double> vector2, int commonIndex)
{
  double value1 = vector1[commonIndex];
  double value2 = vector2[commonIndex];

  double product = value1 * value2;

  return product;
}

std::vector<double> Matrix::operator [] (int index)
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
  string allValues = "";

  std::vector<std::vector<double>> rows = this->getRows();
  int noOfRows = rows.size();

  for (int rowNo = 0; rowNo < noOfRows; rowNo++) {
    std::vector<double> row = rows[rowNo];
    string rowOfValues = this->formatStlVectorAsMatrixRow(row);

    bool moreRows = (rowNo < noOfRows - 1);
    
    if (moreRows)
      rowOfValues += "\n";

    allValues += rowOfValues;
  }

  return allValues;
}

string Matrix::formatStlVectorAsMatrixRow(std::vector<double> vector)
{
  string rowOfValues = "| ";

  for (auto value : vector)
    rowOfValues += to_string(value) + " ";

  rowOfValues += "|";

  return rowOfValues;
}