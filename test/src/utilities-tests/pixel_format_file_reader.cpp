#include <gtest/gtest.h>
#include "src/utilities/pixel_format_file.h"

#include <string>
#include <vector>

TEST(PixelFormatFile, ShouldGetFormatNameFromFirstEntry)
{
  Utilities::PixelFormatFile formatFile {};
  auto formatName = formatFile.getFormatName(0);

  EXPECT_EQ(formatName, "RGBA");
}

TEST(PixelFormatFile, ShouldGetBitsPerPixelFromSecondEntry)
{
  Utilities::PixelFormatFile formatFile {};
  auto formatName = formatFile.getBitsPerPixel(1);

  EXPECT_EQ(formatName, 24);
}

TEST(PixelFormatFile, ShouldGetColours)
{
  Utilities::PixelFormatFile formatFile {};
  auto colours = formatFile.getColours(0);

  std::vector<std::string> correctColours {"alpha", "blue", "green", "red"};
  int noOfColours = correctColours.size();

  for (int valueNo = 0; valueNo < noOfColours; valueNo++)
    EXPECT_EQ(correctColours[valueNo], colours[valueNo]);
}

TEST(PixelFormatFile, ShouldGetIndexOfFirstName)
{
  Utilities::PixelFormatFile formatFile {};
  int index = formatFile.indexByName("RGBA");
  int correctIndex = 0;

  EXPECT_EQ(correctIndex, index);
}