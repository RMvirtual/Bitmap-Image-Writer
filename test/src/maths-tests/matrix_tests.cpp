#include <gtest/gtest.h>
#include <vector>
#include <iostream>
#include "src/maths/matrix/matrix.h"

using namespace Maths;
using namespace std;

TEST(MatrixTests, ShouldCreateMatrixFrom2DVector)
{
  vector<vector<double>> vector2D
    = vector<vector<double>>();

  vector<double> firstColumn = {1, 2, 3, 4};
  vector<double> secondColumn = {5, 6, 7, 8};

  vector2D.push_back(firstColumn);
  vector2D.push_back(secondColumn);

  Matrix matrix = Matrix(vector2D);
  double doubleToTest = matrix[1][1];

  EXPECT_DOUBLE_EQ(6, doubleToTest);
}

TEST(MatrixTests, ShouldReturnWidthAsTwo)
{
  vector<vector<double>> vector2D
    = vector<vector<double>>();

  vector<double> firstColumn = {1, 2, 3, 4};
  vector<double> secondColumn = {5, 6, 7, 8};

  vector2D.push_back(firstColumn);
  vector2D.push_back(secondColumn);

  Matrix matrix = Matrix(vector2D);
  int width = matrix.width();

  EXPECT_EQ(width, 2);
}

TEST(MatrixTests, ShouldReturnWidthAsZero)
{
  vector<vector<double>> vector2D
    = vector<vector<double>>();

  Matrix matrix = Matrix();
  int width = matrix.width();

  EXPECT_EQ(width, 0);
}

TEST(MatrixTests, ShouldReturnHeightAsFour)
{
  vector<vector<double>> vector2D
    = vector<vector<double>>();

  vector<double> firstColumn = {1, 2, 3, 4};
  vector<double> secondColumn = {5, 6, 7, 8};

  vector2D.push_back(firstColumn);
  vector2D.push_back(secondColumn);

  Matrix matrix = Matrix(vector2D);
  int height = matrix.height();

  EXPECT_EQ(height, 4);
}

TEST(MatrixTests, ShouldReturnHeightAsZero)
{
  vector<vector<double>> vector2D
    = vector<vector<double>>();

  Matrix matrix = Matrix();
  int height = matrix.height();

  EXPECT_EQ(height, 0);
}
