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
  this->columns = {Column(column)};
}

Matrix::Matrix(vector<vector<double>> matrixColumns)
{
  bool isValidSize = this->checkVectorIsValidMatrixSize(matrixColumns);

  if (isValidSize)
    this->setVectorAsColumnsAndRows(matrixColumns);

  else
    throw runtime_error(
      "Arithmetic error: Vector is not a congruent size to be used to " \
      "populate a matrix."
    );
}

void Matrix::setVectorAsColumnsAndRows(vector<vector<double>> vector2D)
{
  for (auto vector : vector2D)
    this->columns.push_back(Column(vector));
}

int Matrix::width()
{
  return this->columns.size();
}

int Matrix::height()
{
  int height = 0;
  bool matrixIsNotEmpty = (!this->columns.empty());

  if (matrixIsNotEmpty)
    height = this->columns.front().size();

  return height;
}

bool Matrix::checkVectorIsValidMatrixSize(vector<vector<double>> vector)
{
  bool contentsEmpty = vector.empty();

  if (contentsEmpty)
    return false;
  
  int sizeToCheck = vector.front().size();
  bool sizeMatches = true;

  for (auto subVector : vector) {
    sizeMatches = (subVector.size() == sizeToCheck);

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
  int lhsMatrixWidth = this->width();
  int rhsMatrixHeight = otherMatrix.height();

  bool isMatrixCongruentSize = (lhsMatrixWidth == rhsMatrixHeight);

  return isMatrixCongruentSize;
}

vector<double> Matrix::getColumn(int index)
{
  vector<double> columnValues = {};
  Column column = (*this)[index];

  for (auto value : column.toVector())
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
  std::vector<double> newVectorValues
    = this->getMultipliedVectorValues(vector);
  
  Maths::Vector newVector = Maths::Vector(newVectorValues);

  return newVector;
}

std::vector<double> Matrix::getMultipliedVectorValues(Maths::Vector vector)
{
  std::vector<double> newVectorValues = {};
  std::vector<std::vector<double>> rows = this->getRows();

  for (auto row : rows) {
    double newValue = this->getProductBetweenTwoVectors(row, vector);
    newVectorValues.push_back(newValue);
  }

  return newVectorValues;
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
    double newColumnValue = this->getProductBetweenTwoVectors(
      row, column);

    newColumn.push_back(newColumnValue);
  }

  return newColumn; 
}

double Matrix::getProductBetweenTwoVectors(
    vector<double> vector1, vector<double> vector2)
{
  double totalProduct = 0;
  int noOfValues = vector1.size();

  for (int commonIndex = 0; commonIndex < noOfValues; commonIndex++) {
    double product = this->getProductBetweenTwoVectorsAtSameIndex(
      vector1, vector2, commonIndex);
    
    totalProduct += product;
  }

  return totalProduct;
}

double Matrix::getProductBetweenTwoVectors(
    vector<double> vector1, Maths::Vector vector2)
{
  double totalProduct = 0;
  int noOfValues = vector1.size();

  for (int commonIndex = 0; commonIndex < noOfValues; commonIndex++) {
    double product = this->getProductBetweenTwoVectorsAtSameIndex(
      vector1, vector2, commonIndex);
    
    totalProduct += product;
  }

  return totalProduct;
}

double Matrix::getProductBetweenTwoVectors(
    Maths::Vector vector1, std::vector<double> vector2)
{
  return this->getProductBetweenTwoVectors(vector2, vector1);
}

double Matrix::getProductBetweenTwoVectorsAtSameIndex(
    std::vector<double> vector1, std::vector<double> vector2, int commonIndex)
{
  double value1 = vector1[commonIndex];
  double value2 = vector2[commonIndex];

  double product = value1 * value2;

  return product;
}

double Matrix::getProductBetweenTwoVectorsAtSameIndex(
    std::vector<double> vector1, Maths::Vector vector2, int commonIndex)
{
  double value1 = vector1[commonIndex];
  double value2 = vector2[commonIndex];

  double product = value1 * value2;

  return product;
}

double Matrix::getProductBetweenTwoVectorsAtSameIndex(
    Maths::Vector vector1, vector<double> vector2, int commonIndex)
{
  return this->getProductBetweenTwoVectorsAtSameIndex(
    vector2, vector1, commonIndex);
}

Column Matrix::operator [] (int columnIndex)
{
  int indexRange = this->width() - 1;
  bool outOfRange = (columnIndex < 0 || columnIndex > indexRange);
  
  if (outOfRange)
    throw out_of_range("Column index is out of range.");

  Column column = this->columns[columnIndex]; 
  
  return column;
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