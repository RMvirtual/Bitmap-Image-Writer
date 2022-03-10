#include "src/test/cpp/bitmaps/packet/pixel-array/fixture.h"

void PixelArrayTest::isGreen(Bitmaps::Colours& colour)
{
  EXPECT_EQ(colour["green"], 255);
  EXPECT_EQ(colour["blue"], 0);
  EXPECT_EQ(colour["red"], 0);
}