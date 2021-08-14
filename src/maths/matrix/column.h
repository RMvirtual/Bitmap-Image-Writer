#ifndef COLUMN_H
#define COLUMN_H

#include <vector>

namespace Maths
{
  class Column
  {
    public:
      Column();
      Column(std::vector<double>);
      Column(double* columnArray, int length);
      
      double operator [] (int index);
      
      int length();

    private:
      std::vector<double> rows;
  };
}

#endif