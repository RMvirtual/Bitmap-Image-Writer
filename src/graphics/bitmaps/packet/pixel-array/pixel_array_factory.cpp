#include "src/graphics/bitmaps/packet/pixel-array/pixel_array_factory.h"
#include "src/graphics/bitmaps/packet/pixel-array/rgb/pixel_array.h"
#include "src/graphics/bitmaps/packet/pixel-array/rgb/pixel.h"
#include "src/graphics/bitmaps/packet/pixel-array/rgb/pixel_array_values.h"
#include "src/graphics/bitmaps/packet/pixel-array/rgb/colours.h"

Pixels::PixelArrayFactory::PixelArrayFactory()
{
  // pass.
}

Pixels::RGBPixelArray Pixels::PixelArrayFactory::rgbPixelArray(
  int widthInPixels, int heightInPixels)
{
  Pixels::RGBPixelArrayValues values;
  values.widthInPixels = 2;
  values.heightInPixels = 2;

  return {values};
}

Pixels::RGBPixelArray Pixels::PixelArrayFactory::rgbPixelArray(
  int widthInPixels, int heightInPixels, Pixels::RGBColours colours)
{
  Pixels::RGBPixelArrayValues values;
  values.widthInPixels = 2;
  values.heightInPixels = 2;
  values.defaultPixel = {colours};
  
  return {values};
}

Pixels::RGBPixel Pixels::PixelArrayFactory::rgbPixel()
{
  return {};
}

Pixels::RGBPixel Pixels::PixelArrayFactory::rgbPixel(
  Pixels::RGBColours colours)
{
  return {colours};
}