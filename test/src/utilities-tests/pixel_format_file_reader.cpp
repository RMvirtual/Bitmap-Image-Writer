#include <gtest/gtest.h>
#include "src/utilities/pixel_format_file.h"

#include <string>
#include <vector>

TEST(PixelFormatFile, ShouldGetFormatNameFromFirstEntry)
{
  Utilities::PixelFormatFile reader {};
  auto formatName = reader.getFormatName(0);

  EXPECT_EQ(formatName, "RGBA");
}

TEST(PixelFormatFile, ShouldGetBitsPerPixelFromSecondEntry)
{
  Utilities::PixelFormatFile reader {};
  auto formatName = reader.getBitsPerPixel(1);

  EXPECT_EQ(formatName, 24);
}

TEST(PixelFormatFile, ShouldGetColours)
{
  Utilities::PixelFormatFile reader {};
  auto colours = reader.getColours(0);

  std::vector<std::string> correctColours = {
    "alpha", "blue", "green", "red"};

  int noOfColours = correctColours.size();

  for (int valueNo = 0; valueNo < noOfColours; valueNo++)
    EXPECT_EQ(colours[valueNo], correctColours[valueNo]);
}

TEST(PixelFormatFile, ShouldGetIndexOfFirstName)
{
  Utilities::PixelFormatFile file {};
  int index = file.indexByName("RGBA");
  int correctIndex = 0;

  EXPECT_EQ(correctIndex, index);
}