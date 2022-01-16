#ifndef MATRIX_ROW_H
#define MATRIX_ROW_H

#include <vector>

namespace Common {
template <class T>
class MatrixRow
{
public:
  MatrixRow(int maxColumns, const T& defaultValue);

  void set(const T& value, int columnIndex);
  T at(int columnIndex) const;
  T operator [](int index) const;
  int size() const;

private:
  std::vector<T> columns;
};}

template <class T>
Common::MatrixRow<T>::MatrixRow(int noOfColumns, const T& defaultValue)
{
  for (int columnNo = 0; columnNo < noOfColumns; columnNo++)
    this->columns.push_back(defaultValue);
}

template <class T>
void Common::MatrixRow<T>::set(const T& value, int columnIndex)
{
  this->columns.at(columnIndex) = value;
}

template <class T>
T Common::MatrixRow<T>::at(int columnIndex) const
{
  return this->columns.at(columnIndex);
}

template <class T>
T Common::MatrixRow<T>::operator[](int index) const
{
  return this->at(index);
}

template <class T>
int Common::MatrixRow<T>::size() const
{
  return this->columns.size();
}

#endif