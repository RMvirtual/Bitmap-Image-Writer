#include <string>

#include "gtest/gtest.h"
#include "src/test/cpp/files/json-reader/fixture.h"

TEST_F(JSONReaderTest, ShouldReadFromArrayFileWithIndex)
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

  int correctNumberOfObjects = 2; // Based on manually observed amount in file.
  EXPECT_EQ(correctNumberOfObjects, this->reader.numberOfObjects());
}

TEST_F(JSONReaderTest, ShouldGetArrayFromObjectKeyInObjectFile)
{
  this->asObjectFile();

  auto array = this->reader.value<std::vector<double>>("surface_level_array");
  std::vector<double> correctArray = {0,1,2,3};

  int noOfElements = array.size();

  ASSERT_EQ(correctArray.size(), noOfElements);

  for (int i = 0; i < noOfElements; i++)
    EXPECT_EQ(correctArray[i], array[i]);
}

TEST_F(JSONReaderTest, ShouldGetNestedArrayFromObjectKeyInObjectFile)
{
  this->asObjectFile();

  auto array = this->reader.value<std::vector<std::vector<double>>>(
    "nested_array");

  std::vector<std::vector<double>> correctArray = {
    {0,1}, {2,3}, {4,5}, {6,7}, {8,9}};

  int noOfElements = array.size();
  ASSERT_EQ(correctArray.size(), noOfElements);

  for (int i = 0; i < noOfElements; i++) {
    auto correctSubArray = correctArray[i];
    auto subArray = array[i];

    int noOfSubElements = subArray.size();

    ASSERT_EQ(correctSubArray.size(), noOfSubElements);

    for (int j = 0; j < noOfSubElements; j++)
      EXPECT_EQ(correctArray[j], array[j]);
  }
}

TEST_F(JSONReaderTest, ShouldGetValueFromSpecificObjectInObjectFiles)
{
  this->asNestedObjectsFile();
  auto value = this->reader.value<int>("object2", "value1");
  int correctValue = 3;

  EXPECT_EQ(correctValue, value);
}