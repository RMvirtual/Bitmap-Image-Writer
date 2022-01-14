#include <gtest/gtest.h>
#include <string>

#include "src/common/matrix-2D/matrix_row.h"
#include "src/common/matrix-2D/matrix_2d.h"

TEST(Matrix2DTests, ShouldCreateMatrixRow)
{
  int width = 2;
  Common::MatrixRow<std::string> matrixRow {width, "0"};

  auto value1 = "1";
  auto value2 = "2";
  matrixRow.set(value1, 0);
  matrixRow.set(value2, 1);
  
  EXPECT_EQ(matrixRow.at(0), value1);
  EXPECT_EQ(matrixRow.at(1), value2);
}

TEST(Matrix2DTests, ShouldCreate2DMatrix)
{
  int width = 2;
  int height = 2;

  auto value1 = "0, 1";
  auto value2 = "1, 1";

  Common::Matrix2D<std::string> matrix {width, height, "0"};
  matrix.set(value1, 0, 1);
  matrix.set(value2, 1, 1);

  EXPECT_EQ(matrix.at(0, 1), value1);
  EXPECT_EQ(matrix.at(1, 1), value2);
}
