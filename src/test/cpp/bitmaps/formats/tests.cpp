#include <string>
#include <vector>

#include "gtest/gtest.h"
#include "src/main/cpp/bitmaps/formats/formats.h"
#include "src/test/cpp/bitmaps/formats/fixture.h"

TEST_F(BitmapFormatsTest, ShouldGetRGBAFormat)
{
  this->setupRGBAFormat();
  this->compare(Bitmaps::format("RGBA32"));
}

TEST_F(BitmapFormatsTest, ShouldGetRGBFormat)
{
  this->setupRGBFormat();
  this->compare(Bitmaps::format("RGB24"));
}

TEST_F(BitmapFormatsTest, ShouldCalculatePixelArrayRowPaddingOverFour)
{
  this->setupRGBFormat(5, 3);
  int actualPadding = this->format.bytesPaddingPerRow();
  int correctPadding = 1;

  EXPECT_EQ(correctPadding, actualPadding);
}

TEST_F(BitmapFormatsTest, ShouldCalculatePixelArrayRowPaddingOnFour)
{
  this->setupRGBFormat(4, 3);
  int actualPadding = this->format.bytesPaddingPerRow();
  int correctPadding = 0;

  EXPECT_EQ(correctPadding, actualPadding);
}

TEST_F(BitmapFormatsTest, ShouldCalculatePixelArrayRowPaddingUnderFour)
{
  this->setupRGBFormat(2, 1);
  int actualPadding = this->format.bytesPaddingPerRow();
  int correctPadding = 2;

  EXPECT_EQ(correctPadding, actualPadding);
}

TEST_F(BitmapFormatsTest, ShouldCalculatePixelArrayRowSizeInBytes)
{
  this->setupRGBFormat(6, 2);
  int actualSize = this->format.bytesPerRow();
  int correctSize = 20;
  
  EXPECT_EQ(correctSize, actualSize);
}

TEST_F(BitmapFormatsTest, ShouldIterateThroughColourNamesInOrder)
{
  this->setupRGBAFormat();
  std::vector<std::string> correctNames {"alpha", "blue", "green", "red"};
  auto names = this->format.colourNames();

  for (int i = 0; i < correctNames.size(); i++)
    EXPECT_EQ(correctNames[i], names[i]);
}

TEST_F(BitmapFormatsTest, ShouldGetColourValuesByNumericIndex)
{
  this->setupRGBColours();
  std::vector<int> correctValues {1, 2, 3};
  
  for (int i = 0; i < correctValues.size(); i++)
    EXPECT_EQ(correctValues[i], this->colours[i]);
}