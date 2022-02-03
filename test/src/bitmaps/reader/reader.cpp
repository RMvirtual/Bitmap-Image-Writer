#include <gtest/gtest.h>

#include "test/src/bitmaps/reader/fixture.h"

TEST_F(BitmapReaderTest, ShouldReadFileHeader)
{
  auto packet = this->readBlueFile();
  this->compare(packet.fileHeader);
}

TEST_F(BitmapReaderTest, ShouldReadDibHeader)
{
  auto packet = this->readBlueFile();
  this->compare(packet.dibHeader);
}

TEST_F(BitmapReaderTest, ShouldReadPixelArray)
{
  auto packet = this->readBlueFile();
  this->compare(packet.pixelArray);
}