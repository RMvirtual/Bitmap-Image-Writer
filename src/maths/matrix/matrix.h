#include "src/common/arrays.h"

namespace Maths
{
  class Matrix
  {
    public:
      Matrix(ArrayList<ArrayList<double>> arraylist);
      
      int width();
      int height();

      double operator [] (int index);

      class Column
      {
        public:
          Column(double* columnArray, int length);
          Column();
          
          double operator [] (int index);

        private:
          double* values;
          int length;
      };

    private:
      int matrixWidth;
      int matrixHeight;
      Column* columns;
  };
}