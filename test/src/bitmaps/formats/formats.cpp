#include <gtest/gtest.h>

#include "src/bitmaps/formats/formats.h"
#include "test/src/bitmaps/formats/fixture.h"

TEST_F(BitmapFormatsTest, ShouldGetRGBAFormat)
{
  this->initialiseRgbaFormat();
  this->compare(Bitmaps::format("RGBA"));
}

TEST_F(BitmapFormatsTest, ShouldGetRGBFormat)
{
  this->initialiseRgbFormat();
  compare(Bitmaps::format("RGB"));
}

TEST_F(BitmapFormatsTest, ShouldGet32BitPerPixelFormat)
{
  this->initialiseRgbaFormat();
  compare(Bitmaps::format(32));
}

TEST_F(BitmapFormatsTest, ShouldGet24BitPerPixelFormat)
{
  this->initialiseRgbFormat();
  compare(Bitmaps::format(24));
}

TEST_F(BitmapFormatsTest, ShouldCalculatePixelArrayRowPadding)
{
  auto format = Bitmaps::format(24);
  format.setWidthInPixels(2);
  format.setHeightInPixels(1);

  int actualPadding = format.rowPaddingInBytes();
  int correctPadding = 2;

  EXPECT_EQ(correctPadding, actualPadding);
}

TEST_F(BitmapFormatsTest, ShouldCalculatePixelArrayRowSizeInBytes)
{
  auto format = Bitmaps::format(24);
  format.setWidthInPixels(6);
  format.setHeightInPixels(1);

  int actualSize = format.rowSizeInBytes();
  int correctSize = 20;
  
  EXPECT_EQ(correctSize, actualSize);
}