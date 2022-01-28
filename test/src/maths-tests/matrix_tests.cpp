#include <gtest/gtest.h>
#include <vector>
#include <iostream>
#include "src/maths/matrix/matrix.h"

std::vector<std::vector<double>> setup2DVector()
{
  return {{1, 2, 3, 4}, {5, 6, 7, 8}};
}

TEST(MatrixTests, ShouldCreateMatrixFrom2DVector)
{
  auto vector2D = setup2DVector();
  Maths::Matrix matrix {vector2D};

  std::vector<std::vector<double>> correctElements {
    {1, 2, 3, 4},
    {5, 6, 7, 8}
  };

  for (int columnNo = 0; columnNo < correctElements.size(); columnNo++)
    for (int rowNo = 0; rowNo < correctElements[columnNo].size(); rowNo++) {
      double correctValue = correctElements[columnNo][rowNo];
      double valueToTest = matrix[columnNo][rowNo];

      EXPECT_DOUBLE_EQ(correctValue, valueToTest);
    }
}

TEST(MatrixTests, ShouldReturnWidthAsTwo)
{
  auto vector2D = setup2DVector();
  Maths::Matrix matrix {vector2D};

  int width = matrix.width();
  int correctWidth = vector2D.size();  

  EXPECT_EQ(width, correctWidth);
}

TEST(MatrixTests, ShouldReturnWidthAsZero)
{
  std::vector<std::vector<double>> vector2D {};
  Maths::Matrix matrix {};

  int width = matrix.width();
  int correctWidth = vector2D.size();

  EXPECT_EQ(correctWidth, width);
}

TEST(MatrixTests, ShouldReturnHeightAsFour)
{
  auto vector2D = setup2DVector();
  Maths::Matrix matrix {vector2D};

  int height = matrix.height();
  int correctHeight = vector2D.front().size();

  EXPECT_EQ(correctHeight, height);
}

TEST(MatrixTests, ShouldReturnHeightAsZero)
{
  std::vector<std::vector<double>> vector2D {};
  Maths::Matrix matrix {};

  EXPECT_EQ(matrix.height(), 0);
}

TEST(MatrixTests, ShouldGetColumn)
{
  auto vector2D = setup2DVector();
  Maths::Matrix matrix {vector2D};
  auto column = matrix.column(0);

  std::vector<double> correctValues {1, 2, 3, 4};

  for (int rowNo = 0; rowNo < column.size(); rowNo++)
    EXPECT_EQ(column[rowNo], correctValues[rowNo]);
}

TEST(MatrixTests, ShouldGetRow)
{
  auto vector2D = setup2DVector();
  Maths::Matrix matrix {vector2D};
  auto row = matrix.row(0);

  std::vector<double> correctValues {1, 5};

  for (int valueNo = 0; valueNo < row.size(); valueNo++)
    EXPECT_EQ(row[valueNo], correctValues[valueNo]);
}

TEST(MatrixTests, ShouldMultiplyMatrixByA2DVector)
{
  std::vector<std::vector<double>> vector2D {{1, 2}, {3, 4}};
  Maths::Matrix matrix {vector2D};
  Maths::Vector vector {5, 6};
  Maths::Vector multipledResult = vector * matrix;
  
  Maths::Vector correctVector {23, 34};

  for (int i = 0; i < correctVector.length(); i++)
    EXPECT_DOUBLE_EQ(multipledResult[i], correctVector[i]);
}

TEST(MatrixTests, ShouldMultiplyMatrixByA3DVector)
{
  std::vector<std::vector<double>> vector2D = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
  };

  Maths::Matrix matrix {vector2D};
  Maths::Vector vector {10, 11, 12};
  Maths::Vector multipledResult = matrix * vector;

  Maths::Vector correctResult {138, 171, 204};

  for (int i = 0; i < correctResult.length(); i++)
    EXPECT_DOUBLE_EQ(multipledResult[i], correctResult[i]);
}

TEST(MatrixTests, ShouldMultiplyMatrixByAnotherMatrix)
{
  std::vector<std::vector<double>> vector1 {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
  };

  std::vector<std::vector<double>> vector2 {
    {10, 11, 12},
    {13, 14, 15},
    {16, 17, 18}
  };

  Maths::Matrix lhsMatrix {vector1};
  Maths::Matrix rhsMatrix {vector2};

  Maths::Matrix resultMatrix = lhsMatrix * rhsMatrix;

  std::vector<std::vector<double>> correctValues {
    {138, 171, 204},
    {174, 216, 258},
    {210, 261, 312}
  };

  Maths::Matrix correctMatrix {correctValues};

  for (int columnNo = 0; columnNo < correctMatrix.width(); columnNo++)
    for (int rowNo = 0; rowNo < correctMatrix.height(); rowNo++)
      EXPECT_DOUBLE_EQ(
        correctMatrix[columnNo][rowNo],
        resultMatrix[columnNo][rowNo]
      );
}

TEST(MatrixTests, ShouldMultiplyMatrixByAMatrixWithDifferentHeight)
{
  std::vector<std::vector<double>> vector1 {
    {1, 2},
    {3, 4},
    {5, 6}
  };

  std::vector<std::vector<double>> vector2 {
    {7, 8, 9},
    {10, 11, 12},
    {13, 14, 15}
  };

  Maths::Matrix lhsMatrix {vector1};
  Maths::Matrix rhsMatrix {vector2};

  Maths::Matrix resultMatrix = lhsMatrix * rhsMatrix;

  std::vector<std::vector<double>> correctVectors {
    {76, 100},
    {103, 136},
    {130, 172}
  };

  Maths::Matrix correctMatrix(correctVectors);

  for (int columnNo = 0; columnNo < correctMatrix.width(); columnNo++)
    for (int rowNo = 0; rowNo < correctMatrix.height(); rowNo++)
      EXPECT_DOUBLE_EQ(
        correctMatrix[columnNo][rowNo],
        resultMatrix[columnNo][rowNo]
      );
}

TEST(MatrixTests, ShouldPrintMatrixAsString)
{
  std::vector<std::vector<double>> values {{1, 2, 3}, {4, 5, 6}};
  Maths::Matrix matrix {values};

  std::string correctString = (
    "| 1 4 |\n" \
    "| 2 5 |\n" \
    "| 3 6 |" \
  );

  EXPECT_EQ(correctString, matrix.toString());
}

TEST(MatrixTests, ColumnShouldBeIterable)
{
  std::vector<double> correctValues {1, 2, 3, 4};
  Maths::Column column {correctValues};
  std::vector<double> valuesFromIteration {};
  
  for (auto value : column)
    valuesFromIteration.push_back(value);

  for (int i = 0; i < correctValues.size(); i++)
    EXPECT_DOUBLE_EQ(correctValues[i], valuesFromIteration[i]);
}