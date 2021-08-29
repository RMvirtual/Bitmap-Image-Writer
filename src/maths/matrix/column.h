#ifndef MATRIX_COLUMN_H
#define MATRIX_COLUMN_H

#include <algorithm>
#include <iterator>
#include <vector>

namespace Maths
{
  // A class representing a vertical column of values in a Matrix.
  class Column
  {
  public:
    // Returns a new column of matrix values.
    Column(std::vector<double> vector);

    // Returns a value from a column row.
    double operator[](int index);

    // Returns the number of rows in the column.
    int size();

    // Returns an iterator at the start of the column's values.
    std::vector<double>::iterator begin();

    // Returns an iterator at the end of the column's values.
    std::vector<double>::iterator end();

    // Returns a constant iterator at the start of the column's values.
    std::vector<double>::const_iterator begin() const;
    
    // Returns a constant iterator at the end of the column's values.
    std::vector<double>::const_iterator end() const;

  private:
    std::vector<double> values;
  };
}

#endif