#include <gtest/gtest.h>
#include "src/test/bitmaps/formats/fixture.h"

void BitmapFormatsTest::compare(Bitmaps::Format& format)
{
  this->compareNames(format); 
  this->compareBitsPerPixel(format);
  this->compareColours(format);
}

void BitmapFormatsTest::compareNames(Bitmaps::Format& format)
{
  EXPECT_EQ(this->format.name(), format.name());
}

void BitmapFormatsTest::compareBitsPerPixel(Bitmaps::Format& format)
{
  EXPECT_EQ(this->format.bitsPerPixel(), format.bitsPerPixel());
}

void BitmapFormatsTest::compareColours(Bitmaps::Format& format)
{
  auto correctColours = this->format.colourNames();
  auto colours = format.colourNames();

  int correctNoOfColours = correctColours.size();
  int noOfColours = colours.size();

  ASSERT_EQ(correctNoOfColours, noOfColours);

  for (int colourNo = 0; colourNo < noOfColours; colourNo++)
    EXPECT_EQ(correctColours[colourNo], colours[colourNo]);
}