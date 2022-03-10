#include "src/test/cpp/bitmaps/packet/fixture.h"

void BitmapPacketTest::isGreen(Bitmaps::Colours& colour)
{
  EXPECT_EQ(colour["green"], 255);
  EXPECT_EQ(colour["blue"], 0);
  EXPECT_EQ(colour["red"], 0);
}