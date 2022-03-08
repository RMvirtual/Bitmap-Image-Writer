#include "src/test/cpp/text/textbox/fixture.h"

void TextTest::compare(
  std::vector<Text::Letter> correctLetters, Text::Text2D text)
{
  int noOfLetters = text.size();
  ASSERT_EQ(correctLetters.size(), noOfLetters);

  for (int i = 0; i < noOfLetters; i++) {
    std::cout << "In letter no: " << i << std::endl;
    auto correctLetter = correctLetters[i];
    auto letter = text[i];

    this->compare(correctLetter, letter);
  }
}

void TextTest::compare(Text::Letter correctLetter, Text::Letter letter)
{
  int noOfLines = letter.noOfLines();
  ASSERT_EQ(correctLetter.noOfLines(), noOfLines);

  for (int i = 0; i < noOfLines; i++) {
    auto correctLine = correctLetter[i];
    auto line = letter[i];

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