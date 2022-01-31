#include <gtest/gtest.h>
#include "src/utilities/filesystem.h"

TEST(Filesystem, ShouldGetSizeOfFile)
{ 
  char* bitmapFile = (
    "C:\\Users\\rmvir\\Desktop\\scc300-Win3D\\test\\resources\\" \
    "correct-resources\\blueImage512x512.bmp"
  );

  int correctSize = 786486;
  int fileSizeInBytes = Utilities::getSizeOfFile(bitmapFile);

  EXPECT_EQ(correctSize, fileSizeInBytes);
}