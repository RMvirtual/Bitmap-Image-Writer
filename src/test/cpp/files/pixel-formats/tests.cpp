#include <string>
#include <vector>

#include "gtest/gtest.h"
#include "src/main/cpp/files/pixel-formats/file.h"

TEST(PixelFormatFileTest, ShouldGetFormat)
{
  std::string correctName = "RGBA32";
  auto format = Files::PixelFormats::format(correctName);

  int correctBitsPerPixel = 32;
  EXPECT_EQ(correctName, format.name);
  EXPECT_EQ(correctBitsPerPixel, format.bitsPerPixel);
  
  std::vector<std::string> correctColours {"alpha", "blue", "green", "red"};
  
  int noOfColours = correctColours.size();

  for (int valueNo = 0; valueNo < noOfColours; valueNo++)
    EXPECT_EQ(correctColours[valueNo], format.colours[valueNo]);
}