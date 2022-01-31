#ifndef MATRIX_ROW_H
#define MATRIX_ROW_H

#include <vector>

namespace Common {
template <class T>
class MatrixRow
{
public:
  MatrixRow(int noOfColumns, const T& defaultValue);

  void set(const T& value, int columnIndex);
  void fill(const T& value);
  T at(int columnIndex) const;
  T& at(int columnIndex);
  T operator [](int index) const;
  T& operator [](int index);
  int size() const;

private:
  std::vector<T> columns;
};}

template <class T>
Common::MatrixRow<T>::MatrixRow(int noOfColumns, const T& defaultValue)
{
  this->columns = std::vector<T>(noOfColumns, defaultValue);
}

template <class T>
void Common::MatrixRow<T>::set(const T& value, int columnIndex)
{
  this->columns.at(columnIndex) = value;
}

template <class T>
void Common::MatrixRow<T>::fill(const T& value)
{
  std::fill(this->columns.begin(), this->columns.end(), value);
}

template <class T>
T Common::MatrixRow<T>::at(int columnIndex) const
{
  return this->columns.at(columnIndex);
}

template <class T>
T& Common::MatrixRow<T>::at(int columnIndex)
{
  return this->columns.at(columnIndex);
}

template <class T>
T Common::MatrixRow<T>::operator[](int index) const
{
  return this->at(index);
}

template <class T>
T& Common::MatrixRow<T>::operator[](int index)
{
  return this->at(index);
}

template <class T>
int Common::MatrixRow<T>::size() const
{
  return this->columns.size();
}

#endif