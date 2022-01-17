#ifndef MATRIX_H
#define MATRIX_H

#include <vector>

#include "src/maths/matrix/column.h"
#include "src/maths/vector/vector.h"

namespace Maths {
class Matrix
{
public:
  // Returns an empty matrix.
  Matrix();

  // Returns a matrix populated with one column of values.
  Matrix(const std::vector<double>& columnValues);
  
  /**
   * Returns a matrix populated with multiple columns of values.
   * All rows in the vector must be the same size or an arithmetic
   * error with throw.
   */
  Matrix(const std::vector<std::vector<double>>& columns);

  // Returns the width (number of columns) of the matrix.
  int width() const;

  // Returns the height (number of rows) of the matrix.
  int height() const;

  // Returns the values of a specific row.
  std::vector<double> row(int index) const;

  // Returns the values of a specific column.
  std::vector<double> column(int index) const;

  /**
   * Returns a 2D stl vector containing single vectors all the
   * values of the entire matrix sorted into vertical order (i.e.
   * each vector contains the values found in all the rows of a
   * single column).
   */
  std::vector<std::vector<double>> columns() const;
  
  /**
   * Returns a 2D stl vector containing single vectors of all the
   * values of the entire matrix sorted into horizontal order
   * (i.e. each vector contains the values found in all the columns
   * of single row).
   */
  std::vector<std::vector<double>> rows() const;

  /**
   * Returns a Column Proxy object that extends an stl vector
   * representing a column of values (can be indexed again using
   * the subscript operator to get the actual row value.
   */
  Column operator [](int columnIndex) const;

  // Multiplies the matrix by a vector.
  Vector operator *(const Maths::Vector& vectorRhs) const;

  // Multiplies the matrix by another matrix.
  Matrix operator *(const Matrix& matrixRhs) const;

  /**
   * Returns all the values of this matrix formatted as a string.
   * Follows the format:
   * 
   * | 1 4 7 |
   * | 2 5 8 |
   * | 3 6 9 |
   */
  std::string toString() const;

private:
  std::vector<Column> _columns;

  /**
   * Multiplies a vector against this matrix.
   */
  Maths::Vector multiplyVector(const Maths::Vector& vector) const;
  
  /**
   * Returns an stl vector of the values required to instantiate a
   * Maths::Vector class object.
   */
  std::vector<double> getMultipliedVectorValues(
    const Maths::Vector& vector) const;
  
  /**
   * Multiplies another matrix against this matrix.
   */
  Matrix multiplyMatrix(const Matrix& matrix) const; 
  
  /**
   * Returns a 2D stl vector of the values required to populate
   * the columns and rows of a new matrix object resulting from
   * the multiplication of two other matrices.
   */
  std::vector<std::vector<double>> getValuesFromMultiplication(
    const Matrix& matrix) const;

  /**
   * Calculates the product of all row values against the values
   * found in an stl vector representing a column of values.
   */
  std::vector<double> getProductAgainstAllRows(
    const std::vector<double>& column) const;

  /**
   * Calculates the product between two vectors.
   */
  double product(
    const std::vector<double>& vector1,
    const std::vector<double>& vector2) const;

  /**
   * Calculates the product between two vectors.
   */
  double product(
    const std::vector<double>& vector1,
    const Vector& vector2) const;
  
  /**
   * Calculates the product between two vectors.
   */
  double product(
    const Vector& vector1,
    const std::vector<double>& vector2) const;

  /**
   * Calculates the product between two items found at the same
   * index in two different vectors.
   */
  double product(
    const std::vector<double>& vector1,
    const std::vector<double>& vector2,
    int commonIndex) const;

  /**
   * Calculates the product between two items found at the same
   * index in two different vectors.
   */
  double product(
    const std::vector<double>& vector1, const Vector& vector2,
    int commonIndex) const;

  /**
   * Calculates the product between two items found at the same
   * index in two different vectors.
   */
  double product(
    const Vector& vector1, const std::vector<double>& vector2,
    int commonIndex
  ) const;

  /**
   * Takes a 2D stl vector and converts it into the matrix's
   * values, assuming the outer vector as a container for the
   * columns, and the inner vectors to represent columns containing
   * the actual row values.
   */
  void from2DVector(const std::vector<std::vector<double>>& vector);
  
  /**
   * Checks that a 2D stl vector follows the valid width and
   * height dimensions required to be processed into the matrix's
   * contents.
   */
  bool isVectorValidSize(
    const std::vector<std::vector<double>>& vector) const;

  /**
   * Checks whether a Maths::Vector object has the correct
   * dimensions to be used in a multiplication operation against
   * this matrix.
   */
  bool isVectorMultipliable(const Vector& vector) const;
  
  /**
   * Checks whether another Matrix object has the correct
   * dimensions to be used in a multiplication operation against
   * this matrix.
   */
  bool isMatrixMultipliable(const Matrix& matrix) const;

  bool isColumnIndexInRange(int columnIndex) const;

  /**
   * Returns a vector of values formatted as a string representing
   * a matrix row in the format:
   * 
   * | 1 4 7 |
   */
  std::string transposeToMatrixRow(const std::vector<double>& vector) const;
};}

/**
 * Multiplies the matrix by a vector.
 */
Maths::Vector operator *(
  const Maths::Vector& vector, const Maths::Matrix& matrix);

#endif