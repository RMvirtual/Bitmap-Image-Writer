#ifndef RGBA_PIXEL_ARRAY_VALUES_H
#define RGBA_PIXEL_ARRAY_VALUES_H

#include "src/graphics/bitmaps/packet/pixel-array/rgba/rgba_pixel.h"

namespace Pixels {
struct RGBAPixelArrayValues
{
  int widthInPixels;
  int heightInPixels;
  Pixels::RGBAPixel defaultPixel;
};}

#endif