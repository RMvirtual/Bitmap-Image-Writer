#ifndef MATRIX_2D_H
#define MATRIX_2D_H

#include <vector>
#include <cmath>

#include "src/common/matrix-2d/matrix_row.h"

namespace Common {
template <class T>
class Matrix2D
{
public:
  Matrix2D(int width, int height, T defaultValue);
  void set(T element, int rowNo, int columnNo);
  T at(int rowNo, int columnNo);
  T at(int index);

private:
  int width;
  int height;
  std::vector<MatrixRow<T>> rows;

  int convertToIndex(int rowNo, int columnNo);
  bool isIndexOutOfBounds(int index);
};}

template <class T> Common::Matrix2D<T>::Matrix2D(
  int width, int height, T defaultValue)
{
  for (int rowNo = 0; rowNo < height; rowNo++) {
    auto newRow = MatrixRow<T> {width, defaultValue};
    this->rows.push_back(newRow);
  }

  this->width = width;
  this->height = height;  
}

template <class T> void Common::Matrix2D<T>::set(
  T value, int rowNo, int columnNo)
{
  this->rows.at(rowNo).set(value, columnNo);
}

template <class T> T Common::Matrix2D<T>::at(int rowNo, int columnIndex)
{
  return this->rows.at(rowNo).at(columnIndex);
}

template <class T> T Common::Matrix2D<T>::at(int indexNo)
{
  int rowNo = floor(indexNo / this->width);
  int columnNo = indexNo % this->width;

  return this->at(rowNo, columnNo);
}


#endif