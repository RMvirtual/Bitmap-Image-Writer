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
  Matrix2D(int width, int height, const T& defaultValue);
  void set(const T& element, int rowNo, int columnNo);
  void set(const T& element, int index);
  T at(int rowNo, int columnNo) const;
  T at(int index) const;

private:
  int width;
  int height;
  std::vector<MatrixRow<T>> rows;

  int convertToIndex(int rowNo, int columnNo);
  bool isIndexOutOfBounds(int index);
};}

template <class T> Common::Matrix2D<T>::Matrix2D(
  int width, int height, const T& defaultValue)
{
  for (int rowNo = 0; rowNo < height; rowNo++) {
    auto newRow = MatrixRow<T> {width, defaultValue};
    this->rows.push_back(newRow);
  }

  this->width = width;
  this->height = height;  
}

template <class T> void Common::Matrix2D<T>::set(
  const T& value, int rowNo, int columnNo)
{
  this->rows.at(rowNo).set(value, columnNo);
}

template <class T> void Common::Matrix2D<T>::set(const T& value, int index)
{
  int rowNo = floor(index / this->width);
  int columnNo = index % this->width;

  this->set(value, rowNo, columnNo);
}

template <class T> T Common::Matrix2D<T>::at(int rowNo, int columnIndex) const
{
  return this->rows.at(rowNo).at(columnIndex);
}

template <class T> T Common::Matrix2D<T>::at(int indexNo) const
{
  int rowNo = floor(indexNo / this->width);
  int columnNo = indexNo % this->width;

  return this->at(rowNo, columnNo);
}

#endif