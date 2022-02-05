#include <gtest/gtest.h>
#include "test/src/bitmaps/image/fixture.h"

TEST_F(BitmapImageTest, ShouldWriteImageToFile)
{  
  this->image.writeToFile(this->filePath);
}