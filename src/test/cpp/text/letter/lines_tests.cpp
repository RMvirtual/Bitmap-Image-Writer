#include <vector>

#include "src/test/cpp/text/letter/fixture.h"
#include "src/main/cpp/text/2d/letter/letter.h"
#include "src/main/cpp/geometry/line/line.h"

TEST_F(LetterTest, ShouldGetLines)
{
  Text::Letter letter {"c"};

  std::vector<Geometry::Line> correctLines = {
    {{1.5, 2}, {0.5, 2}},
    {{0.5, 2}, {0.0, 1.5}},
    {{0.0, 1.5}, {0.0, 0.5}},
    {{0.0, 0.5}, {0.5, 0.0}},
    {{0.5, 0.0}, {1.5, 0.0}}
  };

  int noOfLines = letter.noOfLines();
  ASSERT_EQ(correctLines.size(), noOfLines);

  for (int i = 0; i < noOfLines; i++)
    this->compare(correctLines[i], letter[i]);
}

TEST_F(LetterTest, ShouldGetTranslatedLines)
{
  Text::Letter letter {"c"};
  letter.translate({2,4});

  std::vector<Geometry::Line> correctLines = {
    {{3.5, 6}, {2.5, 6}},
    {{2.5, 6}, {2, 5.5}},
    {{2, 5.5}, {2, 4.5}},
    {{2, 4.5}, {2.5, 4}},
    {{2.5, 4}, {3.5, 4}}
  };

  int noOfLines = letter.noOfLines();
  ASSERT_EQ(correctLines.size(), noOfLines);

  for (int i = 0; i < noOfLines; i++)
    this->compare(correctLines[i], letter[i]);
}

TEST_F(LetterTest, ShouldTranslateLinesWith0Y)
{
  Text::Letter letter {"c"};
  letter.translate({2, 0});

  std::vector<Geometry::Line> correctLines = {
    {{3.5, 2}, {2.5, 2}},
    {{2.5, 2}, {2, 1.5}},
    {{2, 1.5}, {2, 0.5}},
    {{2, 0.5}, {2.5, 0.0}},
    {{2.5, 0.0}, {3.5, 0.0}}
  };

  int noOfLines = letter.noOfLines();
  ASSERT_EQ(correctLines.size(), noOfLines);

  for (int i = 0; i < noOfLines; i++)
    this->compare(correctLines[i], letter[i]);
}


TEST_F(LetterTest, ShouldGetScaledLines)
{
  Text::Letter letter {"c"};
  letter.scaleIncludingOrigin(2);

  std::vector<Geometry::Line> correctLines = {
    {{3, 4}, {1, 4}},
    {{1, 4}, {0.0, 3}},
    {{0.0, 3}, {0.0, 1}},
    {{0.0, 1}, {1, 0.0}},
    {{1, 0.0}, {3, 0.0}}
  };

  int noOfLines = letter.noOfLines();
  ASSERT_EQ(correctLines.size(), noOfLines);

  for (int i = 0; i < noOfLines; i++)
    this->compare(correctLines[i], letter[i]);
}

TEST_F(LetterTest, ShouldScaleThenTranslateLines)
{
  Text::Letter letter {"c"};
  letter.scaleIncludingOrigin(2);
  letter.translate({2,4});

  std::vector<Geometry::Line> correctLines = {
    {{5, 8}, {3, 8}},
    {{3, 8}, {2, 7}},
    {{2, 7}, {2, 5}},
    {{2, 5}, {3, 4}},
    {{3, 4}, {5, 4}}
  };

  int noOfLines = letter.noOfLines();
  ASSERT_EQ(correctLines.size(), noOfLines);

  for (int i = 0; i < noOfLines; i++)
    this->compare(correctLines[i], letter[i]);
}

TEST_F(LetterTest, ShouldTranslateThenScaleLines)
{
  Text::Letter letter {"c"};
  letter.translate({2,4});
  letter.scaleIncludingOrigin(2);

  std::vector<Geometry::Line> correctLines = {
    {{7, 12}, {5, 12}},
    {{5, 12}, {4, 11}},
    {{4, 11}, {4, 9}},
    {{4, 9}, {5, 8}},
    {{5, 8}, {7, 8}}
  };

  int noOfLines = letter.noOfLines();
  ASSERT_EQ(correctLines.size(), noOfLines);

  for (int i = 0; i < noOfLines; i++)
    this->compare(correctLines[i], letter[i]);
}

TEST_F(LetterTest, ShouldScaleWithProvidedOrigin)
{
  Text::Letter letter {"c"};
  letter.translate({5,3});
  letter.scale(2, {5, 3});

  std::vector<Geometry::Line> correctLines = {
    {{8, 7}, {6, 7}},
    {{6, 7}, {5, 6}},
    {{5, 6}, {5, 4}},
    {{5, 4}, {6, 3}},
    {{6, 3}, {8, 3}}
  };

  int noOfLines = letter.noOfLines();
  ASSERT_EQ(correctLines.size(), noOfLines);

  for (int i = 0; i < noOfLines; i++)
    this->compare(correctLines[i], letter[i]);
}
