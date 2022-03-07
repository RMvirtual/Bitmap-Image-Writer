#include <gtest/gtest.h>
#include <string>

#include "src/main/cpp/files/paths/file.h"

TEST(PathsFile, ShouldGetFilePath)
{  
  auto path = Files::FilePaths::path("alphabet_2d");
  std::string correctPath {"resources/alphabet/2d.json"};

  EXPECT_EQ(correctPath, path);
}