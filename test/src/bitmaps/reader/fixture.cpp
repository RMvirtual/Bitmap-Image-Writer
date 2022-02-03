#include "src/bitmaps/packet/packet.h"
#include "src/bitmaps/reader/bitmap_reader.h"
#include "src/bitmaps/formats/formats.h"
#include "test/src/bitmaps/reader/fixture.h"

BitmapReaderTest::BitmapReaderTest()
{
  this->initialiseFileHeader();
  this->initialiseDibHeader();
  this->initialisePixelArray();
}

BitmapReaderTest::~BitmapReaderTest()
{

}

Bitmaps::Packet BitmapReaderTest::readPacket()
{
  return this->reader.read(this->blueImagePath());
}

std::string BitmapReaderTest::blueImagePath()
{
  return (
    "C:\\Users\\rmvir\\Desktop\\scc300-Win3D\\test\\resources\\"
    "correct-resources\\blueImage512x512.bmp"
  );
}

Bitmaps::Packet BitmapReaderTest::blueBitmapPacket()
{
  this->loadBluePixelFileHeader();
  this->loadBluePixelDibHeader();
  this->loadBluePixelArray();

  Bitmaps::Packet packet;
  packet.fileHeader = this->fileHeader;
  packet.dibHeader = this->dibHeader;
  packet.pixelArray = this->pixelArray;

  return packet;
}

Bitmaps::Headers BitmapReaderTest::bluePixelHeaders()
{
  this->loadBluePixelFileHeader();
  this->loadBluePixelDibHeader();

  Bitmaps::Headers headers;
  headers.fileHeader = this->fileHeader;
  headers.dibHeader = this->dibHeader;

  return headers;
}

void BitmapReaderTest::loadBluePixelFileHeader()
{
  this->fileHeader.setSignatureBytes("BM");
  this->fileHeader.setFileSizeInBytes(786486);
  this->fileHeader.setReservedBytes(0);
  this->fileHeader.setPixelArrayOffsetInBytes(54);
}

void BitmapReaderTest::loadBluePixelDibHeader()
{
  this->dibHeader.setWidthInPixels(512);
  this->dibHeader.setHeightInPixels(512);
  this->dibHeader.setNumberOfColourPlanes(1);
  this->dibHeader.setBitsPerPixel(24);
}

void BitmapReaderTest::loadBluePixelArray()
{
  Bitmaps::Format format;
  format.setWidthInPixels(512);
  format.setHeightInPixels(512);
  format.setName("RGB");
  format.setBitsPerPixel(24);
  format.setColourNames({"red", "blue", "green"});

  this->pixelArray = {format};
  this->loadBlueColours();
}

void BitmapReaderTest::loadBluePixelArray(int width, int height)
{
  Bitmaps::Format format;
  format.setWidthInPixels(width);
  format.setHeightInPixels(height);
  format.setName("RGBA");
  format.setBitsPerPixel(32);
  format.setColourNames({"alpha", "blue", "green", "red"});

  this->pixelArray = {format};
  this->loadBlueColoursWithAlpha();
}

void BitmapReaderTest::loadBlueColours()
{
  Bitmaps::Colours colours;
  colours["red"] = 100;
  colours["green"] = 255;
  colours["blue"] = 255;

  this->pixelArray.fill(colours);
}

void BitmapReaderTest::loadBlueColoursWithAlpha()
{
  Bitmaps::Colours colours;
  colours["alpha"] = 255;
  colours["red"] = 100;
  colours["green"] = 255;
  colours["blue"] = 255;

  this->pixelArray.fill(colours);
}

void BitmapReaderTest::loadWhiteColours()
{
  Bitmaps::Colours colours;
  colours["red"] = 255;
  colours["green"] = 255;
  colours["blue"] = 255;

  this->pixelArray.fill(colours);
}

void BitmapReaderTest::initialiseFileHeader()
{
  this->fileHeader.setSignatureBytes("BM");
  this->fileHeader.setFileSizeInBytes(786486);
  this->fileHeader.setReservedBytes(0);
  this->fileHeader.setPixelArrayOffsetInBytes(54);
}

void BitmapReaderTest::initialiseDibHeader()
{
  this->dibHeader.setWidthInPixels(512);
  this->dibHeader.setHeightInPixels(512);
  this->dibHeader.setNumberOfColourPlanes(1);
  this->dibHeader.setBitsPerPixel(24);
}

void BitmapReaderTest::initialisePixelArray()
{
  Bitmaps::Format format;
  format.setWidthInPixels(512);
  format.setHeightInPixels(512);
  format.setName("RGB");
  format.setBitsPerPixel(24);
  format.setColourNames({"red", "blue", "green"});

  this->pixelArray.setFormat(format);
  this->pixelArray.fill(this->colours);
}

void BitmapReaderTest::initialiseColours()
{
  this->colours["red"] = 100;
  this->colours["green"] = 255;
  this->colours["blue"] = 255;
}