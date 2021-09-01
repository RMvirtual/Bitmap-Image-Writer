#include <gtest/gtest.h>
#include <iostream>
#include <vector>

#include "src/common/filesystem.h"

TEST(FilesystemTests, ShouldGetSizeOfFile)
{ 
  char* bitmapFile = (
    "C:\\Users\\rmvir\\Desktop\\scc300-Win3D\\test\\resources\\" \
    "correct-resources\\blueImage512x512.bmp"
  );

  int correctSize = 786486;
  int fileSizeInBytes = Filesystem::getSizeOfFile(bitmapFile);

  EXPECT_EQ(correctSize, fileSizeInBytes);
}