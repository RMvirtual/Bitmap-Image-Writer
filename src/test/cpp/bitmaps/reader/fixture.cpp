#include "gtest/gtest.h"
#include "src/main/cpp/bitmaps/packet/packet.h"
#include "src/main/cpp/bitmaps/reader/image/reader.h"
#include "src/main/cpp/bitmaps/formats/formats.h"
#include "src/test/cpp/bitmaps/reader/fixture.h"
#include "src/main/cpp/files/stream/filestream.h"

BitmapReaderTest::BitmapReaderTest()
{
  this->setupCorrectImage();
  this->fileContents = Files::readFileToByteArray(this->blueImagePath());
}

BitmapReaderTest::~BitmapReaderTest()
{

}

std::string BitmapReaderTest::blueImagePath()
{
  return (
    "C:\\Users\\rmvir\\Desktop\\scc300-Win3D\\resources\\test\\"
    "correct-resources\\blueImage2x2.bmp"
  );
}