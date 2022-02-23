#include <gtest/gtest.h>
#include <string>

#include "src/main/cpp/containers/matrix-2d/matrix_row.h"
#include "src/main/cpp/containers/matrix-2d/matrix_2d.h"

TEST(Matrix2D, ShouldGetValuesFrom2DMatrixRow)
{
  int width = 2;
  MatrixRow<std::string> matrixRow {width, "0"};

  auto value1 = "1";
  auto value2 = "2";
  matrixRow.set(value1, 0);
  matrixRow.set(value2, 1);
  
  EXPECT_EQ(matrixRow.at(0), value1);
  EXPECT_EQ(matrixRow.at(1), value2);
}

TEST(Matrix2D, ShouldGetValuesFrom2DMatrix)
{
  int width = 2;
  int height = 2;

  std::string value1 = "0, 1";
  std::string value2 = "1, 1";

  Matrix2D<std::string> matrix {width, height, "0"};
  matrix.set(value1, 0, 1);
  matrix.set(value2, 1, 1);

  EXPECT_EQ(matrix.at(0, 1), value1);
  EXPECT_EQ(matrix.at(1, 1), value2);
}

TEST(Matrix2D, ShouldGetElementWithAbsoluteIndex)
{
  int width = 2;
  int height = 2;

  std::string value1 = "0, 1";
  std::string value2 = "1, 1";
  
  Matrix2D<std::string> matrix {width, height, "0"};
  matrix.set(value1, 0, 1);
  matrix.set(value2, 1, 1);

  EXPECT_EQ(matrix.at(1), value1);
  EXPECT_EQ(matrix.at(3), value2);
}

TEST(Matrix2D, ShouldGetElementWithDoubleSubscriptOperator)
{
  int width = 2;
  int height = 2;

  std::string value1 = "0, 1";
  std::string value2 = "1, 1";
  
  Matrix2D<std::string> matrix {width, height, "0"};
  matrix.set(value1, 0, 1);
  matrix.set(value2, 1, 1);

  EXPECT_EQ(matrix[0][1], value1);
  EXPECT_EQ(matrix[1][1], value2);
}


TEST(Matrix2D, ShouldFillMatrix)
{
  int width = 2;
  int height = 2;

  Matrix2D<std::string> matrix {width, height, "0"};

  std::string correctValue = "0, 1";
  matrix.fill(correctValue);

  for (int i = 0; i < 4; i++)
    EXPECT_EQ(matrix.at(i), correctValue);
}

TEST(Matrix2D, ShouldFillMatrixRow)
{
  int columns = 2;

  MatrixRow<std::string> row {columns, "0"};

  std::string correctValue = "0, 1";
  row.fill(correctValue);

  for (int columnNo = 0; columnNo < columns; columnNo++)
    EXPECT_EQ(row[columnNo], correctValue);
}
