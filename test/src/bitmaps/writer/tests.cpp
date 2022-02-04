#include <gtest/gtest.h>

#include "test/src/bitmaps/writer/fixture.h"

TEST_F(BitmapWriterTest, ShouldConvertFileHeaderToBytes)
{
  auto header = this->packet.fileHeader;
  auto bytes = this->writer.convertToBytes(header);

  this->compareToFileHeader(bytes);
}

TEST_F(BitmapWriterTest, ShouldConvertDibHeaderToBytes)
{
  auto header = this->packet.dibHeader;
  auto bytes = this->writer.convertToBytes(header);
  
  this->compareToDibHeader(bytes);
}

TEST_F(BitmapWriterTest, ShouldConvertPixelArrayToBytes)
{
  auto pixelArray = this->packet.pixelArray;
  auto bytes = this->writer.convertToBytes(pixelArray);

  this->compareToPixelArray(bytes);
}

TEST_F(BitmapWriterTest, ShouldConvertColoursToBytes)
{
  auto colours = this->colours;
  auto bytes = this->writer.convertToBytes(colours);

  this->compareToColours(bytes);
}