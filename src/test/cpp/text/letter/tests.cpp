#include "src/test/cpp/text/letter/fixture.h"
#include "src/main/cpp/text/2d/letter/letter.h"

TEST_F(LetterTest, ShouldGetXUpperBound)
{
  Text::Letter letter {"c"};
  double correctBound = 1.5;
  double bound = letter.xUpperBound();
  
  EXPECT_EQ(correctBound, bound);
}