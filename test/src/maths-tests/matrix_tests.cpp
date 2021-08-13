#include <gtest/gtest.h>
#include <iostream>
#include "src/maths/matrix/matrix.h"

using namespace Maths;

TEST(MatrixTests, ShouldCreateMatrix)
{
  ArrayList<ArrayList<double>> arraylist2d
    = ArrayList<ArrayList<double>>();

  ArrayList<double> firstColumn = ArrayList<double>();
  firstColumn.add(0);
  firstColumn.add(1);

  ArrayList<double> secondColumn = ArrayList<double>();
  secondColumn.add(2);
  secondColumn.add(3);

  arraylist2d.add(firstColumn);
  arraylist2d.add(secondColumn);

  Matrix* matrix = new Matrix(arraylist2d);
  double doubleToTest = matrix[1][1];

  EXPECT_DOUBLE_EQ(3, doubleToTest);
}