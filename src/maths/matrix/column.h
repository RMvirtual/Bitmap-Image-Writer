#ifndef MATRIX_COLUMN_H
#define MATRIX_COLUMN_H

#include <iterator>
#include <vector>

using namespace std;

namespace Maths{
  class Column
  {
    public:
      Column(std::vector<double> vector);
      double operator[](int index);
      int size();
      vector<double> toVector();
      
    private:
      vector<double> vector;
  };
}

#endif