#ifndef MATRIX_ROW_H
#define MATRIX_ROW_H

#include <vector>

namespace Common {
template <class T>
class MatrixRow
{
public:
  MatrixRow(int maxColumns, T defaultValue);

  void set(T value, int columnIndex);
  T at(int columnIndex);
  int size();

private:
  std::vector<T> columns;
};}

template <class T>
Common::MatrixRow<T>::MatrixRow(int noOfColumns, T defaultValue)
{
  for (int columnNo = 0; columnNo < noOfColumns; columnNo++)
    this->columns.push_back(defaultValue);
}

template <class T>
void Common::MatrixRow<T>::set(T value, int columnIndex)
{
  this->columns.at(columnIndex) = value;
}

template <class T>
T Common::MatrixRow<T>::at(int columnIndex)
{
  return this->columns.at(columnIndex);
}

template <class T>
int Common::MatrixRow<T>::size()
{
  return this->columns.size();
}

#endif