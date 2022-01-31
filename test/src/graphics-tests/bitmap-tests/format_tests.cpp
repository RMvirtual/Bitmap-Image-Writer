#include <gtest/gtest.h>
#include <src/graphics/bitmaps/formats/formats.h>

Bitmaps::Format rgbaFormat()
{
  Bitmaps::Format format {};
  format.setName("RGBA");
  format.setBitsPerPixel(32);
  format.setColourNames({"alpha", "blue", "green", "red"});

  return format;
}

Bitmaps::Format rgbFormat()
{
  Bitmaps::Format format {};
  format.setName("RGB");
  format.setBitsPerPixel(24);
  format.setColourNames({"blue", "green", "red"});

  return format;
}

void comparePixelFormats(Bitmaps::Format& correctFormat, Bitmaps::Format& format)
{
  EXPECT_EQ(correctFormat.name(), format.name());
  EXPECT_EQ(correctFormat.bitsPerPixel(), format.bitsPerPixel());
  EXPECT_EQ(correctFormat.colourNames().size(), format.colourNames().size());

  for (int colour = 0; colour < correctFormat.colourNames().size(); colour++)
    EXPECT_EQ(
      correctFormat.colourNames()[colour], format.colourNames()[colour]);
}

TEST(PixelFormats, ShouldGetRGBAFormat)
{
  auto format = Bitmaps::format("RGBA");
  auto correctFormat = rgbaFormat();

  comparePixelFormats(correctFormat, format);
}

TEST(PixelFormats, ShouldGetRGBFormat)
{
  auto format = Bitmaps::format("RGB");
  auto correctFormat = rgbaFormat();

  comparePixelFormats(correctFormat, format);
}

TEST(PixelFormats, ShouldGet32BitPerPixelFormat)
{
  auto format = Bitmaps::format(32);
  auto correctFormat = rgbaFormat();

  comparePixelFormats(correctFormat, format);
}

TEST(PixelFormats, ShouldGet24BitPerPixelFormat)
{
  auto format = Bitmaps::format(24);
  auto correctFormat = rgbFormat();

  comparePixelFormats(correctFormat, format);
}

TEST(PixelFormats, ShouldCalculatePixelArrayRowPadding)
{
  auto format = Bitmaps::format(24);
  format.setWidthInPixels(2);
  format.setHeightInPixels(1);
  int actualPadding = format.rowPaddingInBytes();
  int correctPadding = 2;

  EXPECT_EQ(correctPadding, actualPadding);
}

TEST(PixelFormats, ShouldCalculatePixelArrayRowSizeInBytes)
{
  auto format = Bitmaps::format(24);
  format.setWidthInPixels(6);
  format.setHeightInPixels(1);

  int correctSize = 20;
  int actualSize = format.rowSizeInBytes();
  
  EXPECT_EQ(correctSize, actualSize);
}