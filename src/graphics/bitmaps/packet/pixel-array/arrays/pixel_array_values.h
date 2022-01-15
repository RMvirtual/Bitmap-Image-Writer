#ifndef PIXEL_ARRAY_VALUES_H
#define PIXEL_ARRAY_VALUES_H

#include "src/graphics/bitmaps/packet/pixel-array/pixels/rgb_pixel.h"

namespace Pixels {
struct PixelArrayValues
{
  int widthInPixels;
  int heightInPixels;
  Pixels::RGBPixel defaultPixel;
};}

#endif