#include <vector>

#include "gtest/gtest.h"
#include "src/main/cpp/files/alphabet-2d/file.h"

TEST(AlphabetFile, ShouldGetLetterHFromFile)
{
  auto letterMesh = Files::Alphabet2D::letter("h");

  Geometry::LineMesh correctLetterMesh = {{
    {{0.0, 0.0}, {0.0, 2}},
    {{0.0, 2}, {0.0, 1}},
    {{0.0, 1}, {1, 1}},
    {{1, 1}, {1, 0.0}},
    {{1, 0.0}, {1, 2}},
  }};
 
  auto numberOfVertices = letterMesh.size();
  ASSERT_EQ(correctLetterMesh.size(), numberOfVertices);

  for (int i = 0; i < numberOfVertices; i++) {
    auto line = letterMesh[i];
    auto correctLine = correctLetterMesh[i];

    EXPECT_EQ(correctLine.origin()[0], line.origin()[0]);
    EXPECT_EQ(correctLine.origin()[1], line.origin()[1]);
    EXPECT_EQ(correctLine.destination()[0], line.destination()[0]);
    EXPECT_EQ(correctLine.destination()[0], line.destination()[0]);
  }
}