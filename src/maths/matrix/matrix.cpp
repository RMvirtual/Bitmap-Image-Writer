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

Maths::Matrix::Matrix(const std::vector<double>& column)
{
  this->columns = {Maths::Column(column)};
}

Maths::Matrix::Matrix(const std::vector<std::vector<double>>& matrixColumns)
{
  this->isVectorValidSize(matrixColumns) ?
    this->from2DVector(matrixColumns) : throw std::runtime_error(
      "Arithmetic error: Vector is not a congruent size to be used to " \
      "populate a matrix."
    );
}

void Maths::Matrix::from2DVector(
  const std::vector<std::vector<double>>& vector2D)
{
  for (auto vector : vector2D)
    this->columns.push_back(Maths::Column(vector));
}

int Maths::Matrix::width() const
{
  return this->columns.size();
}

int Maths::Matrix::height() const
{
  return this->columns.size() ? this->columns.front().size() : 0;
}

bool Maths::Matrix::isVectorValidSize(
  const std::vector<std::vector<double>>& vector) const
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

bool Maths::Matrix::isVectorMultipliable(const Maths::Vector& vector) const
{
  return (this->width() == vector.length());
}

bool Maths::Matrix::isMatrixMultipliable(const Maths::Matrix& matrix) const
{
  return (this->width() == matrix.height());
}

std::vector<double> Maths::Matrix::getColumn(int index) const
{
  std::vector<double> columnValues = {};
  Maths::Column column = (*this)[index];

  for (auto value : column)
    columnValues.push_back(value);

  return columnValues;
}

std::vector<double> Maths::Matrix::getRow(int index) const
{
  std::vector<double> rowValues = {};

  for (auto column : this->columns)
    rowValues.push_back(column[index]);

  return rowValues;
}

std::vector<std::vector<double>> Maths::Matrix::getColumns() const
{
  std::vector<std::vector<double>> columns = {};

  for (int columnNo = 0; columnNo < this->width(); columnNo++)
    columns.push_back(this->getColumn(columnNo));

  return columns;
}

std::vector<std::vector<double>> Maths::Matrix::getRows() const
{
  std::vector<std::vector<double>> rows = {};

  for (int rowNo = 0; rowNo < this->height(); rowNo++)
    rows.push_back(this->getRow(rowNo));

  return rows;
}

Maths::Vector Maths::Matrix::operator * (const Maths::Vector& vector) const
{
  return this->isVectorMultipliable(vector) ? this->multiplyVector(vector) :
    throw std::length_error(
      "Arithmetic error: Vector is incongruent size to the " \
      "to the Matrix it is being multiplied against."
    );
}

Maths::Vector Maths::Matrix::multiplyVector(const Maths::Vector& vector) const
{ 
  return Maths::Vector(this->getMultipliedVectorValues(vector));
}

std::vector<double> Maths::Matrix::getMultipliedVectorValues(
  const Maths::Vector& vector) const
{
  std::vector<double> newVectorValues = {};

  for (auto row : this->getRows())
    newVectorValues.push_back(this->calculateProduct(row, vector));

  return newVectorValues;
}

Maths::Matrix Maths::Matrix::operator * (const Maths::Matrix& matrixRhs) const
{
  return this->isMatrixMultipliable(matrixRhs) ?
    multiplyMatrix(matrixRhs) : throw std::length_error(
      "Arithmetic error: Matrix has incongruent dimensions to the " \
      "to the Matrix it is being multiplied against."
    );
}

Maths::Matrix Maths::Matrix::multiplyMatrix(
  const Maths::Matrix& matrixToMultiply) const
{
  return Maths::Matrix(this->getValuesFromMultiplication(matrixToMultiply));
}

std::vector<std::vector<double>> Maths::Matrix::getValuesFromMultiplication(
  const Maths::Matrix& matrixToMultiply) const
{
  std::vector<std::vector<double>> newMatrixValues = {};
  
  for (auto column : matrixToMultiply.getColumns())
    newMatrixValues.push_back(this->getProductAgainstAllRows(column));

  return newMatrixValues;
}

std::vector<double> Maths::Matrix::getProductAgainstAllRows(
  const std::vector<double>& column) const
{
  std::vector<double> newColumn = {};

  for (auto row : this->getRows())
    newColumn.push_back(this->calculateProduct(row, column));

  return newColumn; 
}

double Maths::Matrix::calculateProduct(
  const std::vector<double>& vector1, const std::vector<double>& vector2) const
{
  double totalProduct = 0;
  int noOfValues = vector1.size();

  for (int commonIndex = 0; commonIndex < noOfValues; commonIndex++)
    totalProduct += this->calculateProduct(vector1, vector2, commonIndex);

  return totalProduct;
}

double Maths::Matrix::calculateProduct(
  const std::vector<double>& vector1, const Maths::Vector& vector2) const
{
  double totalProduct = 0;
  int noOfValues = vector1.size();

  for (int commonIndex = 0; commonIndex < noOfValues; commonIndex++)
    totalProduct += this->calculateProduct(vector1, vector2, commonIndex);

  return totalProduct;
}

double Maths::Matrix::calculateProduct(
  const Maths::Vector& vector1, const std::vector<double>& vector2) const
{
  return this->calculateProduct(vector2, vector1);
}

double Maths::Matrix::calculateProduct(
  const std::vector<double>& vector1, const std::vector<double>& vector2,
  int commonIndex) const
{
  return vector1[commonIndex] * vector2[commonIndex];
}

double Maths::Matrix::calculateProduct(
  const std::vector<double>& vector1, const Maths::Vector& vector2,
  int commonIndex) const
{
  return vector1[commonIndex] * vector2[commonIndex];
}

double Maths::Matrix::calculateProduct(
  const Maths::Vector& vector1, const std::vector<double>& vector2,
  int commonIndex) const
{
  return this->calculateProduct(vector2, vector1, commonIndex);
}

Maths::Column Maths::Matrix::operator [] (int columnIndex) const
{
  return this->isColumnIndexInRange(columnIndex) ? this->columns[columnIndex] :
    throw std::out_of_range("Column index is out of range.");
}

bool Maths::Matrix::isColumnIndexInRange(int index) const
{
  return (index >= 0 || index <= this->width() - 1);
}

Maths::Vector operator * (
  const Maths::Vector& vectorLhs, const Maths::Matrix& matrixRhs)
{
  return matrixRhs * vectorLhs;
}

std::string Maths::Matrix::toString() const
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

std::string Maths::Matrix::transposeToMatrixRow(
  const std::vector<double>& vector) const
{
  std::string rowOfValues = "| ";

  for (auto value : vector) {
    std::ostringstream stringFormatter;
    stringFormatter << std::setprecision(8) << std::noshowpoint << value;

    rowOfValues += stringFormatter.str() + " ";
  }
  
  return rowOfValues += "|";
}