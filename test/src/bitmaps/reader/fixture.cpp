#include <gtest/gtest.h>

#include "src/bitmaps/packet/packet.h"
#include "src/bitmaps/reader/bitmap_reader.h"
#include "src/bitmaps/formats/formats.h"
#include "test/src/bitmaps/reader/fixture.h"
#include "src/utilities/filesystem.h"

BitmapReaderTest::BitmapReaderTest()
{
  this->setupCorrectPacket();
  this->fileContents = Utilities::readFileToByteArray(this->blueImagePath());
}

BitmapReaderTest::~BitmapReaderTest()
{

}

std::string BitmapReaderTest::blueImagePath()
{
  return (
    "C:\\Users\\rmvir\\Desktop\\scc300-Win3D\\test\\resources\\"
    "correct-resources\\blueImage512x512.bmp"
  );
}