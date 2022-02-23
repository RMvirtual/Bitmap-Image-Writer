#include <gtest/gtest.h>

#include "src/main/bitmaps/packet/packet.h"
#include "src/main/bitmaps/packet/headers/headers.h"
#include "src/main/bitmaps/formats/format/format.h"
#include "src/main/bitmaps/packet/pixel-array/array.h"
#include "src/main/bitmaps/formats/colours/colours.h"
#include "src/test/bitmaps/packet/fixture.h"

BitmapPacketTest::BitmapPacketTest()
{
  this->setupRedPixelArray();
}

BitmapPacketTest::~BitmapPacketTest()
{

}

void BitmapPacketTest::setupRedPixelArray()
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

void BitmapPacketTest::isGreen(Bitmaps::Colours& colour)
{
  EXPECT_EQ(colour["green"], 255);
  EXPECT_EQ(colour["blue"], 0);
  EXPECT_EQ(colour["red"], 0);
}