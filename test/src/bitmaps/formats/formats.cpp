#include <gtest/gtest.h>
#include <string>
#include <vector>

#include "src/bitmaps/formats/formats.h"
#include "test/src/bitmaps/formats/fixture.h"

TEST_F(BitmapFormatsTest, ShouldGetRGBAFormat)
{
  this->loadRGBAFormat();
  this->compare(Bitmaps::format("RGBA"));
}

TEST_F(BitmapFormatsTest, ShouldGetRGBFormat)
{
  this->loadRGBFormat();
  this->compare(Bitmaps::format("RGB"));
}

TEST_F(BitmapFormatsTest, ShouldGet32BitPerPixelFormat)
{
  this->loadRGBAFormat();
  this->compare(Bitmaps::format(32));
}

TEST_F(BitmapFormatsTest, ShouldGet24BitPerPixelFormat)
{
  this->loadRGBFormat();
  this->compare(Bitmaps::format(24));
}

TEST_F(BitmapFormatsTest, ShouldGetBitmapFormatFromHeaders)
{
  this->loadRGBFormat();
  this->compare(Bitmaps::format(this->rgbHeaders()));
}

TEST_F(BitmapFormatsTest, ShouldCalculatePixelArrayRowPadding)
{
  this->loadRGBFormat(2, 1);
  int actualPadding = this->format.rowPaddingInBytes();
  int correctPadding = 2;

  EXPECT_EQ(correctPadding, actualPadding);
}

TEST_F(BitmapFormatsTest, ShouldCalculatePixelArrayRowSizeInBytes)
{
  this->loadRGBFormat(6, 1);
  int actualSize = this->format.rowSizeInBytes();
  int correctSize = 20;
  
  EXPECT_EQ(correctSize, actualSize);
}

TEST_F(BitmapFormatsTest, ShouldIterateThroughColourNamesInOrder)
{
  this->loadRGBAFormat();
  std::vector<std::string> correctNames {"alpha", "blue", "green", "red"};
  auto names = this->format.colourNames();

  for (int i = 0; i < 4; i++)
    EXPECT_EQ(correctNames[i], names[i]);
}