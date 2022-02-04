#include <gtest/gtest.h>
#include "test/src/bitmaps/image/fixture.h"

TEST_F(BitmapImageTest, ShouldWriteImageToFile)
{  
  std::string filePath = (
    "C:\\Users\\rmvir\\Desktop\\scc300-Win3D\\test\\resources\\"
    "correct-resources\\blueImage2x2.bmp"
  );

  this->image.writeToFile(filePath);
}