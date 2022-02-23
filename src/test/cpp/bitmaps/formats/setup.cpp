#include <gtest/gtest.h>
#include "src/test/cpp/bitmaps/formats/fixture.h"

void BitmapFormatsTest::setupRGBAFormat()
{
  this->format.setName("RGBA");
  this->format.setBitsPerPixel(32);
  this->format.setColourNames({"alpha", "blue", "green", "red"});
}

void BitmapFormatsTest::setupRGBFormat()
{
  this->format.setName("RGB");
  this->format.setBitsPerPixel(24);
  this->format.setColourNames({"blue", "green", "red"});
}

void BitmapFormatsTest::setupRGBFormat(int width, int height)
{
  this->setupRGBFormat();
  this->format.setWidthInPixels(width);
  this->format.setHeightInPixels(height);
}

void BitmapFormatsTest::setupRGBColours()
{
  this->setupRGBFormat();

  this->colours = this->format.colours();
  this->colours["red"] = 3;
  this->colours["green"] = 2;
  this->colours["blue"] = 1;
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