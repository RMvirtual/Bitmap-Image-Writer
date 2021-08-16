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

Matrix::Matrix(vector<double> column)
{
  this->columns = {column};
}

Matrix::Matrix(vector<vector<double>> matrixColumns)
{
  bool isValidSize = this->check2DStlVectorIsValidMatrixSize(matrixColumns);

  if (isValidSize)
    this->convert2DStlVectorToColumns(matrixColumns);

  else
    throw runtime_error(
      "Arithmetic error: vectors are not a congruent size.");
}

void Matrix::convert2DStlVectorToColumns(vector<vector<double>> vector2D)
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
  vector<vector<double>> vector2D)
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

vector<double> Matrix::getColumn(int index)
{
  vector<double> columnValues = {};
  vector<double> column = (*this)[index];

  for (auto value : column)
    columnValues.push_back(value);

  return columnValues;
}

vector<double> Matrix::getRow(int index)
{
  vector<double> rowValues = {};

  for (auto column : this->columns)
    rowValues.push_back(column[index]);

  return rowValues;
}

vector<vector<double>> Matrix::getColumns()
{
  vector<vector<double>> columns = {};

  for (int i = 0; i < this->width(); i++) {
    vector<double> column = this->getColumn(i);
    columns.push_back(column);
  }

  return columns;
}

vector<vector<double>> Matrix::getRows()
{
  vector<vector<double>> rows = {};

  for (int i = 0; i < this->height(); i++) {
    vector<double> row = this->getRow(i);
    rows.push_back(row);
  }

  return rows;
}

Maths::Vector Matrix::operator * (Maths::Vector vector)
{
  bool vectorIsIncongruentSize = 
    !this->isVectorMultipliable(vector);

  if (vectorIsIncongruentSize)
    throw length_error(
      "Arithmetic error: Vector is incongruent size to the " \
      "to the Matrix it is being multiplied against."
    );
  
  Maths::Vector newVector = this->multiplyVector(vector);

  return newVector;
}

Maths::Vector Matrix::multiplyVector(Maths::Vector vector)
{
  std::vector<double> newVectorValues = {};

  for (int rowNo = 0; rowNo < this->height(); rowNo++) {
    double newValue = 0;
    
    for (int columnNo = 0; columnNo < this->width(); columnNo++) {
      std::vector<double> column = this->columns[columnNo];
      
      double matrixValue = column[rowNo];
      double vectorValue = vector[columnNo];

      double product = matrixValue * vectorValue;
      newValue += product;
    }
    
    newVectorValues.push_back(newValue);
  }

  Maths::Vector newVector = Maths::Vector(newVectorValues);

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
  vector<vector<double>> newMatrixValues = 
    this->getValuesFromMatrixMultiplication(matrixToMultiply);
  
  Matrix newMatrix = Matrix(newMatrixValues);

  return newMatrix;
}

vector<vector<double>> Matrix::getValuesFromMatrixMultiplication(
    Matrix matrixToMultiply)
{
  vector<vector<double>> newMatrixValues = {};
  
  vector<vector<double>> otherMatrixColumns =
    matrixToMultiply.getColumns();

  for (auto otherMatrixColumn : otherMatrixColumns) {
    vector<double> newColumn =
      this->getProductAgainstAllRowsWithColumn(otherMatrixColumn);

    newMatrixValues.push_back(newColumn);
  }

  return newMatrixValues;
}

vector<double> Matrix::getProductAgainstAllRowsWithColumn(
    vector<double> column)
{
  vector<double> newColumn = {};
  vector<vector<double>> matrixRows = this->getRows();

  for (auto row : matrixRows) {
    double newColumnValue = this->getProductBetweenTwoStlVectors(
      row, column);

    newColumn.push_back(newColumnValue);
  }

  return newColumn; 
}

double Matrix::getProductBetweenTwoStlVectors(
    vector<double> vector1, vector<double> vector2)
{
  double totalProduct = 0;
  int noOfValues = vector1.size();

  for (int commonIndex = 0; commonIndex < noOfValues; commonIndex++) {
    double product = this->getProductBetweenTwoStlVectorsAtSameIndex(
      vector1, vector2, commonIndex);
    
    totalProduct += product;
  }

  return totalProduct;
}

double Matrix::getProductBetweenTwoStlVectorsAtSameIndex(
    vector<double> vector1, vector<double> vector2, int commonIndex)
{
  double value1 = vector1[commonIndex];
  double value2 = vector2[commonIndex];

  double product = value1 * value2;

  return product;
}

vector<double> Matrix::operator [] (int index)
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

  vector<vector<double>> rows = this->getRows();
  int noOfRows = rows.size();

  for (int rowNo = 0; rowNo < noOfRows; rowNo++) {
    vector<double> row = rows[rowNo];
    string rowOfValues = this->formatStlVectorAsMatrixRow(row);

    bool moreRows = (rowNo < noOfRows - 1);
    
    if (moreRows)
      rowOfValues += "\n";

    allValues += rowOfValues;
  }

  return allValues;
}

string Matrix::formatStlVectorAsMatrixRow(vector<double> vector)
{
  string rowOfValues = "| ";

  for (auto value : vector)
    rowOfValues += to_string(value) + " ";

  rowOfValues += "|";

  return rowOfValues;
}