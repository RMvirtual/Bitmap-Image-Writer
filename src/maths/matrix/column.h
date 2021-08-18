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
    vector<double> toVector();

    std::vector<double>::iterator begin() {return values.begin();}
    std::vector<double>::iterator end() {return values.end();}

    std::vector<double>::const_iterator begin() const {return values.begin();}
    std::vector<double>::const_iterator end() const {return values.end();}

  private:
    vector<double> values;
  };
}

#endif