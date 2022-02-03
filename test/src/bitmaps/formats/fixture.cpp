#include <gtest/gtest.h>

#include "test/src/bitmaps/formats/fixture.h"
#include "src/bitmaps/packet/headers/headers.h"

BitmapFormatsTest::BitmapFormatsTest()
{
  
}

BitmapFormatsTest::~BitmapFormatsTest()
{

}

void BitmapFormatsTest::compare(Bitmaps::Format& format)
{
  EXPECT_EQ(this->format.name(), format.name());
  EXPECT_EQ(this->format.bitsPerPixel(), format.bitsPerPixel());

  auto correctColours = this->format.colourNames();
  auto colours = format.colourNames();

  int noOfColours = correctColours.size();
  EXPECT_EQ(noOfColours, colours.size());

  for (int colourNo = 0; colourNo < noOfColours; colourNo++)
    EXPECT_EQ(correctColours[colourNo], colours[colourNo]);
}

void BitmapFormatsTest::loadRGBAFormat()
{
  this->format.setName("RGBA");
  this->format.setBitsPerPixel(32);
  this->format.setColourNames({"alpha", "blue", "green", "red"});
}

void BitmapFormatsTest::loadRGBFormat()
{
  this->format.setName("RGB");
  this->format.setBitsPerPixel(24);
  this->format.setColourNames({"blue", "green", "red"});
}

void BitmapFormatsTest::loadRGBFormat(int width, int height)
{
  this->loadRGBFormat();
  this->format.setWidthInPixels(width);
  this->format.setHeightInPixels(height);
}

Bitmaps::Headers BitmapFormatsTest::rgbHeaders()
{
  Bitmaps::Headers headers;
  headers.fileHeader = this->rgbFileHeader();
  headers.dibHeader = this->rgbDibHeader();

  return headers;
}

Bitmaps::FileHeader BitmapFormatsTest::rgbFileHeader()
{
  Bitmaps::FileHeader header;

  header.setSignatureBytes("BM");
  header.setFileSizeInBytes(786486);
  header.setReservedBytes(0);
  header.setPixelArrayOffsetInBytes(54);

  return header;
}

Bitmaps::DibHeader BitmapFormatsTest::rgbDibHeader()
{
  Bitmaps::DibHeader header;

  header.setWidthInPixels(2);
  header.setHeightInPixels(2);
  header.setNumberOfColourPlanes(1);
  header.setBitsPerPixel(24);

  return header;
}