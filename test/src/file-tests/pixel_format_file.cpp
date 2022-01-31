#include <gtest/gtest.h>
#include "src/files/pixel_formats.h"
#include <string>
#include <vector>

TEST(PixelFormatFile, ShouldGetFormatNameFromFirstEntry)
{
  Files::PixelFormats formatFile {};
  auto formatName = formatFile.formatName(0);

  EXPECT_EQ(formatName, "RGBA");
}

TEST(PixelFormatFile, ShouldGetBitsPerPixelFromSecondEntry)
{
  Files::PixelFormats formatFile {};
  auto formatName = formatFile.bitsPerPixel(1);

  EXPECT_EQ(formatName, 24);
}

TEST(PixelFormatFile, ShouldGetColours)
{
  Files::PixelFormats formatFile {};
  auto colours = formatFile.colours(0);

  std::vector<std::string> correctColours {"alpha", "blue", "green", "red"};
  int noOfColours = correctColours.size();

  for (int valueNo = 0; valueNo < noOfColours; valueNo++)
    EXPECT_EQ(correctColours[valueNo], colours[valueNo]);
}

TEST(PixelFormatFile, ShouldGetIndexOfFirstName)
{
  Files::PixelFormats formatFile {};
  int index = formatFile.indexOf("RGBA");
  int correctIndex = 0;

  EXPECT_EQ(correctIndex, index);
}