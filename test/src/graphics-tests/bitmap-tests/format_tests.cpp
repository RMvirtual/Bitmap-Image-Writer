#include <gtest/gtest.h>
#include <src/graphics/bitmaps/packet/formats/formats.h>

Pixels::Format rgbaFormat()
{
  Pixels::Format format {};
  format.name = "RGBA";
  format.bitsPerPixel = 32;
  format.colourNames = {"alpha", "blue", "green", "red"};

  return format;
}

Pixels::Format rgbFormat()
{
  Pixels::Format format {};
  format.name = "RGB";
  format.bitsPerPixel = 24;
  format.colourNames = {"blue", "green", "red"};

  return format;
}

void comparePixelFormats(Pixels::Format& correctFormat, Pixels::Format& format)
{
  EXPECT_EQ(correctFormat.name, format.name);
  EXPECT_EQ(correctFormat.bitsPerPixel, format.bitsPerPixel);
  EXPECT_EQ(correctFormat.colourNames.size(), format.colourNames.size());

  for (int colour = 0; colour < correctFormat.colourNames.size(); colour++)
    EXPECT_EQ(correctFormat.colourNames[colour], format.colourNames[colour]);
}

TEST(PixelFormats, ShouldGetRGBAFormat)
{
  auto format = Pixels::format("RGBA");
  auto correctFormat = rgbaFormat();

  comparePixelFormats(correctFormat, format);
}

TEST(PixelFormats, ShouldGet32BitPerPixelFormat)
{
  auto format = Pixels::format(32);
  auto correctFormat = rgbaFormat();

  comparePixelFormats(correctFormat, format);
}

TEST(PixelFormats, ShouldGet24BitPerPixelFormat)
{
  auto format = Pixels::format(24);
  auto correctFormat = rgbFormat();

  comparePixelFormats(correctFormat, format);
}