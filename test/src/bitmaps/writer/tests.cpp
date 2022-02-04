#include <gtest/gtest.h>
#include "test/src/bitmaps/writer/fixture.h"

#include <iostream>

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
  auto bytes = this->writer.convertToBytes(this->packet.pixelArray);
  this->compareToPixelArray(bytes);
}

TEST_F(BitmapWriterTest, ShouldConvertColoursToBytes)
{
  auto bytes = this->writer.convertToBytes(this->colours);

  std::cout << "Bytes received: " << bytes.size() << "\n";

  this->compareToColours(bytes);
}