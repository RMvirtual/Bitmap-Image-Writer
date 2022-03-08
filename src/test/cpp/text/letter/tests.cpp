#include "src/test/cpp/text/letter/fixture.h"
#include "src/main/cpp/text/2d/letter/letter.h"

TEST_F(LetterTest, ShouldGetXLowerBound)
{
  Text::Letter letter {"c"};
  double correctBound = 0.0;
  auto bound = letter.xLowerBound();
  
  EXPECT_EQ(correctBound, bound);
}

TEST_F(LetterTest, ShouldGetXUpperBound)
{
  Text::Letter letter {"c"};
  double correctBound = 1.5;
  auto bound = letter.xUpperBound();
  
  EXPECT_EQ(correctBound, bound);
}

TEST_F(LetterTest, ShouldGetYLowerBound)
{
  Text::Letter letter {"c"};
  double correctBound = 0.0;
  auto bound = letter.yLowerBound();
  
  EXPECT_EQ(correctBound, bound);
}

TEST_F(LetterTest, ShouldGetYUpperBound)
{
  Text::Letter letter {"c"};
  double correctBound = 2;
  auto bound = letter.yUpperBound();
  
  EXPECT_EQ(correctBound, bound);
}