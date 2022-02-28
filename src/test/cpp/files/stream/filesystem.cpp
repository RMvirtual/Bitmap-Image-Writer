#include <gtest/gtest.h>
#include "src/main/cpp/files/stream/filestream.h"

TEST(Filesystem, ShouldGetSizeOfFile)
{ 
  char* bitmapFile = (
    "C:\\Users\\rmvir\\Desktop\\scc300-Win3D\\resources\\test\\" \
    "correct-resources\\blueImage512x512.bmp"
  );

  int correctSize = 786486;
  int fileSizeInBytes = Files::getSizeOfFile(bitmapFile);

  EXPECT_EQ(correctSize, fileSizeInBytes);
}