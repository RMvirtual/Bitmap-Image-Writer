#include <gtest/gtest.h>

#include "test/src/bitmaps/reader/fixture.h"

TEST_F(BitmapReaderTest, ShouldReadFileHeaderFromFile)
{
  auto packet = this->readBlueFile();
  this->compare(packet.fileHeader);
}

TEST_F(BitmapReaderTest, ShouldReadDibHeaderFromFile)
{
  auto packet = this->readBlueFile();
  this->compare(packet.dibHeader);
}

TEST_F(BitmapReaderTest, ShouldReadPixelArrayFromFile)
{
  auto packet = this->readBlueFile();
  this->compare(packet.pixelArray);
}