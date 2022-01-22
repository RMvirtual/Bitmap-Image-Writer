#ifndef PIXEL_ARRAY_FACTORY_H
#define PIXEL_ARRAY_FACTORY_H

#include "src/graphics/bitmaps/packet/pixel-array/rgb/pixel_array.h"
#include "src/graphics/bitmaps/packet/pixel-array/rgb/pixel.h"
#include "src/graphics/bitmaps/packet/pixel-array/rgb/colours.h"

namespace Pixels {
class PixelArrayFactory
{
public:
  PixelArrayFactory();

  RGBPixelArray rgbPixelArray(int widthInPixels, int heightInPixels);

  RGBPixelArray rgbPixelArray(
    int widthInPixels, int heightInPixels, RGBColours colours);

  RGBPixel rgbPixel();
  RGBPixel rgbPixel(RGBColours colours);
};}

#endif