#include <gtest/gtest.h>
#include "src/utilities/file_system_reader.h"

#include <string>

TEST(FileSystemReaderTests, ShouldGetFileSystemNames)
{
  Utilities::FileSystemReader reader {};
  auto fieldNames = reader.fieldNames();
  std::string correctFieldName {"pixel_formats"};

  EXPECT_EQ(fieldNames[0], correctFieldName);
}

TEST(FileSystemReaderTests, ShouldGetFilePath)
{
  Utilities::FileSystemReader reader {};
  std::string correctValue {"resources/pixel_formats.json"};

  EXPECT_EQ(correctValue, reader.filePath("pixel_formats"));
}