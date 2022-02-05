#include <gtest/gtest.h>

#include "src/bitmaps/writer/writer.h"
#include "src/containers/byte-array/byte_conversion.h"
#include "test/src/bitmaps/writer/fixture.h"
#include "src/bitmaps/formats/formats.h"

#include <iostream>

BitmapWriterTest::BitmapWriterTest()
{
  this->setupFileHeader();
  this->setupDibHeader();
  this->setupPixelArray();
}

BitmapWriterTest::~BitmapWriterTest()
{

}

void BitmapWriterTest::setupFileHeader()
{
  this->packet.fileHeader.setSignatureBytes("BM");
  this->packet.fileHeader.setFileSizeInBytes(66);
  this->packet.fileHeader.setReservedBytes(0);
  this->packet.fileHeader.setPixelArrayOffsetInBytes(54);
}

void BitmapWriterTest::setupDibHeader()
{
  this->packet.dibHeader.setWidthInPixels(2);
  this->packet.dibHeader.setHeightInPixels(2);
  this->packet.dibHeader.setNumberOfColourPlanes(1);
  this->packet.dibHeader.setBitsPerPixel(24);
}

void BitmapWriterTest::setupPixelArray()
{
  auto& header = this->packet.dibHeader;

  auto format = Bitmaps::format(header.bitsPerPixel());
  format.setWidthInPixels(header.widthInPixels());
  format.setHeightInPixels(header.heightInPixels());

  this->packet.pixelArray = {format};
  this->setupColours();
}

void BitmapWriterTest::setupColours()
{
  Bitmaps::Colours colours {"blue", "green", "red"};
  colours["blue"] = 255;
  colours["green"] = 255;
  colours["red"] = 100;

  this->packet.pixelArray.fill(colours);
  this->colours = colours;
}