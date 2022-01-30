#include <gtest/gtest.h>
#include "src/utilities/json_reader.h"

#include <vector>
#include <string>

Utilities::JSONReader getJsonReader()
{
  std::string jsonFile {
    "C://Users/rmvir/Desktop/scc300-Win3D/resources/filesystem.json"};

  Utilities::JSONReader reader {};
  reader.read(jsonFile);

  return reader;
}

TEST(JSONReaderTests, ShouldGetFieldNames)
{
  auto reader = getJsonReader();
  auto fieldNames = reader.fieldNames();

  std::string correctFieldName {"pixel_formats"};

  EXPECT_EQ(fieldNames[0], correctFieldName);
}

TEST(JSONReaderTests, ShouldGetValueFromField)
{
  auto reader = getJsonReader();
  std::string correctValue {"resources/pixel_formats.json"};

  EXPECT_EQ(correctValue, reader.value("pixel_formats"));
}