#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include "src/maths/matrix/matrix_vector.h"
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

      // Returns a matrix populated with one column of values.
      Matrix(MatrixVector column);

      /**
       * Returns a matrix populated with multiple columns of values.
       * All rows in the vector must be the same size or an arithmetic
       * error with throw.
       */
      Matrix(std::vector<MatrixVector> columns);

      // Returns the width (number of columns) of the matrix.
      int width();

      // Returns the height (number of rows) of the matrix.
      int height();

      std::vector<double> getRow(int index);
      std::vector<double> getColumn(int index);
      std::vector<std::vector<double>> getColumnTuples();
      std::vector<std::vector<double>> getRowTuples();

      // Indexes a row value from the column.
      MatrixVector operator [] (int index);

      Maths::Vector operator * (Maths::Vector vectorRhs);
      Matrix operator * (Matrix matrixRhs);

      string toString();

    private:
      std::vector<MatrixVector> columns;

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
      
      void convertStlVectorToColumns(std::vector<std::vector<double>> vector);

      bool checkStlVectorIsValidMatrixSize(
        std::vector<std::vector<double>> vector);
        
      bool isVectorMultipliable(Maths::Vector vector);
      bool isMatrixMultipliable(Matrix matrix);
      string getAllValuesAsString();
      string formatStlVectorAsMatrixRow(std::vector<double> vector);
      string getValueAsString(int columnNo, int rowNo);
  };
}

using namespace Maths;

Maths::Vector operator * (Maths::Vector vectorLhs, Matrix matrixRhs);

#endif