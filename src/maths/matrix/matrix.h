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

      // Returns a formatted string representation of the matrix.
      string toString();

    private:
      vector<vector<double>> columns;

      Maths::Vector multiplyVector(Maths::Vector vector);
      Matrix multiplyMatrix(Matrix matrix);
      
      vector<vector<double>> getValuesFromMatrixMultiplication(
        Matrix matrix);

      vector<double> getProductAgainstAllRowsWithColumn(
        vector<double> column);

      double getProductBetweenTwoStlVectors(
        vector<double> vector1, vector<double> vector2);

      double getProductBetweenTwoStlVectorsAtSameIndex(
        vector<double> vector1, vector<double> vector2,
        int commonIndex
      );
      
      void convert2DStlVectorToColumns(
        vector<vector<double>> vector);

      bool check2DStlVectorIsValidMatrixSize(
        vector<vector<double>> vector);
        
      bool isVectorMultipliable(Maths::Vector vector);
      bool isMatrixMultipliable(Matrix matrix);
      string getAllValuesAsString();
      string formatStlVectorAsMatrixRow(vector<double> vector);
  };
}

// Multiplies the matrix by a vector.
Maths::Vector operator * (Maths::Vector vectorLhs, Matrix matrixRhs);

#endif