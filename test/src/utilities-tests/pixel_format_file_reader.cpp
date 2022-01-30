#include <gtest/gtest.h>
#include "src/utilities/pixel_format_file_reader.h"

#include <string>
#include <vector>

TEST(PixelFormatReader, ShouldGetFormatNameFromFirstEntry)
{
  Utilities::PixelFormatFileReader reader {};
  auto formatName = reader.getFormatName(0);

  EXPECT_EQ(formatName, "RGBA");
}

TEST(PixelFormatReader, ShouldGetBitsPerPixelFromSecondEntry)
{
  Utilities::PixelFormatFileReader reader {};
  auto formatName = reader.getBitsPerPixel(1);

  EXPECT_EQ(formatName, 24);
}

TEST(PixelFormatReader, ShouldGetColours)
{
  Utilities::PixelFormatFileReader reader {};
  auto colours = reader.getColours(0);

  std::vector<std::string> correctColours = {
    "alpha", "blue", "green", "red"};

  int noOfColours = correctColours.size();

  for (int valueNo = 0; valueNo < noOfColours; valueNo++)
    EXPECT_EQ(colours[valueNo], correctColours[valueNo]);
}