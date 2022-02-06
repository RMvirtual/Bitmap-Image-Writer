#include "test/src/bitmaps/reader/fixture.h"
#include "src/bitmaps/formats/formats.h"

void BitmapReaderTest::setupCorrectPacket()
{
  this->setupFileHeader();
  this->setupDibHeader();
  this->setupPixelArray();
}

void BitmapReaderTest::setupFileHeader()
{
  this->packet.fileHeader.setSignatureBytes("BM");
  // 54 header bytes + 16 pixel bytes
  // Pixel bytes = (2row x 2column x 3pixelSize + (2row x 2 row padding bytes))
  this->packet.fileHeader.setFileSizeInBytes(70);
  this->packet.fileHeader.setReservedBytes(0);
  this->packet.fileHeader.setPixelArrayOffsetInBytes(54);
}

void BitmapReaderTest::setupDibHeader()
{
  this->packet.dibHeader.setWidthInPixels(2);
  this->packet.dibHeader.setHeightInPixels(2);
  this->packet.dibHeader.setNumberOfColourPlanes(1);
  this->packet.dibHeader.setBitsPerPixel(24);
  this->packet.dibHeader.setHorizontalResolution(3780); // Not sure how this 
  this->packet.dibHeader.setVerticalResolution(3780); // is calculated.
}

void BitmapReaderTest::setupPixelArray()
{
  auto format = Bitmaps::format(24);
  format.setWidthInPixels(this->packet.dibHeader.widthInPixels());
  format.setHeightInPixels(this->packet.dibHeader.heightInPixels());

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