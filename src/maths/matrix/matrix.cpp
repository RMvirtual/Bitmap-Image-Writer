#include <cmath>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

#include <sstream>
#include <iomanip>

#include "src/maths/matrix/matrix.h"
#include "src/maths/vector/vector.h"

Maths::Matrix::Matrix()
{
  this->columns = {};
}

Maths::Matrix::Matrix(std::vector<double> column)
{
  this->columns = {Maths::Column(column)};
}

Maths::Matrix::Matrix(std::vector<std::vector<double>> matrixColumns)
{
  bool isValidSize = this->checkVectorIsValidMatrixSize(matrixColumns);

  if (isValidSize)
    this->setVectorAsColumnsAndRows(matrixColumns);

  else
    throw std::runtime_error(
      "Arithmetic error: Vector is not a congruent size to be used to " \
      "populate a matrix."
    );
}

void Maths::Matrix::setVectorAsColumnsAndRows(
  std::vector<std::vector<double>> vector2D)
{
  for (auto vector : vector2D)
    this->columns.push_back(Maths::Column(vector));
}

int Maths::Matrix::width()
{
  return this->columns.size();
}

int Maths::Matrix::height()
{
  int height = 0;
  bool matrixIsNotEmpty = (!this->columns.empty());

  if (matrixIsNotEmpty)
    height = this->columns.front().size();

  return height;
}

bool Maths::Matrix::checkVectorIsValidMatrixSize(
  std::vector<std::vector<double>> vector)
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

bool Maths::Matrix::isVectorMultipliable(Maths::Vector vector)
{
  int vectorHeight = vector.length();
  int matrixWidth = this->width();

  bool isVectorCongruentSize = (vectorHeight == matrixWidth);

  return isVectorCongruentSize;
}

bool Maths::Matrix::isMatrixMultipliable(Maths::Matrix otherMatrix)
{
  int lhsMatrixWidth = this->width();
  int rhsMatrixHeight = otherMatrix.height();

  bool isMatrixCongruentSize = (lhsMatrixWidth == rhsMatrixHeight);

  return isMatrixCongruentSize;
}

std::vector<double> Maths::Matrix::getColumn(int index)
{
  std::vector<double> columnValues = {};
  Maths::Column column = (*this)[index];

  for (auto value : column)
    columnValues.push_back(value);

  return columnValues;
}

std::vector<double> Maths::Matrix::getRow(int index)
{
  std::vector<double> rowValues = {};

  for (auto column : this->columns)
    rowValues.push_back(column[index]);

  return rowValues;
}

std::vector<std::vector<double>> Maths::Matrix::getColumns()
{
  std::vector<std::vector<double>> columns = {};

  for (int i = 0; i < this->width(); i++) {
    std::vector<double> column = this->getColumn(i);
    columns.push_back(column);
  }

  return columns;
}

std::vector<std::vector<double>> Maths::Matrix::getRows()
{
  std::vector<std::vector<double>> rows = {};

  for (int i = 0; i < this->height(); i++) {
    std::vector<double> row = this->getRow(i);
    rows.push_back(row);
  }

  return rows;
}

Maths::Vector Maths::Matrix::operator * (Maths::Vector vector)
{
  bool vectorIsIncongruentSize = 
    !this->isVectorMultipliable(vector);

  if (vectorIsIncongruentSize)
    throw std::length_error(
      "Arithmetic error: Vector is incongruent size to the " \
      "to the Matrix it is being multiplied against."
    );
  
  Maths::Vector newVector = this->multiplyVector(vector);

  return newVector;
}

Maths::Vector Maths::Matrix::multiplyVector(Maths::Vector vector)
{
  std::vector<double> newVectorValues
    = this->getMultipliedVectorValues(vector);
  
  Maths::Vector newVector = Maths::Vector(newVectorValues);

  return newVector;
}

std::vector<double> Maths::Matrix::getMultipliedVectorValues(
  Maths::Vector vector)
{
  std::vector<double> newVectorValues = {};
  std::vector<std::vector<double>> rows = this->getRows();

  for (auto row : rows) {
    double newValue = this->getProductBetweenTwoVectors(row, vector);
    newVectorValues.push_back(newValue);
  }

  return newVectorValues;
}

Maths::Matrix Maths::Matrix::operator * (Maths::Matrix matrixRhs)
{
  bool matrixIsIncongruentSize = !this->isMatrixMultipliable(matrixRhs);

  if (matrixIsIncongruentSize)
    throw std::length_error(
      "Arithmetic error: Matrix has incongruent dimensions to the " \
      "to the Matrix it is being multiplied against."
    );
  
  Matrix newMatrix = multiplyMatrix(matrixRhs);

  return newMatrix;
}

Maths::Matrix Maths::Matrix::multiplyMatrix(Maths::Matrix matrixToMultiply)
{
  std::vector<std::vector<double>> newMatrixValues = 
    this->getValuesFromMatrixMultiplication(matrixToMultiply);
  
  Maths::Matrix newMatrix = Maths::Matrix(newMatrixValues);

  return newMatrix;
}

std::vector<std::vector<double>>
Maths::Matrix::getValuesFromMatrixMultiplication(
  Maths::Matrix matrixToMultiply)
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

std::vector<double> Maths::Matrix::getProductAgainstAllRowsWithColumn(
  std::vector<double> column)
{
  std::vector<double> newColumn = {};
  std::vector<std::vector<double>> matrixRows = this->getRows();

  for (auto row : matrixRows) {
    double newColumnValue = this->getProductBetweenTwoVectors(
      row, column);

    newColumn.push_back(newColumnValue);
  }

  return newColumn; 
}

double Maths::Matrix::getProductBetweenTwoVectors(
  std::vector<double> vector1, std::vector<double> vector2)
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

double Maths::Matrix::getProductBetweenTwoVectors(
  std::vector<double> vector1, Maths::Vector vector2)
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

double Maths::Matrix::getProductBetweenTwoVectors(
  Maths::Vector vector1, std::vector<double> vector2)
{
  return this->getProductBetweenTwoVectors(vector2, vector1);
}

double Maths::Matrix::getProductBetweenTwoVectorsAtSameIndex(
  std::vector<double> vector1, std::vector<double> vector2, int commonIndex)
{
  double value1 = vector1[commonIndex];
  double value2 = vector2[commonIndex];

  double product = value1 * value2;

  return product;
}

double Maths::Matrix::getProductBetweenTwoVectorsAtSameIndex(
  std::vector<double> vector1, Maths::Vector vector2, int commonIndex)
{
  double value1 = vector1[commonIndex];
  double value2 = vector2[commonIndex];

  double product = value1 * value2;

  return product;
}

double Maths::Matrix::getProductBetweenTwoVectorsAtSameIndex(
  Maths::Vector vector1, std::vector<double> vector2, int commonIndex)
{
  return this->getProductBetweenTwoVectorsAtSameIndex(
    vector2, vector1, commonIndex);
}

Maths::Column Maths::Matrix::operator [] (int columnIndex)
{
  int indexRange = this->width() - 1;
  bool outOfRange = (columnIndex < 0 || columnIndex > indexRange);
  
  if (outOfRange)
    throw std::out_of_range("Column index is out of range.");

  Column column = this->columns[columnIndex]; 
  
  return column;
}

Maths::Vector operator * (Maths::Vector vectorLhs, Maths::Matrix matrixRhs)
{
  return matrixRhs * vectorLhs;
}

std::string Maths::Matrix::toString()
{
  std::string allValues = this->getAllValuesAsString();

  return allValues;
}

std::string Maths::Matrix::getAllValuesAsString()
{
  std::string allValues = "";

  std::vector<std::vector<double>> rows = this->getRows();
  int noOfRows = rows.size();

  for (int rowNo = 0; rowNo < noOfRows; rowNo++) {
    std::vector<double> row = rows[rowNo];
    std::string rowOfValues = this->formatStlVectorAsMatrixRow(row);

    bool moreRows = (rowNo < noOfRows - 1);
    
    if (moreRows)
      rowOfValues += "\n";

    allValues += rowOfValues;
  }

  return allValues;
}

std::string Maths::Matrix::formatStlVectorAsMatrixRow(
  std::vector<double> vector)
{
  std::string rowOfValues = "| ";

  for (auto value : vector) {
    std::ostringstream stringFormatter;
    stringFormatter << std::setprecision(8) << std::noshowpoint << value;

    rowOfValues += stringFormatter.str() + " ";
  }
  
  rowOfValues += "|";

  return rowOfValues;
}