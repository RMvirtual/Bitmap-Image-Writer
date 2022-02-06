#include <gtest/gtest.h>
#include "test/src/bitmaps/image/fixture.h"

TEST_F(BitmapImageTest, ShouldWrite2x2BlueImageToFile)
{
  this->setup2x2Image();
  this->image.writeToFile(this->filePath);
}

TEST_F(BitmapImageTest, ShouldWrite1x4BlueImageToFile)
{
  this->setup1x4Image();
  this->image.writeToFile(this->filePath);
}

TEST_F(BitmapImageTest, ShouldWrite3x5BlueImageToFile)
{
  this->setup3x5Image();
  this->image.writeToFile(this->filePath);
}