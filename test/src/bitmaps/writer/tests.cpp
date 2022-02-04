#include <gtest/gtest.h>
#include "test/src/bitmaps/writer/fixture.h"

TEST_F(BitmapWriterTest, ShouldConvertPacketToBytes)
{
  auto bytes = this->writer.convertToBytes(this->packet);
  this->compareToPacket(bytes);
}

TEST_F(BitmapWriterTest, ShouldConvertFileHeaderToBytes)
{
  auto bytes = this->writer.convertToBytes(this->packet.fileHeader);
  this->compareToFileHeader(bytes);
}

TEST_F(BitmapWriterTest, ShouldConvertDibHeaderToBytes)
{
  auto bytes = this->writer.convertToBytes(this->packet.dibHeader); 
  this->compareToDibHeader(bytes);
}

TEST_F(BitmapWriterTest, ShouldConvertPixelArrayToBytes)
{
  auto bytes = this->writer.convertToBytes(this->packet.pixelArray);
  this->compareToPixelArray(bytes);
}

TEST_F(BitmapWriterTest, ShouldConvertColoursToBytes)
{
  auto bytes = this->writer.convertToBytes(this->colours);
  this->compareToColours(bytes);
}