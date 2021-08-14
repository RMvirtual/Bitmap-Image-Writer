#include <gtest/gtest.h>
#include <vector>
#include <iostream>
#include "src/maths/matrix/matrix.h"

using namespace Maths;
using namespace std;

std::vector<std::vector<double>> setup2DVector()
{
  std::vector<std::vector<double>> vector2D
  = std::vector<std::vector<double>>();

  std::vector<double> firstColumn = {1, 2, 3, 4};
  std::vector<double> secondColumn = {5, 6, 7, 8};

  vector2D.push_back(firstColumn);
  vector2D.push_back(secondColumn);

  return vector2D;
}

TEST(MatrixTests, ShouldCreateMatrixFrom2DVector)
{
  std::vector<std::vector<double>> vector2D = setup2DVector();

  Matrix matrix = Matrix(vector2D);
  double doubleToTest = matrix[1][1];

  EXPECT_DOUBLE_EQ(6, doubleToTest);
}

TEST(MatrixTests, ShouldReturnWidthAsTwo)
{
  std::vector<std::vector<double>> vector2D = setup2DVector();

  Matrix matrix = Matrix(vector2D);
  int width = matrix.width();

  EXPECT_EQ(width, 2);
}

TEST(MatrixTests, ShouldReturnWidthAsZero)
{
  std::vector<std::vector<double>> vector2D
    = std::vector<std::vector<double>>();

  Matrix matrix = Matrix();
  int width = matrix.width();

  EXPECT_EQ(width, 0);
}

TEST(MatrixTests, ShouldReturnHeightAsFour)
{
  std::vector<std::vector<double>> vector2D = setup2DVector();

  Matrix matrix = Matrix(vector2D);
  int height = matrix.height();

  EXPECT_EQ(height, 4);
}

TEST(MatrixTests, ShouldReturnHeightAsZero)
{
  std::vector<std::vector<double>> vector2D
    = std::vector<std::vector<double>>();

  Matrix matrix = Matrix();
  int height = matrix.height();

  EXPECT_EQ(height, 0);
}

TEST(MatrixTests, ShouldMultiplyMatrixByA2DVector)
{
  std::vector<std::vector<double>> vector2D
    = std::vector<std::vector<double>>();

  std::vector<double> firstColumn = {1, 2};
  std::vector<double> secondColumn = {3, 4};

  vector2D.push_back(firstColumn);
  vector2D.push_back(secondColumn);

  Matrix matrix = Matrix(vector2D);
  Maths::Vector vector = Vector(5, 6);

  Maths::Vector multipledResult = matrix * vector;
  Maths::Vector correctVector(23, 34);

  for (int i = 0; i < correctVector.length(); i++)
    EXPECT_DOUBLE_EQ(multipledResult[i], correctVector[i]);
}

TEST(MatrixTests, ShouldMultiplyMatrixByA3DVector)
{
  std::vector<std::vector<double>> vector2D;

  std::vector<double> firstColumn = {1, 2, 3};
  std::vector<double> secondColumn = {4, 5, 6};
  std::vector<double> thirdColumn = {7, 8, 9};

  vector2D = {firstColumn, secondColumn, thirdColumn};

  Matrix matrix = Matrix(vector2D);
  Maths::Vector vector = Vector(10, 11, 12);

  Maths::Vector multipledResult = matrix * vector;
  Maths::Vector correctVector(138, 171, 204);

  for (int i = 0; i < correctVector.length(); i++)
    EXPECT_DOUBLE_EQ(multipledResult[i], correctVector[i]);
}