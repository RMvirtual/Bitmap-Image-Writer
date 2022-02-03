#include <gtest/gtest.h>

#include "src/bitmaps/packet/packet.h"
#include "src/bitmaps/reader/bitmap_reader.h"
#include "src/bitmaps/formats/formats.h"
#include "test/src/bitmaps/reader/fixture.h"

BitmapReaderTest::BitmapReaderTest()
{
  this->initialiseCorrectPacket();
}

BitmapReaderTest::~BitmapReaderTest()
{

}

void BitmapReaderTest::initialiseCorrectPacket()
{
  this->loadCorrectFileHeader();
  this->loadCorrectDibHeader();
  this->loadCorrectPixelArray();
}

void BitmapReaderTest::compare(const Bitmaps::FileHeader& header)
{
  
}

void BitmapReaderTest::compare(const Bitmaps::DibHeader& header)
{

}

void BitmapReaderTest::compare(Bitmaps::PixelArray& array)
{
  
}

Bitmaps::Packet BitmapReaderTest::readBlueFile()
{
  auto filePath = this->blueImagePath();
  
  return this->reader.read(filePath);
}

std::string BitmapReaderTest::blueImagePath()
{
  return (
    "C:\\Users\\rmvir\\Desktop\\scc300-Win3D\\test\\resources\\"
    "correct-resources\\blueImage512x512.bmp"
  );
}

void BitmapReaderTest::loadCorrectFileHeader()
{
  this->packet.fileHeader.setSignatureBytes("BM");
  this->packet.fileHeader.setFileSizeInBytes(786486);
  this->packet.fileHeader.setReservedBytes(0);
  this->packet.fileHeader.setPixelArrayOffsetInBytes(54);
}

void BitmapReaderTest::loadCorrectDibHeader()
{
  this->packet.dibHeader.setWidthInPixels(512);
  this->packet.dibHeader.setHeightInPixels(512);
  this->packet.dibHeader.setNumberOfColourPlanes(1);
  this->packet.dibHeader.setBitsPerPixel(24);
}

void BitmapReaderTest::loadCorrectPixelArray()
{
  Bitmaps::Format format;
  format.setWidthInPixels(512);
  format.setHeightInPixels(512);
  format.setName("RGB");
  format.setBitsPerPixel(24);
  format.setColourNames({"red", "blue", "green"});

  this->packet.pixelArray = {format};
  this->loadColours();
}

void BitmapReaderTest::loadColours()
{
  Bitmaps::Colours colours;
  colours["red"] = 100;
  colours["green"] = 255;
  colours["blue"] = 255;

  this->packet.pixelArray.fill(colours);
}