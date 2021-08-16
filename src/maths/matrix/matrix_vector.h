#ifndef MATRIX_COLUMN_H
#define MATRIX_COLUMN_H

#include <vector>

namespace Maths
{
  class MatrixVector
  {
    public:
      MatrixVector();
      MatrixVector(std::vector<double>);
      MatrixVector(double* columnArray, int length);
      
      double operator [] (int index);
      
      int length();

    private:
      std::vector<double> values;
  };
}

#endif