#include <string>

#include "gtest/gtest.h"
#include "src/test/cpp/files/json-reader/fixture.h"

TEST_F(JSONReaderTest, ShouldReadFromArrayFile)
{
  std::string filePath = {
    "C://Users/rmvir/Desktop/scc300-Win3D/resources/test/json-files/array_file.json"};

  this->reader = Files::JSONReader::fromArrayFile(filePath);
  auto value = this->reader.value<std::string>(1, "name");
  std::string correctValue = "arrayObject2";

  EXPECT_EQ(correctValue, value);
}

TEST_F(JSONReaderTest, ShouldReadFromObjectFile)
{
  std::string filePath = {
    "C://Users/rmvir/Desktop/scc300-Win3D/resources/test/json-files/object_file.json"};

  this->reader = Files::JSONReader::fromObjectFile(filePath);

  auto value = this->reader.value<std::string>("name");
  std::string correctValue = "object1";

  EXPECT_EQ(correctValue, value);
}

TEST_F(JSONReaderTest, ShouldGetNumberOfObjects)
{
  EXPECT_TRUE(false);
}