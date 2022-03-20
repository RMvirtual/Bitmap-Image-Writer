#pragma once

#include <vector>

template <class T>
class MatrixRow
{
public:
  MatrixRow(int noOfColumns, const T& defaultValue);

  void set(const T& value, int columnIndex);
  void fill(const T& value);
  void fill(T* value);

  T at(int columnIndex) const;
  T& at(int columnIndex);
  T operator [](int index) const;
  T& operator [](int index);
  int size() const;

private:
  std::vector<T> columns;
};

template <class T>
MatrixRow<T>::MatrixRow(int noOfColumns, const T& defaultValue)
{
  this->columns = std::vector<T>(noOfColumns, defaultValue);
}

template <class T>
void MatrixRow<T>::set(const T& value, int index)
{
  this->columns[index] = value;
}

template <class T>
void MatrixRow<T>::fill(const T& value)
{
  /*
  auto noOfColumns = this->size();
  std::vector<std::thread> threads;

  auto columnReplacer = [](T* column, T& value) {
    *column = value;
  };

  for (int columnNo = 0; columnNo < noOfColumns; columnNo++) {
    T* column = &(this->columns[columnNo]);
    threads.emplace_back(columnReplacer, column, value);
  }

  for (auto& thread : threads) {
    thread.join();
  }
  */

  /*
  auto columnReplacer1 = [this](T* value) {
    for (auto& column : this->columns) {
      column = *value;
    }
  };

  auto valueCopy = value;
  T* valuePointer = &valueCopy;
  
  std::thread thread1(columnReplacer1, valuePointer);
  thread1.join();
  */

 auto size = this->columns.size();

  for (int i = 0; i < size; i++)
  {
    this->columns[i] = value;
  }
}

template <class T>
void MatrixRow<T>::fill(T* value)
{
  for (auto& column : this->columns) {
    column = *value;
  }
}

template <class T>
T MatrixRow<T>::at(int columnIndex) const
{
  return this->columns[columnIndex];
}

template <class T>
T& MatrixRow<T>::at(int columnIndex)
{
  return this->columns[columnIndex];
}

template <class T>
T MatrixRow<T>::operator[](int index) const
{
  return this->columns[index];
}

template <class T>
T& MatrixRow<T>::operator[](int index)
{
  return this->columns[index];
}

template <class T>
int MatrixRow<T>::size() const
{
  return this->columns.size();
}