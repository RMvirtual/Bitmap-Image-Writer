#include <gtest/gtest.h>
#include "test/src/bitmaps/writer/fixture.h"

TEST_F(BitmapWriterTest, ShouldWritePacketToBytes)
{
  auto bytes = this->writer.write(this->packet);
  this->compareToPacket(bytes);
}

TEST_F(BitmapWriterTest, ShouldWriteFileHeaderToBytes)
{
  auto bytes = this->writer.write(this->packet.fileHeader);
  this->compareToFileHeader(bytes);
}

TEST_F(BitmapWriterTest, ShouldWriteDibHeaderToBytes)
{
  auto bytes = this->writer.write(this->packet.dibHeader); 
  this->compareToDibHeader(bytes);
}

TEST_F(BitmapWriterTest, ShouldWritePixelArrayToBytes)
{
  auto bytes = this->writer.write(this->packet.pixelArray);
  this->compareToPixelArray(bytes);
}