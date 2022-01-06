#include <cmath>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <string>
#include <sstream>
#include <vector>

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
  this->isVectorValidSize(matrixColumns) ?
    this->from2DVector(matrixColumns) : throw std::runtime_error(
      "Arithmetic error: Vector is not a congruent size to be used to " \
      "populate a matrix."
    );
}

void Maths::Matrix::from2DVector(std::vector<std::vector<double>> vector2D)
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
  return this->columns.size() ? this->columns.front().size() : 0;
}

bool Maths::Matrix::isVectorValidSize(std::vector<std::vector<double>> vector)
{
  if (vector.empty())
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
  return (vector.length() == this->width());
}

bool Maths::Matrix::isMatrixMultipliable(Maths::Matrix otherMatrix)
{
  return (this->width() == otherMatrix.height());
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

  for (int columnNo = 0; columnNo < this->width(); columnNo++)
    columns.push_back(this->getColumn(columnNo));

  return columns;
}

std::vector<std::vector<double>> Maths::Matrix::getRows()
{
  std::vector<std::vector<double>> rows = {};

  for (int rowNo = 0; rowNo < this->height(); rowNo++)
    rows.push_back(this->getRow(rowNo));

  return rows;
}

Maths::Vector Maths::Matrix::operator * (Maths::Vector vector)
{
  return this->isVectorMultipliable(vector) ? this->multiplyVector(vector) :
    throw std::length_error(
      "Arithmetic error: Vector is incongruent size to the " \
      "to the Matrix it is being multiplied against."
    );
}

Maths::Vector Maths::Matrix::multiplyVector(Maths::Vector vector)
{ 
  return Maths::Vector(this->getMultipliedVectorValues(vector));
}

std::vector<double> Maths::Matrix::getMultipliedVectorValues(
  Maths::Vector vector)
{
  std::vector<double> newVectorValues = {};

  for (auto row : this->getRows())
    newVectorValues.push_back(this->calculateProduct(row, vector));

  return newVectorValues;
}

Maths::Matrix Maths::Matrix::operator * (Maths::Matrix matrixRhs)
{
  return this->isMatrixMultipliable(matrixRhs) ?
    multiplyMatrix(matrixRhs) : throw std::length_error(
      "Arithmetic error: Matrix has incongruent dimensions to the " \
      "to the Matrix it is being multiplied against."
    );
}

Maths::Matrix Maths::Matrix::multiplyMatrix(Maths::Matrix matrixToMultiply)
{
  return Maths::Matrix(this->getValuesFromMultiplication(matrixToMultiply));
}

std::vector<std::vector<double>> Maths::Matrix::getValuesFromMultiplication(
  Maths::Matrix matrixToMultiply)
{
  std::vector<std::vector<double>> newMatrixValues = {};
  
  for (auto column : matrixToMultiply.getColumns())
    newMatrixValues.push_back(this->getProductAgainstAllRows(column));

  return newMatrixValues;
}

std::vector<double> Maths::Matrix::getProductAgainstAllRows(
  std::vector<double> column)
{
  std::vector<double> newColumn = {};

  for (auto row : this->getRows())
    newColumn.push_back(this->calculateProduct(row, column));

  return newColumn; 
}

double Maths::Matrix::calculateProduct(
  std::vector<double> vector1, std::vector<double> vector2)
{
  double totalProduct = 0;
  int noOfValues = vector1.size();

  for (int commonIndex = 0; commonIndex < noOfValues; commonIndex++)
    totalProduct += this->calculateProduct(vector1, vector2, commonIndex);

  return totalProduct;
}

double Maths::Matrix::calculateProduct(
  std::vector<double> vector1, Maths::Vector vector2)
{
  double totalProduct = 0;
  int noOfValues = vector1.size();

  for (int commonIndex = 0; commonIndex < noOfValues; commonIndex++)
    totalProduct += this->calculateProduct(vector1, vector2, commonIndex);

  return totalProduct;
}

double Maths::Matrix::calculateProduct(
  Maths::Vector vector1, std::vector<double> vector2)
{
  return this->calculateProduct(vector2, vector1);
}

double Maths::Matrix::calculateProduct(
  std::vector<double> vector1, std::vector<double> vector2, int commonIndex)
{
  return vector1[commonIndex] * vector2[commonIndex];
}

double Maths::Matrix::calculateProduct(
  std::vector<double> vector1, Maths::Vector vector2, int commonIndex)
{
  return vector1[commonIndex] * vector2[commonIndex];
}

double Maths::Matrix::calculateProduct(
  Maths::Vector vector1, std::vector<double> vector2, int commonIndex)
{
  return this->calculateProduct(vector2, vector1, commonIndex);
}

Maths::Column Maths::Matrix::operator [] (int columnIndex)
{
  return this->isColumnIndexInRange(columnIndex) ? this->columns[columnIndex] :
    throw std::out_of_range("Column index is out of range.");
}

bool Maths::Matrix::isColumnIndexInRange(int index)
{
  return (index >= 0 || index <= this->width() - 1);
}

Maths::Vector operator * (Maths::Vector vectorLhs, Maths::Matrix matrixRhs)
{
  return matrixRhs * vectorLhs;
}

std::string Maths::Matrix::toString()
{
  return this->getAllValuesAsString();
}

std::string Maths::Matrix::getAllValuesAsString()
{
  std::string allValues = "";

  std::vector<std::vector<double>> rows = this->getRows();
  int noOfRows = rows.size();

  for (int rowNo = 0; rowNo < noOfRows; rowNo++) {
    std::vector<double> row = rows[rowNo];
    std::string rowOfValues = this->transposeToMatrixRow(row);

    bool moreRowsRemaining = (rowNo < noOfRows - 1);
    
    if (moreRowsRemaining)
      rowOfValues += "\n";

    allValues += rowOfValues;
  }

  return allValues;
}

std::string Maths::Matrix::transposeToMatrixRow(std::vector<double> vector)
{
  std::string rowOfValues = "| ";

  for (auto value : vector) {
    std::ostringstream stringFormatter;
    stringFormatter << std::setprecision(8) << std::noshowpoint << value;

    rowOfValues += stringFormatter.str() + " ";
  }
  
  return rowOfValues += "|";
}