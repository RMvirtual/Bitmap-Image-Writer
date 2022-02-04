#include <gtest/gtest.h>
#include "test/src/bitmaps/packet/fixture.h"

TEST_F(BitmapPacketTest, ShouldSetPixelInPixelArray)
{
  auto green = this->greenColours();
  this->pixelArray.set(green, 1, 0);

  auto amendedColours = this->pixelArray.at(1, 0); 
  this->isGreen(amendedColours);
}

TEST_F(BitmapPacketTest, ShouldGetNumberOfPixelsInPixelArray)
{
  int correctNoOfPixels = 4;
  int actualNoOfPixels = this->pixelArray.sizeInPixels();

  EXPECT_EQ(correctNoOfPixels, actualNoOfPixels);
}

TEST_F(BitmapPacketTest, ShouldFillPixelArray)
{
  this->pixelArray.fill(this->greenColours());
  int noOfPixels = this->pixelArray.sizeInPixels();

  for (int i = 0; i < noOfPixels; i++) {
    auto pixel = this->pixelArray.at(i);
    this->isGreen(pixel);
  }
}