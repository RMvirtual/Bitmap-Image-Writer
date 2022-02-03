#include "src/bitmaps/packet/packet.h"
#include "src/bitmaps/packet/headers/headers.h"
#include "src/bitmaps/formats/format.h"
#include "src/bitmaps/packet/pixel-array/array.h"
#include "src/bitmaps/packet/pixel-array/colours.h"
#include "test/src/bitmaps/packet/fixture.h"

BitmapPacketTest::BitmapPacketTest()
{
  this->initialiseFileHeader();
  this->initialiseDibHeader();
  this->initialisePixelArray();
}

BitmapPacketTest::~BitmapPacketTest()
{

}

void BitmapPacketTest::initialiseFileHeader()
{
  this->fileHeader.setSignatureBytes("BM");
  this->fileHeader.setFileSizeInBytes(786486);
  this->fileHeader.setReservedBytes(0);
  this->fileHeader.setPixelArrayOffsetInBytes(54);
}

void BitmapPacketTest::initialiseDibHeader()
{
  this->dibHeader.setWidthInPixels(512);
  this->dibHeader.setHeightInPixels(512);
  this->dibHeader.setNumberOfColourPlanes(1);
  this->dibHeader.setBitsPerPixel(24);
}

void BitmapPacketTest::initialisePixelArray()
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

void BitmapPacketTest::initialiseColours()
{
  this->colours["red"] = 100;
  this->colours["green"] = 255;
  this->colours["blue"] = 255;
}

std::string BitmapPacketTest::blueImagePath()
{
  return (
    "C:\\Users\\rmvir\\Desktop\\scc300-Win3D\\test\\resources\\"
    "correct-resources\\blueImage512x512.bmp"
  );
}

Bitmaps::Packet BitmapPacketTest::blueBitmapPacket()
{
  Bitmaps::Packet packet;
  packet.fileHeader = bluePixelFileHeader();
  packet.dibHeader = bluePixelDibHeader();
  packet.pixelArray = bluePixelArray();

  return packet;
}

Bitmaps::Headers BitmapPacketTest::bluePixelHeaders()
{
  Bitmaps::Headers headers {};
  headers.fileHeader = bluePixelFileHeader();
  headers.dibHeader = bluePixelDibHeader();

  return headers;
}

Bitmaps::FileHeader BitmapPacketTest::bluePixelFileHeader()
{
  Bitmaps::FileHeader fileHeader;

  fileHeader.setSignatureBytes("BM");
  fileHeader.setFileSizeInBytes(786486);
  fileHeader.setReservedBytes(0);
  fileHeader.setPixelArrayOffsetInBytes(54);

  return fileHeader;
}

Bitmaps::DibHeader BitmapPacketTest::bluePixelDibHeader()
{
  Bitmaps::DibHeader dibHeader {};

  dibHeader.setWidthInPixels(512);
  dibHeader.setHeightInPixels(512);
  dibHeader.setNumberOfColourPlanes(1);
  dibHeader.setBitsPerPixel(24);

  return dibHeader;
}

Bitmaps::PixelArray BitmapPacketTest::bluePixelArray()
{
  Bitmaps::Format format;
  format.setWidthInPixels(512);
  format.setHeightInPixels(512);
  format.setName("RGB");
  format.setBitsPerPixel(24);
  format.setColourNames({"red", "blue", "green"});

  Bitmaps::PixelArray pixelArray {format};
  pixelArray.fill(this->blueColours());

  return pixelArray;
}

Bitmaps::PixelArray BitmapPacketTest::bluePixelArray(int width, int height)
{
  Bitmaps::Format format;
  format.setWidthInPixels(width);
  format.setHeightInPixels(height);
  format.setName("RGBA");
  format.setBitsPerPixel(32);
  format.setColourNames({"alpha", "blue", "green", "red"});

  Bitmaps::PixelArray pixelArray {format};
  pixelArray.fill(this->blueColoursWithAlpha());

  return pixelArray;
}

void BitmapPacketTest::loadRedPixelArray()
{
  Bitmaps::Format format;
  format.setWidthInPixels(2);
  format.setHeightInPixels(2);
  format.setName("RGB");
  format.setBitsPerPixel(24);
  format.setColourNames({"red", "blue", "green"});

  this->pixelArray.setFormat(format);
  this->pixelArray.fill(this->redColours());
}

Bitmaps::Colours BitmapPacketTest::redColours()
{
  Bitmaps::Colours colours;
  colours["red"] = 255;
  colours["green"] = 0;
  colours["blue"] = 0;

  return colours;
}

Bitmaps::Colours BitmapPacketTest::greenColours()
{
  Bitmaps::Colours colours;
  colours["red"] = 0;
  colours["green"] = 255;
  colours["blue"] = 0;

  return colours;
}

Bitmaps::Colours BitmapPacketTest::blueColours()
{
  Bitmaps::Colours colours;
  colours["red"] = 100;
  colours["green"] = 255;
  colours["blue"] = 255;

  return colours;
}

Bitmaps::Colours BitmapPacketTest::blueColoursWithAlpha()
{
  Bitmaps::Colours colours;
  colours["alpha"] = 255;
  colours["red"] = 100;
  colours["green"] = 255;
  colours["blue"] = 255;

  return colours;
}

Bitmaps::Colours BitmapPacketTest::whiteColours()
{
  Bitmaps::Colours colours;
  colours["red"] = 255;
  colours["green"] = 255;
  colours["blue"] = 255;

  return colours;
}