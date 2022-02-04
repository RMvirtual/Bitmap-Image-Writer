#include <gtest/gtest.h>
#include <string>
#include <vector>

#include "src/bitmaps/formats/formats.h"
#include "test/src/bitmaps/formats/fixture.h"

TEST_F(BitmapFormatsTest, ShouldGetRGBAFormat)
{
  this->setupRGBAFormat();
  this->compare(Bitmaps::format("RGBA"));
}

TEST_F(BitmapFormatsTest, ShouldGetRGBFormat)
{
  this->setupRGBFormat();
  this->compare(Bitmaps::format("RGB"));
}

TEST_F(BitmapFormatsTest, ShouldGet32BitPerPixelFormat)
{
  this->setupRGBAFormat();
  this->compare(Bitmaps::format(32));
}

TEST_F(BitmapFormatsTest, ShouldGet24BitPerPixelFormat)
{
  this->setupRGBFormat();
  this->compare(Bitmaps::format(24));
}

TEST_F(BitmapFormatsTest, ShouldGetBitmapFormatFromHeaders)
{
  this->setupRGBFormat();
  this->compare(Bitmaps::format(this->rgbHeaders()));
}

TEST_F(BitmapFormatsTest, ShouldCalculatePixelArrayRowPadding)
{
  this->setupRGBFormat(2, 1);
  int actualPadding = this->format.rowPaddingInBytes();
  int correctPadding = 2;

  EXPECT_EQ(correctPadding, actualPadding);
}

TEST_F(BitmapFormatsTest, ShouldCalculatePixelArrayRowSizeInBytes)
{
  this->setupRGBFormat(6, 1);
  int actualSize = this->format.rowSizeInBytes();
  int correctSize = 20;
  
  EXPECT_EQ(correctSize, actualSize);
}

TEST_F(BitmapFormatsTest, ShouldIterateThroughColourNamesInOrder)
{
  this->setupRGBAFormat();
  std::vector<std::string> correctNames {"alpha", "blue", "green", "red"};
  auto names = this->format.colourNames();

  for (int i = 0; i < 4; i++)
    EXPECT_EQ(correctNames[i], names[i]);
}

TEST_F(BitmapFormatsTest, ShouldGetColourValuesByNumericIndex)
{
  this->setupRGBColours();
  std::vector<int> correctValues {1, 2, 3};
  
  for (int i = 0; i < correctValues.size(); i++)
    EXPECT_EQ(correctValues[i], this->colours[i]);
}