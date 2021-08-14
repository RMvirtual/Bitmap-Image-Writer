#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include "src/maths/matrix/column.h"
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
      Matrix(Column column);

      /**
       * Returns a matrix populated with multiple columns of values.
       * All rows in the vector must be the same size or an arithmetic
       * error with throw.
       */
      Matrix(std::vector<Column> columns);

      // Returns the width (number of columns) of the matrix.
      int width();

      // Returns the height (number of rows) of the matrix.
      int height();

      // Indexes a row value from the column.
      Column operator [] (int index);

      Maths::Vector operator * (Maths::Vector vectorRhs);
      Matrix operator * (Matrix matrixRhs);

    private:
      std::vector<Column> columns;

      bool checkStlVectorIsValidMatrixSize(
        std::vector<std::vector<double>> vector);

      void convertStlVectorToColumns(std::vector<std::vector<double>> vector);
      bool isVectorCongruentSize(Maths::Vector vector);
  };
}

using namespace Maths;

Maths::Vector operator * (Maths::Vector vectorLhs, Matrix matrixRhs);

#endif