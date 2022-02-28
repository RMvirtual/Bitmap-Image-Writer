#include <gtest/gtest.h>
#include <string>

#include "src/main/cpp/files/json-reader/json_reader.h"

Files::JSONReader getJsonReader()
{
  std::string jsonFile {
    "C://Users/rmvir/Desktop/scc300-Win3D/resources/filesystem.json"};

  Files::JSONReader reader {};
  reader.read(jsonFile);

  return reader;
}

TEST(JSONReader, ShouldGetFieldNames)
{
  auto reader = getJsonReader();
  auto fieldNames = reader.fieldNames();

  std::string correctFieldName {"pixel_formats"};

  EXPECT_EQ(fieldNames[0], correctFieldName);
}

TEST(JSONReader, ShouldGetValueFromField)
{
  auto reader = getJsonReader();
  std::string correctValue {"resources/pixel_formats.json"};

  EXPECT_EQ(correctValue, reader.value<std::string>("pixel_formats"));
}

TEST(JSONReader, ShouldGetNumberOfObjects)
{
  auto reader = getJsonReader();

  EXPECT_EQ(1, reader.numberOfObjects());
}