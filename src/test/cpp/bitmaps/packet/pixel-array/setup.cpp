#include "src/test/cpp/bitmaps/packet/pixel-array/fixture.h"

void PixelArrayTest::setupRedPixelArray(int width, int height)
{
  Bitmaps::Format format;
  format.setWidthInPixels(width);
  format.setHeightInPixels(height);
  format.setName("RGB");
  format.setBitsPerPixel(24);
  format.setColourNames({"red", "blue", "green"});

  this->pixelArray = Bitmaps::PixelArray(format);
  this->pixelArray.setFormat(format);
  this->pixelArray.fill(this->redColours());
}

Bitmaps::Colours PixelArrayTest::redColours()
{
  Bitmaps::Colours colours;
  colours["red"] = 255;
  colours["green"] = 0;
  colours["blue"] = 0;

  return colours;
}

Bitmaps::Colours PixelArrayTest::greenColours()
{
  Bitmaps::Colours colours;
  colours["red"] = 0;
  colours["green"] = 255;
  colours["blue"] = 0;

  return colours;
}
