#ifndef RGB_PIXEL_ARRAY_VALUES_H
#define RGB_PIXEL_ARRAY_VALUES_H

#include "src/graphics/bitmaps/packet/pixel-array/rgb/rgb_pixel.h"

namespace Pixels {
struct RGBPixelArrayValues
{
  int widthInPixels;
  int heightInPixels;
  Pixels::RGBPixel defaultPixel;
};}

#endif