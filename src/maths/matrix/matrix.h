#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include "src/maths/vector/vector.h"

using namespace std;

namespace Maths
{
  class Matrix
  {
    public:
      // Returns an empty matrix.
      Matrix();

      // Returns a matrix populated with one column of values.
      Matrix(vector<double> columnValues);
      
      /**
       * Returns a matrix populated with multiple columns of values.
       * All rows in the vector must be the same size or an arithmetic
       * error with throw.
       */
      Matrix(vector<vector<double>> columns);

      // Returns the width (number of columns) of the matrix.
      int width();

      // Returns the height (number of rows) of the matrix.
      int height();

      // Returns an stl vector containing the values of a specific row.
      vector<double> getRow(int index);

      // Returns an stl vector containing the values of a specific column.
      vector<double> getColumn(int index);

      /**
       * Returns a 2D stl vector containing single vectors all the
       * values of the entire matrix sorted into vertical order (i.e.
       * each vector contains the values found in all the rows of a
       * single column).
       */
      vector<vector<double>> getColumns();
      
      /**
       * Returns a 2D stl vector containing single vectors of all the
       * values of the entire matrix sorted into horizontal order
       * (i.e. each vector contains the values found in all the columns
       * of single row).
       */
      vector<vector<double>> getRows();

      /**
       * Indexes an stl vector representing a column of values (can be
       * indexed again using the subscript operator to get the actual
       * row value.
       */
      vector<double> operator [] (int index);

      // Multiplies the matrix by a vector.
      Maths::Vector operator * (Maths::Vector vectorRhs);

      // Multiplies the matrix by another matrix.
      Matrix operator * (Matrix matrixRhs);

      /**
       * Returns all the values of this matrix formatted as a string.
       * Follows the format:
       * 
       * | 1 4 7 |
       * | 2 5 8 |
       * | 3 6 9 |
       */
      string toString();

    private:
      vector<vector<double>> columns;

      // Multiplies a vector against this matrix.
      Maths::Vector multiplyVector(Maths::Vector vector);
      
      /**
       * Returns an stl vector of the values required to instantiate a
       * Maths::Vector class object.
       */
      std::vector<double> getMultipliedVectorValues(Maths::Vector vector);
      
      // Multiplies another matrix against this matrix.
      Matrix multiplyMatrix(Matrix matrix);
      
      /**
       * Returns a 2D stl vector of the values required to populate
       * the columns and rows of a new matrix object resulting from
       * the multiplication of two other matrices.
       */
      vector<vector<double>> getValuesFromMatrixMultiplication(
        Matrix matrix);

      /**
       * Calculates the product of all row values against the values
       * found in an stl vector representing a column of values.
       */
      vector<double> getProductAgainstAllRowsWithColumn(
        vector<double> column);

      // Calculates the product between two vectors.
      double getProductBetweenTwoVectors(
        std::vector<double> vector1, std::vector<double> vector2);

      // Calculates the product between two vectors.
      double getProductBetweenTwoVectors(
        std::vector<double> vector1, Maths::Vector vector2);
      
      // Calculates the product between two vectors.
      double getProductBetweenTwoVectors(
        Maths::Vector vector1, std::vector<double> vector2);

      /**
       * Calculates the product between two items found at the same
       * index in two different vectors.
       */
      double getProductBetweenTwoVectorsAtSameIndex(
        vector<double> vector1, vector<double> vector2,
        int commonIndex
      );

      /**
       * Calculates the product between two items found at the same
       * index in two different vectors.
       */
      double getProductBetweenTwoVectorsAtSameIndex(
        std::vector<double> vector1, Maths::Vector vector2,
        int commonIndex
      );

      /**
       * Calculates the product between two items found at the same
       * index in two different vectors.
       */
      double getProductBetweenTwoVectorsAtSameIndex(
        Maths::Vector vector1, vector<double> vector2,
        int commonIndex
      );

      /**
       * Takes a 2D stl vector and converts it into the matrix's
       * values, assuming the outer vector as a container for the
       * columns, and the inner vectors to represent columns containing
       * the actual row values.
       */
      void setVectorAsColumnsAndRows(vector<vector<double>> vector);
      
      /**
       * Checks that a 2D stl vector follows the valid width and
       * height dimensions required to be processed into the matrix's
       * contents.
       */
      bool checkVectorIsValidMatrixSize(vector<vector<double>> vector);
        
      /**
       * Checks whether a Maths::Vector object has the correct
       * dimensions to be used in a multiplication operation against
       * this matrix.
       */
      bool isVectorMultipliable(Maths::Vector vector);
      
      /**
       * Checks whether another Matrix object has the correct
       * dimensions to be used in a multiplication operation against
       * this matrix.
       */
      bool isMatrixMultipliable(Matrix matrix);
      
      /**
       * Returns all the values of this matrix formatted as a string.
       * Follows the format:
       * 
       * | 1 4 7 |
       * | 2 5 8 |
       * | 3 6 9 |
       */
      string getAllValuesAsString();

      /**
       * Returns a vector of values formatted as a string representing
       * a matrix row in the format:
       * 
       * | 1 4 7 |
       */
      string formatStlVectorAsMatrixRow(vector<double> vector);
  };
}

// Multiplies the matrix by a vector.
Maths::Vector operator * (Maths::Vector vectorLhs, Matrix matrixRhs);

#endif