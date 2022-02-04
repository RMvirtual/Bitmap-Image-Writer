#include "test/src/bitmaps/reader/fixture.h"

void BitmapReaderTest::setupCorrectPacket()
{
  this->setupFileHeader();
  this->setupDibHeader();
  this->setupPixelArray();
}

void BitmapReaderTest::setupFileHeader()
{
  this->packet.fileHeader.setSignatureBytes("BM");
  this->packet.fileHeader.setFileSizeInBytes(786486);
  this->packet.fileHeader.setReservedBytes(0);
  this->packet.fileHeader.setPixelArrayOffsetInBytes(54);
}

void BitmapReaderTest::setupDibHeader()
{
  this->packet.dibHeader.setWidthInPixels(512);
  this->packet.dibHeader.setHeightInPixels(512);
  this->packet.dibHeader.setNumberOfColourPlanes(1);
  this->packet.dibHeader.setBitsPerPixel(24);
}

void BitmapReaderTest::setupPixelArray()
{
  Bitmaps::Format format;
  format.setWidthInPixels(512);
  format.setHeightInPixels(512);
  format.setName("RGB");
  format.setBitsPerPixel(24);
  format.setColourNames({"red", "blue", "green"});

  this->packet.pixelArray = {format};
  this->setupColours();
}

void BitmapReaderTest::setupColours()
{
  Bitmaps::Colours colours;
  colours["red"] = 100;
  colours["green"] = 255;
  colours["blue"] = 255;

  this->packet.pixelArray.fill(colours);
}