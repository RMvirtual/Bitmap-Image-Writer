#include <gtest/gtest.h>
#include "src/utilities/json_reader.h"

#include <vector>
#include <string>

Utilities::JSONReader configurateFileReader()
{
  Utilities::JSONReader reader {};
  reader.read(
    "C://Users/rmvir/Desktop/scc300-Win3D/resources/filesystem.json");

  return reader;
}

Utilities::JSONReader getPixelFormatLoadedReader()
{
  std::string pixelFormatsFilePath = {
    "C://Users/rmvir/Desktop/scc300-Win3D/resources/pixel_formats.json"};

  Utilities::JSONReader reader {};
  reader.read(pixelFormatsFilePath);

  return reader;
}

TEST(JSONReaderTests, ShouldGetFormatNameFromFirstEntry)
{
  auto reader = getPixelFormatLoadedReader();
  auto formatName = reader.getFormatName(0);

  EXPECT_EQ(formatName, "RGBA");
}

TEST(JSONReaderTests, ShouldGetBitsPerPixelFromSecondEntry)
{
  auto reader = getPixelFormatLoadedReader();
  auto formatName = reader.getBitsPerPixel(1);

  EXPECT_EQ(formatName, 24);
}

TEST(JSONReaderTests, ShouldGetColours)
{
  auto reader = getPixelFormatLoadedReader();
  auto colours = reader.getColours(0);

  std::vector<std::string> correctColours = {
    "alpha", "blue", "green", "red"};

  int noOfColours = correctColours.size();

  for (int valueNo = 0; valueNo < noOfColours; valueNo++)
    EXPECT_EQ(colours[valueNo], correctColours[valueNo]);
}

TEST(JSONReaderTests, ShouldGetListOfObjects)
{
  auto reader = configurateFileReader();
  auto objectNames = reader.listOfObjects();

  for (auto name : objectNames) {
    std::cout << name << "\n";
  }
}