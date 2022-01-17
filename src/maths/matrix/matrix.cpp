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
  this->_columns = {};
}

Maths::Matrix::Matrix(const std::vector<double>& column)
{
  this->_columns = {Maths::Column(column)};
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
    this->_columns.push_back(Maths::Column(vector));
}

int Maths::Matrix::width() const
{
  return this->_columns.size();
}

int Maths::Matrix::height() const
{
  return this->_columns.size() ? this->_columns.front().size() : 0;
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

std::vector<double> Maths::Matrix::column(int index) const
{
  std::vector<double> columnValues = {};
  Maths::Column column = (*this)[index];

  for (auto value : column)
    columnValues.push_back(value);

  return columnValues;
}

std::vector<double> Maths::Matrix::row(int index) const
{
  std::vector<double> rowValues = {};

  for (auto column : this->_columns)
    rowValues.push_back(column[index]);

  return rowValues;
}

std::vector<std::vector<double>> Maths::Matrix::columns() const
{
  std::vector<std::vector<double>> columns = {};

  for (int columnNo = 0; columnNo < this->width(); columnNo++)
    columns.push_back(this->column(columnNo));

  return columns;
}

std::vector<std::vector<double>> Maths::Matrix::rows() const
{
  std::vector<std::vector<double>> rows = {};

  for (int rowNo = 0; rowNo < this->height(); rowNo++)
    rows.push_back(this->row(rowNo));

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

  for (auto row : this->rows())
    newVectorValues.push_back(this->product(row, vector));

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
  
  for (auto column : matrixToMultiply.columns())
    newMatrixValues.push_back(this->getProductAgainstAllRows(column));

  return newMatrixValues;
}

std::vector<double> Maths::Matrix::getProductAgainstAllRows(
  const std::vector<double>& column) const
{
  std::vector<double> newColumn = {};

  for (auto row : this->rows())
    newColumn.push_back(this->product(row, column));

  return newColumn; 
}

double Maths::Matrix::product(
  const std::vector<double>& vector1, const std::vector<double>& vector2) const
{
  double totalProduct = 0;
  int noOfValues = vector1.size();

  for (int commonIndex = 0; commonIndex < noOfValues; commonIndex++)
    totalProduct += this->product(vector1, vector2, commonIndex);

  return totalProduct;
}

double Maths::Matrix::product(
  const std::vector<double>& vector1, const Maths::Vector& vector2) const
{
  double totalProduct = 0;
  int noOfValues = vector1.size();

  for (int commonIndex = 0; commonIndex < noOfValues; commonIndex++)
    totalProduct += this->product(vector1, vector2, commonIndex);

  return totalProduct;
}

double Maths::Matrix::product(
  const Maths::Vector& vector1, const std::vector<double>& vector2) const
{
  return this->product(vector2, vector1);
}

double Maths::Matrix::product(
  const std::vector<double>& vector1, const std::vector<double>& vector2,
  int commonIndex) const
{
  return vector1[commonIndex] * vector2[commonIndex];
}

double Maths::Matrix::product(
  const std::vector<double>& vector1, const Maths::Vector& vector2,
  int commonIndex) const
{
  return vector1[commonIndex] * vector2[commonIndex];
}

double Maths::Matrix::product(
  const Maths::Vector& vector1, const std::vector<double>& vector2,
  int commonIndex) const
{
  return this->product(vector2, vector1, commonIndex);
}

Maths::Column Maths::Matrix::operator [] (int columnIndex) const
{
  return this->isColumnIndexInRange(columnIndex) ?
    this->_columns[columnIndex] :
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

  auto rows = this->rows();
  int noOfRows = rows.size();

  for (int rowNo = 0; rowNo < noOfRows; rowNo++) {
    auto row = rows[rowNo];
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