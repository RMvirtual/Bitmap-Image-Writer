#ifndef RGBA_PIXEL_ARRAY_H
#define RGBA_PIXEL_ARRAY_H

#include "src/graphics/bitmaps/packet/pixel-array/pixel_array.h"
#include "src/graphics/bitmaps/packet/pixel-array/rgba/pixel.h"
#include "src/graphics/bitmaps/packet/pixel-array/rgba/pixel_array_values.h"

namespace Pixels {
class RGBAPixelArray : public PixelArray<RGBAPixel>
{
public:
  RGBAPixelArray();
  RGBAPixelArray(const RGBAPixelArrayValues& values);
};}

#endif