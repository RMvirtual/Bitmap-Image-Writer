#pragma once

#include <thread>
#include <cmath>
#include <vector>

#include "src/main/cpp/containers/index.h"
#include "src/main/cpp/containers/matrix-2d/matrix_row.h"

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
  MatrixRow<T>& operator [](int rowNo);
  MatrixRow<T> operator [](int rowNo) const;
  int width() const;
  int height() const;

private:
  int _width;
  int _height;
  std::vector<MatrixRow<T>> rows;

  Index matrixIndex(int absoluteIndex) const;
  int absoluteIndex(const Index& matrixIndex) const;
};

template <class T>
Matrix2D<T>::Matrix2D(int width, int height, const T& defaultValue)
{
  this->rows = std::vector<MatrixRow<T>>(height, {width, defaultValue});
 
  this->_width = width;
  this->_height = height;  
}

template <class T>
void Matrix2D<T>::set(const T& value, int rowNo, int columnNo)
{
  this->rows[rowNo][columnNo] = value;
}

template <class T>
void Matrix2D<T>::set(const T& value, int index)
{
  int rowNo = floor(index / this->_width);
  int columnNo = index % this->_width;

  this->rows[rowNo][columnNo] = value;
}

template <class T>
void Matrix2D<T>::fill(const T& value)
{
  auto noOfRows = this->height();
  std::vector<std::thread> threads;

  auto rowFiller = [](MatrixRow<T>* row, T value) {
    row->fill(value);
  };

  for (int rowNo = 0; rowNo < noOfRows; rowNo++) {
    MatrixRow<T>& matrixRow = this->rows[rowNo];
    threads.emplace_back(rowFiller, &matrixRow, value);
  }

  for (auto& thread : threads) {
    thread.join();
  }

  // std::fill(this->rows.begin(), this->rows.end(), row); // appears to bottleneck here.
}

template <class T>
T& Matrix2D<T>::at(int row, int column)
{
  return this->rows[row][column];
}

template <class T>
T Matrix2D<T>::at(int row, int column) const
{
  return this->rows[row][column];
}

template <class T>
T& Matrix2D<T>::at(int absoluteIndex)
{
  auto index = this->matrixIndex(absoluteIndex);

  return this->at(index);
}

template <class T>
T Matrix2D<T>::at(int absoluteIndex) const
{
  auto index = this->matrixIndex(absoluteIndex);

  return this->at(index);
}

template <class T>
T& Matrix2D<T>::at(const Index& index)
{
  return this->rows[index.row][index.column];
}

template <class T>
T Matrix2D<T>::at(const Index& index) const
{
  return this->rows[index.row][index.column];
}

template <class T>
MatrixRow<T>& Matrix2D<T>::operator [](int rowNo)
{
  return this->rows[rowNo]; 
}

template <class T>
MatrixRow<T> Matrix2D<T>::operator [](int rowNo) const
{
  return this->rows[rowNo]; 
}

template <class T>
int Matrix2D<T>::height() const
{
  return this->_height;
}

template <class T>
int Matrix2D<T>::width() const
{
  return this->_width;
}

template <class T>
Index Matrix2D<T>::matrixIndex(int absoluteIndex) const
{
  Index index {};
  index.row = floor(absoluteIndex / this->_width);
  index.column = absoluteIndex % this->_width;

  return index;
}

template <class T>
int Matrix2D<T>::absoluteIndex(const Index& matrixIndex) const
{
  return (matrixIndex.row * this->_width) + matrixIndex.column;
}