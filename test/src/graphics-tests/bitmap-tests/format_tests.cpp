#include <gtest/gtest.h>
#include <src/graphics/bitmaps/packet/formats/formats.h>

TEST(PixelFormats, ShouldGetRGBAFormat)
{
  auto format = Pixels::format("RGBA");

  Pixels::Format correctFormat {};
  correctFormat.name = "RGBA";
  correctFormat.bitsPerPixel = 32;
  correctFormat.colourNames = {"alpha", "blue", "green", "red"};

  EXPECT_EQ(correctFormat.name, format.name);
  EXPECT_EQ(correctFormat.bitsPerPixel, format.bitsPerPixel);
  EXPECT_EQ(correctFormat.colourNames.size(), format.colourNames.size());

  for (int colour = 0; colour < correctFormat.colourNames.size(); colour++)
    EXPECT_EQ(correctFormat.colourNames[colour], format.colourNames[colour]);
}

