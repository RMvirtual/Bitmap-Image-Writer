#include <gtest/gtest.h>
#include <string>

#include "src/utilities/file_paths_file.h"

TEST(FileSystemFile, ShouldGetFilePath)
{
  Utilities::FilePathsFile reader {};
  std::string correctValue {"resources/pixel_formats.json"};

  EXPECT_EQ(correctValue, reader.filePath("pixel_formats"));
}