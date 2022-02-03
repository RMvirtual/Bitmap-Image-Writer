#include <gtest/gtest.h>

#include "test/src/bitmaps/packet/fixture.h"

TEST_F(BitmapPacketTest, ShouldSetPixelInPixelArray)
{
  this->loadRedPixelArray();
  auto greenColours = this->greenColours();
  this->pixelArray.set(greenColours, 1, 0);

  this->compare(greenColours, this->pixelArray.at(1, 0));
}

TEST_F(BitmapPacketTest, ShouldGetNumberOfPixelsInPixelArray)
{
  this->loadRedPixelArray();

  int correctNumberOfPixels = 4;
  int actualNumberOfPixels = this->pixelArray.sizeInPixels();

  EXPECT_EQ(correctNumberOfPixels, actualNumberOfPixels);
}