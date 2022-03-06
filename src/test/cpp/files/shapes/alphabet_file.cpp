#include <vector>

#include "gtest/gtest.h"
#include "src/main/cpp/files/shapes/file.h"

TEST(AlphabetFile, ShouldGetLetterHFromFile)
{
  Files::AlphabetFile alphabetFile {};
  auto letterH = alphabetFile.letter("h");

  std::vector<std::vector<double>> correctH {
    {0.0, 0.0}, {0.0, 3},
    {0.0, 2}, {2, 2},
    {2, 0.0}, {2, 3}
  };

  auto numberOfVertices = letterH.size();
  ASSERT_EQ(correctH.size(), numberOfVertices);

  for (int i = 0; i < numberOfVertices; i++) {
    auto vertex = letterH[i];
    auto correctVertex = correctH[i];

    auto numberOfCoordinates = vertex.size();

    ASSERT_EQ(correctVertex.size(), numberOfCoordinates);
    
    for (int j = 0; j < numberOfCoordinates; j++)
      EXPECT_EQ(correctVertex[j], vertex[i]);
  }
}
