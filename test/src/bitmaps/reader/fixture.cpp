#include <gtest/gtest.h>

#include "src/bitmaps/packet/packet.h"
#include "src/bitmaps/reader/bitmap_reader.h"
#include "src/bitmaps/formats/formats.h"
#include "test/src/bitmaps/reader/fixture.h"

BitmapReaderTest::BitmapReaderTest()
{
  this->setupCorrectPacket();
}

BitmapReaderTest::~BitmapReaderTest()
{

}

Bitmaps::Packet BitmapReaderTest::readBlueFile()
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