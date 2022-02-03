#include <gtest/gtest.h>

#include "test/src/bitmaps/reader/fixture.h"
#include "src/bitmaps/formats/formats.h"

TEST_F(BitmapReaderTest, ShouldReadFileHeader)
{
  this->loadBluePixelFileHeader();
  auto header = this->readPacket().fileHeader;
 
  this->compare(header);
}

TEST_F(BitmapReaderTest, ShouldReadDibHeader)
{
  this->loadBluePixelDibHeader();
  auto header = this->readPacket().dibHeader;

  this->compare(header);
}

TEST_F(BitmapReaderTest, ShouldReadPixelArray)
{
  this->loadBluePixelArray();
  auto pixelArray = this->readPacket().pixelArray;
  
  this->compare(pixelArray);
}