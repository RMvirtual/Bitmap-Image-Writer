#include <vector>

#include "src/test/cpp/text/letter/fixture.h"
#include "src/main/cpp/text/2d/letter/letter.h"
#include "src/main/cpp/geometry/line/line.h"

TEST_F(LetterTest, ShouldGetLetterContents)
{
  Text::Letter letter {"c"};

  // [1.5, 2], [0.5, 2],
  // [0.0, 1.5], [0.0, 0.5],
  // [0.5, 0.0], [1.5, 0.0]
  
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

