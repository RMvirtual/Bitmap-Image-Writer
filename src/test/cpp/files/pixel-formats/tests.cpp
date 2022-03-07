#include <string>
#include <vector>

#include "gtest/gtest.h"
#include "src/main/cpp/files/pixel-formats/file.h"

TEST(PixelFormatFileTest, ShouldGetFormatNameFromFirstEntry)
{
  auto formatName = Files::PixelFormats::formatName(0);
  std::string correctFormatName = "RGBA";

  EXPECT_EQ(formatName, "RGBA");
}

TEST(PixelFormatFileTest, ShouldGetBitsPerPixelFromSecondEntry)
{  
  auto bitsPerPixel = Files::PixelFormats::bitsPerPixel(1);
  int correctBitsPerPixel = 24;

  EXPECT_EQ(bitsPerPixel, 24);
}

TEST(PixelFormatFileTest, ShouldGetColours)
{
  auto colours = Files::PixelFormats::colours(0);

  std::vector<std::string> correctColours {"alpha", "blue", "green", "red"};
  int noOfColours = correctColours.size();

  for (int valueNo = 0; valueNo < noOfColours; valueNo++)
    EXPECT_EQ(correctColours[valueNo], colours[valueNo]);
}

TEST(PixelFormatFileTest, ShouldGetIndexOfFirstName)
{
  int index = Files::PixelFormats::indexOf("RGBA");
  int correctIndex = 0;

  EXPECT_EQ(correctIndex, index);
}