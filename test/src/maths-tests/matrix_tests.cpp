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

  std::vector<std::vector<double>> correctElements = {
    {1, 2, 3, 4},
    {5, 6, 7, 8}
  };

  for (int columnNo = 0; columnNo < correctElements.size(); columnNo++)
    for (int rowNo = 0; rowNo < correctElements[columnNo].size(); rowNo++) {
      double correctValue = correctElements[columnNo][rowNo];
      double doubleToTest = matrix[columnNo][rowNo];

      EXPECT_DOUBLE_EQ(correctValue, doubleToTest);
    }
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

TEST(MatrixTests, ShouldGetColumn)
{
  std::vector<std::vector<double>> vector2D = setup2DVector();

  Matrix matrix = Matrix(vector2D);

  std::vector<double> column = matrix.getColumn(0);
  std::vector<double> correctValues = {1, 2, 3, 4};

  for (int i = 0; i < column.size(); i++)
    EXPECT_EQ(column[i], correctValues[i]);
}

TEST(MatrixTests, ShouldGetRow)
{
  std::vector<std::vector<double>> vector2D = setup2DVector();

  Matrix matrix = Matrix(vector2D);

  std::vector<double> row = matrix.getRow(0);
  std::vector<double> correctValues = {1, 5};

  for (int i = 0; i < row.size(); i++)
    EXPECT_EQ(row[i], correctValues[i]);
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

TEST(MatrixTests, ShouldMultiplyMatrixByAnotherMatrix)
{
  std::vector<std::vector<double>> vector1 = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
  };

  std::vector<std::vector<double>> vector2 = {
    {10, 11, 12},
    {13, 14, 15},
    {16, 17, 18}
  };

  Matrix lhsMatrix = Matrix(vector1);
  Matrix rhsMatrix = Matrix(vector2);

  Matrix resultMatrix = lhsMatrix * rhsMatrix;

  std::vector<std::vector<double>> correctVectors = {
    {138, 171, 204},
    {174, 216, 258},
    {210, 261, 312}
  };

  Matrix correctMatrix(correctVectors);

  for (int columnNo = 0; columnNo < correctMatrix.width(); columnNo++)
    for (int rowNo = 0; rowNo < correctMatrix.height(); rowNo++)
      EXPECT_DOUBLE_EQ(
        correctMatrix[columnNo][rowNo],
        resultMatrix[columnNo][rowNo]
      );
}

TEST(MatrixTests, ShouldMultiplyMatrixByAMatrixWithDifferentHeight)
{
  std::vector<std::vector<double>> vector1 = {
    {1, 2},
    {3, 4},
    {5, 6}
  };

  std::vector<std::vector<double>> vector2 = {
    {7, 8, 9},
    {10, 11, 12},
    {13, 14, 15}
  };

  Matrix lhsMatrix = Matrix(vector1);
  Matrix rhsMatrix = Matrix(vector2);

  Matrix resultMatrix = lhsMatrix * rhsMatrix;

  std::vector<std::vector<double>> correctVectors = {
    {76, 100},
    {103, 136},
    {130, 172}
  };

  Matrix correctMatrix(correctVectors);

  for (int columnNo = 0; columnNo < correctMatrix.width(); columnNo++)
    for (int rowNo = 0; rowNo < correctMatrix.height(); rowNo++)
      EXPECT_DOUBLE_EQ(
        correctMatrix[columnNo][rowNo],
        resultMatrix[columnNo][rowNo]
      );
}

TEST(MatrixTests, ShouldPrintMatrixAsString)
{
  std::vector<std::vector<double>> values = {
    {1, 2, 3},
    {4, 5, 6}
  };

  Matrix matrix = Matrix(values);
  string actualString = matrix.toString();

  string correctString = (
    "| 1.000000 4.000000 |\n" \
    "| 2.000000 5.000000 |\n" \
    "| 3.000000 6.000000 |" \
  );

  EXPECT_EQ(correctString, actualString);
}