#include <gtest/gtest.h>

#include "test/src/bitmaps/formats/fixture.h"
#include "src/bitmaps/packet/headers/headers.h"

BitmapFormatsTest::BitmapFormatsTest()
{
  this->loadRGBAFormat();
}

BitmapFormatsTest::~BitmapFormatsTest()
{

}

void BitmapFormatsTest::compare(Bitmaps::Format& format)
{
  EXPECT_EQ(this->format.name(), format.name());
  EXPECT_EQ(this->format.bitsPerPixel(), format.bitsPerPixel());
  EXPECT_EQ(this->format.colourNames().size(), format.colourNames().size());

  for (int col = 0; col < this->format.colourNames().size(); col++)
    EXPECT_EQ(this->format.colourNames()[col], format.colourNames()[col]);
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

Bitmaps::Headers BitmapFormatsTest::rgbHeaders()
{
  Bitmaps::Headers headers;
  headers.fileHeader = this->fileHeader();
  headers.dibHeader = this->dibHeader();

  return headers;
}

Bitmaps::FileHeader BitmapFormatsTest::fileHeader()
{
  Bitmaps::FileHeader header;

  header.setSignatureBytes("BM");
  header.setFileSizeInBytes(786486);
  header.setReservedBytes(0);
  header.setPixelArrayOffsetInBytes(54);

  return header;
}

Bitmaps::DibHeader BitmapFormatsTest::dibHeader()
{
  Bitmaps::DibHeader header;

  header.setWidthInPixels(2);
  header.setHeightInPixels(2);
  header.setNumberOfColourPlanes(1);
  header.setBitsPerPixel(24);

  return header;
}
