#include <gtest/gtest.h>
#include "src/test/cpp/bitmaps/formats/fixture.h"
#include <src/main/cpp/bitmaps/packet/headers/headers.h>

void BitmapFormatsTest::setupRGBAFormat()
{
  this->format.setName("RGBA32");
  this->format.setBitsPerPixel(32);
  this->format.setColourNames({"alpha", "blue", "green", "red"});
}

void BitmapFormatsTest::setupRGBFormat()
{
  this->format.setName("RGB24");
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

std::shared_ptr<Bitmaps::FileHeader> BitmapFormatsTest::rgbFileHeader()
{
  auto header = std::make_shared<Bitmaps::FileHeader>();

  header->setSignatureBytes("BM");
  header->setFileSizeInBytes(786486);
  header->setReservedBytes(0);
  header->setPixelArrayOffsetInBytes(54);

  return header;
}

std::shared_ptr<Bitmaps::DibHeader> BitmapFormatsTest::rgbDibHeader()
{
  auto header = std::make_shared<Bitmaps::DibHeader>();

  header->setWidthInPixels(2);
  header->setHeightInPixels(2);
  header->setNumberOfColourPlanes(1);
  header->setBitsPerPixel(24);

  return header;
}