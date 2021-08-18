#ifndef MATRIX_COLUMN_H
#define MATRIX_COLUMN_H

#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

namespace Maths
{
  template <long FROM, long TO>
  class Column
  {
  public:
    Column(std::vector<double> vector);
    double operator[](int index);
    int size();
    vector<double> toVector();

    class iterator : public std::iterator<
      std::input_iterator_tag,
      double,
      double,
      const double *,
      double
    >
    {
      long num = FROM;

      public:
        explicit iterator(long _num = 0) : num(_num) {};
        iterator& operator++() {
          num = TO >= FROM ? num + 1 : num -1; return *this;
        }

        iterator operator ++ (int) {
          iterator retval = *this; ++(*this); return retval;
        }

        bool operator == (iterator other) const {
          return num == other.num;
        }

        bool operator != (iterator other) const {
          return !(*this == other);
        }

        reference operator * () const {
          return num;
        }
    };

    iterator begin() {return iterator(FROM);}
    iterator end() {return iterator(TO >= FROM? TO + 1 : TO-1;)}    

  private:
    vector<double> vector;
  };
}

#endif