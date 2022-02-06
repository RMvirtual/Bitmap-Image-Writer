#include <gtest/gtest.h>
#include "test/src/bitmaps/image/fixture.h"

TEST_F(BitmapImageTest, ShouldGetCorrectWidthAndHeight)
{
  this->setup2x2Image();
  ASSERT_EQ(2, this->image.widthInPixels());
  ASSERT_EQ(2, this->image.heightInPixels());

  this->setup3x5Image();
  ASSERT_EQ(3, this->image.widthInPixels());
  ASSERT_EQ(5, this->image.heightInPixels());
}

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