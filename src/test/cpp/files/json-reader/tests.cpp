#include <string>

#include "gtest/gtest.h"
#include "src/test/cpp/files/json-reader/fixture.h"

TEST_F(JSONReaderTest, ShouldReadFromArrayFile)
{
  this->asArrayFile();

  auto value = this->reader.value<std::string>(1, "name");
  std::string correctValue = "arrayObject2";

  EXPECT_EQ(correctValue, value);
}

TEST_F(JSONReaderTest, ShouldReadFromObjectFile)
{
  this->asObjectFile();

  auto value = this->reader.value<std::string>("name");
  std::string correctValue = "object1";

  EXPECT_EQ(correctValue, value);
}

TEST_F(JSONReaderTest, ShouldGetNumberOfObjects)
{
  this->asArrayFile();

  int correctNumberOfObjects = 4; // Based on manually observed amount in file.
  EXPECT_EQ(correctNumberOfObjects, this->reader.numberOfObjects());
}

TEST_F(JSONReaderTest, ShouldGetArrayFromObjectKeyInArrayFile)
{
  this->asArrayFile();

  auto array = this->reader.value<std::vector<double>>("surface_level_array");
  std::vector<double> correctArray = {0,1,2,3};

  int noOfElements = array.size();

  ASSERT_EQ(correctArray.size(), noOfElements);

  for (int i = 0; i < noOfElements; i++)
    EXPECT_EQ(correctArray[i], array[i]);
}