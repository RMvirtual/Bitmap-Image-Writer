#include <gtest/gtest.h>
#include "src/test/cpp/bitmaps/writer/fixture.h"

TEST_F(BitmapWriterTest, ShouldWriteImageWithRowStrideLessThanFourToFile)
{
  this->setup2x2Image();
  this->writer.writeToFile(this->image, this->filePath);

  this->compareWrittenFile();
}

TEST_F(BitmapWriterTest, ShouldWriteImageWithRowStrideOfFourToFile)
{
  this->setup1x4Image();
  this->writer.writeToFile(this->image, this->filePath);

  this->compareWrittenFile();
}

TEST_F(BitmapWriterTest, ShouldWriteImageWithRowStrideGreaterThanFourToFile)
{
  this->setup3x5Image();
  this->writer.writeToFile(this->image, this->filePath);

  this->compareWrittenFile();
}