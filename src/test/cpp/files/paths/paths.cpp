#include <gtest/gtest.h>
#include <string>

#include "src/main/cpp/files/paths/file.h"

TEST(PathsFile, ShouldGetFilePath)
{
  ASSERT_TRUE(false);
  
  Files::FilePaths file {};
  std::string correctValue {"resources/alphabet/2d.json"};

  EXPECT_EQ(correctValue, file.filePath("alphabet_2d"));
}