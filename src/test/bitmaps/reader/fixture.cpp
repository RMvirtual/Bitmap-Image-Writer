#include <gtest/gtest.h>

#include "src/main/bitmaps/packet/packet.h"
#include "src/main/bitmaps/reader/image/reader.h"
#include "src/main/bitmaps/formats/formats.h"
#include "src/test/bitmaps/reader/fixture.h"
#include "src/main/utilities/filesystem.h"

BitmapReaderTest::BitmapReaderTest()
{
  this->setupCorrectImage();
  this->fileContents = Utilities::readFileToByteArray(this->blueImagePath());
}

BitmapReaderTest::~BitmapReaderTest()
{

}

std::string BitmapReaderTest::blueImagePath()
{
  return (
    "C:\\Users\\rmvir\\Desktop\\scc300-Win3D\\src\\test\\resources\\"
    "correct-resources\\blueImage2x2.bmp"
  );
}