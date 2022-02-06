#include <gtest/gtest.h>
#include "test/src/bitmaps/writer/fixture.h"

TEST_F(BitmapWriterTest, ShouldWrite2x2BlueImageToFile)
{
  this->setup2x2Image();
  this->writer.writeToFile(this->image, this->filePath);

  this->compareWrittenFile();
}

TEST_F(BitmapWriterTest, ShouldWrite1x4BlueImageToFile)
{
  this->setup1x4Image();
  this->writer.writeToFile(this->image, this->filePath);

  this->compareWrittenFile();
}

TEST_F(BitmapWriterTest, ShouldWrite3x5BlueImageToFile)
{
  this->setup3x5Image();
  this->writer.writeToFile(this->image, this->filePath);

  this->compareWrittenFile();
}