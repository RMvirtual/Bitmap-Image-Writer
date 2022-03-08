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

TEST_F(LetterTest, ShouldGetXLowerBoundAfterTranslation)
{
  Text::Letter letter {"c"};
  letter.translate({2,4});
  
  double correctBound = 2;
  auto bound = letter.xLowerBound();
  
  EXPECT_EQ(correctBound, bound);
}

TEST_F(LetterTest, ShouldGetXUpperBoundAfterTranslation)
{
  Text::Letter letter {"c"};
  letter.translate({2,4});

  double correctBound = 3.5;
  auto bound = letter.xUpperBound();
  
  EXPECT_EQ(correctBound, bound);
}

TEST_F(LetterTest, ShouldGetYLowerBoundAfterTranslation)
{
  Text::Letter letter {"c"};
  letter.translate({2,4});
  
  double correctBound = 4;
  auto bound = letter.yLowerBound();
  
  EXPECT_EQ(correctBound, bound);
}

TEST_F(LetterTest, ShouldGetYUpperBoundAfterTranslation)
{
  Text::Letter letter {"c"};
  letter.translate({2,4});

  double correctBound = 6;
  auto bound = letter.yUpperBound();
  
  EXPECT_EQ(correctBound, bound);
}

TEST_F(LetterTest, ShouldGetXLowerBoundAfterScaling)
{
  Text::Letter letter {"c"};
  letter.scaleIncludingOrigin(2);
  
  double correctBound = 0.0;
  auto bound = letter.xLowerBound();
  
  EXPECT_EQ(correctBound, bound);
}

TEST_F(LetterTest, ShouldGetXUpperBoundAfterScaling)
{
  Text::Letter letter {"c"};
  letter.scaleIncludingOrigin(2);
  
  double correctBound = 3;
  auto bound = letter.xUpperBound();
  
  EXPECT_EQ(correctBound, bound);
}

TEST_F(LetterTest, ShouldGetYLowerBoundAfterScaling)
{
  Text::Letter letter {"c"};
  letter.scaleIncludingOrigin(2);
  
  double correctBound = 0.0;
  auto bound = letter.yLowerBound();
  
  EXPECT_EQ(correctBound, bound);
}

TEST_F(LetterTest, ShouldGetYUpperBoundAfterScaling)
{
  Text::Letter letter {"c"};
  letter.scaleIncludingOrigin(2);
  
  double correctBound = 4;
  auto bound = letter.yUpperBound();
  
  EXPECT_EQ(correctBound, bound);
}

TEST_F(LetterTest, ShouldGetXLowerBoundAfterScalingAndTranslation)
{
  Text::Letter letter {"c"};
  letter.scaleIncludingOrigin(2);
  letter.translate({2,4});
  
  double correctBound = 2;
  auto bound = letter.xLowerBound();
  
  EXPECT_EQ(correctBound, bound);
}

TEST_F(LetterTest, ShouldGetXUpperBoundAfterScalingAndTranslation)
{
  Text::Letter letter {"c"};
  letter.scaleIncludingOrigin(2);
  letter.translate({2,4});
  
  double correctBound = 5;
  auto bound = letter.xUpperBound();
  
  EXPECT_EQ(correctBound, bound);
}

TEST_F(LetterTest, ShouldGetYLowerBoundAfterScalingAndTranslation)
{
  Text::Letter letter {"c"};
  letter.scaleIncludingOrigin(2);
  letter.translate({2,4});
  
  double correctBound = 4;
  auto bound = letter.yLowerBound();
  
  EXPECT_EQ(correctBound, bound);
}

TEST_F(LetterTest, ShouldGetYUpperBoundAfterScalingAndTranslation)
{
  Text::Letter letter {"c"};
  letter.scaleIncludingOrigin(2);
  letter.translate({2,4});
  
  double correctBound = 8;
  auto bound = letter.yUpperBound();
  
  EXPECT_EQ(correctBound, bound);
}