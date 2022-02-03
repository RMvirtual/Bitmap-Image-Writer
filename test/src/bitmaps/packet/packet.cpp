#include <gtest/gtest.h>

#include "src/bitmaps/packet/packet.h"
#include "src/bitmaps/packet/headers/headers.h"
#include "src/bitmaps/formats/format.h"
#include "src/bitmaps/packet/pixel-array/array.h"
#include "src/bitmaps/packet/pixel-array/colours.h"
#include "test/src/bitmaps/fixtures/packet.h"

TEST_F(BitmapPacketTest, ShouldCreatePixelArray)
{
  Bitmaps::Format format;
  format.setName("RGB");
  format.setBitsPerPixel(24);
  format.setColourNames({"red", "green", "blue"});
  format.setWidthInPixels(4);
  format.setHeightInPixels(1);

  Bitmaps::PixelArray pixelArray {format};
  Bitmaps::Colours correctColours {format.colourNames()};

  for (int pixelNo = 0; pixelNo < 4; pixelNo++)
    this->compare(correctColours, pixelArray.at(pixelNo));
}

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