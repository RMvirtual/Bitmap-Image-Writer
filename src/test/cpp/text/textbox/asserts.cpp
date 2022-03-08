#include "src/test/cpp/text/textbox/fixture.h"

void TextTest::compare(Text::Text2D text)
{
  int noOfLetters = text.size();
  ASSERT_EQ(this->correctLetters.size(), noOfLetters);

  for (int i = 0; i < noOfLetters; i++) {
    std::cout << "\nTesting letter " << i << "\n";
    auto lineMesh = text[i];
    auto correctLineMesh = this->correctLetters[i];

    this->compare(correctLineMesh, lineMesh);
  }
}

void TextTest::compare(Geometry::LineMesh correctMesh, Geometry::LineMesh mesh)
{
  int noOfLines = mesh.size();
  ASSERT_EQ(correctMesh.size(), noOfLines);

  for (int i = 0; i < noOfLines; i++) {
    auto line = mesh[i];
    auto correctLine = correctMesh[i];

    this->compare(correctLine, line);
  }
}

void TextTest::compare(Geometry::Line correctLine, Geometry::Line line)
{
  EXPECT_EQ(correctLine["x0"], line["x0"]);
  EXPECT_EQ(correctLine["y0"], line["y0"]);
  EXPECT_EQ(correctLine["x1"], line["x1"]);
  EXPECT_EQ(correctLine["y1"], line["y1"]);
}