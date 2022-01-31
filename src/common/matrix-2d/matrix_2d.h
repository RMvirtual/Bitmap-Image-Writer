#ifndef MATRIX_2D_H
#define MATRIX_2D_H

#include <cmath>
#include <vector>

#include "src/common/index.h"
#include "src/common/matrix-2d/matrix_row.h"

namespace Common {
template <class T>
class Matrix2D
{
public:
  Matrix2D(int width, int height, const T& defaultValue);
  
  void set(const T& element, int rowNo, int columnNo);
  void set(const T& element, int index);
  void fill(const T& element);

  T& at(const Index& index);
  T at(const Index& index) const;
  T& at(int rowNo, int columnNo);
  T at(int rowNo, int columnNo) const;
  T& at(int index);
  T at(int index) const;
  MatrixRow<T> operator [](int rowNo);
  int width() const;
  int height() const;

private:
  int _width;
  int _height;
  std::vector<MatrixRow<T>> rows;

  Index matrixIndex(int absoluteIndex) const;
  int absoluteIndex(const Index& matrixIndex) const;
};}

template <class T>
Common::Matrix2D<T>::Matrix2D(int width, int height, const T& defaultValue)
{
  for (int rowNo = 0; rowNo < height; rowNo++)
    this->rows.push_back({width, defaultValue});

  this->_width = width;
  this->_height = height;  
}

template <class T>
void Common::Matrix2D<T>::set(const T& value, int rowNo, int columnNo)
{
  this->rows.at(rowNo).set(value, columnNo);
}

template <class T>
void Common::Matrix2D<T>::set(const T& value, int index)
{
  int rowNo = floor(index / this->_width);
  int columnNo = index % this->_width;

  this->set(value, rowNo, columnNo);
}

template <class T>
void Common::Matrix2D<T>::fill(const T& value)
{
  for (auto row : this->rows)
    row.fill(value);
}

template <class T>
T Common::Matrix2D<T>::at(int rowNo, int columnIndex) const
{
  return this->rows.at(rowNo).at(columnIndex);
}

template <class T>
T Common::Matrix2D<T>::at(int absoluteIndex) const
{
  auto index = this->matrixIndex(absoluteIndex);

  return this->at(index);
}

template <class T>
T Common::Matrix2D<T>::at(const Common::Index& index) const
{
  return this->at(index.row, index.column);
}

template <class T>
T& Common::Matrix2D<T>::at(int rowNo, int columnIndex)
{
  return this->rows.at(rowNo).at(columnIndex);
}

template <class T>
T& Common::Matrix2D<T>::at(int absoluteIndex)
{
  auto index = this->matrixIndex(absoluteIndex);

  return this->at(index);
}

template <class T>
T& Common::Matrix2D<T>::at(const Common::Index& index)
{
  return this->at(index.row, index.column);
}

template <class T>
Common::MatrixRow<T> Common::Matrix2D<T>::operator [](int rowNo)
{
  return this->rows[rowNo]; 
}

template <class T>
int Common::Matrix2D<T>::height() const
{
  return this->_height;
}

template <class T>
int Common::Matrix2D<T>::width() const
{
  return this->_width;
}

template <class T>
Common::Index Common::Matrix2D<T>::matrixIndex(int absoluteIndex) const
{
  Common::Index index {};
  index.row = floor(absoluteIndex / this->_width);
  index.column = absoluteIndex % this->_width;

  return index;
}

template <class T>
int Common::Matrix2D<T>::absoluteIndex(const Common::Index& matrixIndex) const
{
  return ((matrixIndex.row * this->_width) + matrixIndex.column);
}

#endif