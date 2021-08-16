#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include "src/maths/vector/vector.h"

namespace Maths
{
  class Matrix
  {
    public:
      // Returns an empty matrix to populate.
      Matrix();

      // Returns a matrix populated with one column of values.
      Matrix(std::vector<double> columnValues);
      
      /**
       * Returns a matrix populated with multiple columns of values.
       * All rows in the vector must be the same size or an arithmetic
       * error with throw.
       */
      Matrix(std::vector<std::vector<double>> columns);

      // Returns the width (number of columns) of the matrix.
      int width();

      // Returns the height (number of rows) of the matrix.
      int height();

      // Returns an stl vector containing the values of a specific row.
      std::vector<double> getRow(int index);

      // Returns an stl vector containing the values of a specific column.
      std::vector<double> getColumn(int index);

      /**
       * Returns a 2D stl vector containing single vectors all the
       * values of the entire matrix sorted into vertical order (i.e.
       * each vector contains the values found in all the rows of a
       * single column).
       */
      std::vector<std::vector<double>> getColumns();
      
      /**
       * Returns a 2D stl vector containing single vectors of all the
       * values of the entire matrix sorted into horizontal order
       * (i.e. each vector contains the values found in all the columns
       * of single row).
       */
      std::vector<std::vector<double>> getRows();

      /**
       * Indexes an stl vector representing a column of values (can be
       * indexed again using the subscript operator to get the actual
       * row value.
       */
      std::vector<double> operator [] (int index);

      // Multiplies the matrix by a vector.
      Maths::Vector operator * (Maths::Vector vectorRhs);

      // Multiplies the matrix by another matrix.
      Matrix operator * (Matrix matrixRhs);

      // Returns a formatted string representation of the matrix.
      string toString();

    private:
      std::vector<std::vector<double>> columns;

      Matrix multiplyMatrix(Matrix matrix);
      
      std::vector<std::vector<double>> getValuesFromMatrixMultiplication(
        Matrix matrix);

      std::vector<double> getProductAgainstAllRowsWithColumn(
        std::vector<double> column);

      double getProductBetweenTwoStlVectors(
        std::vector<double> vector1, std::vector<double> vector2);

      double getProductBetweenTwoStlVectorsAtSameIndex(
        std::vector<double> vector1, std::vector<double> vector2,
        int commonIndex
      );
      
      void convert2DStlVectorToColumns(
        std::vector<std::vector<double>> vector);

      bool check2DStlVectorIsValidMatrixSize(
        std::vector<std::vector<double>> vector);
        
      bool isVectorMultipliable(Maths::Vector vector);
      bool isMatrixMultipliable(Matrix matrix);
      string getAllValuesAsString();
      string formatStlVectorAsMatrixRow(std::vector<double> vector);
  };
}

using namespace Maths;

// Multiplies the matrix by a vector.
Maths::Vector operator * (Maths::Vector vectorLhs, Matrix matrixRhs);

#endif