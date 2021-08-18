#ifndef MATRIX_COLUMN_H
#define MATRIX_COLUMN_H

#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

namespace Maths
{
  class Column
  {
  public:
    Column(std::vector<double> vector);
    double operator[](int index);
    int size();

    std::vector<double>::iterator begin();
    std::vector<double>::iterator end();
    std::vector<double>::const_iterator begin() const;
    std::vector<double>::const_iterator end() const;

  private:
    vector<double> values;
  };
}

#endif