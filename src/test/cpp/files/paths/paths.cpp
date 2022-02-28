#include <gtest/gtest.h>
#include <string>

#include "src/main/cpp/files/paths/file.h"

TEST(FileSystemFile, ShouldGetFilePath)
{
  Files::FilePaths file {};
  std::string correctValue {"resources/pixel_formats.json"};

  EXPECT_EQ(correctValue, file.filePath("pixel_formats"));
}