#ifndef RGB_PIXEL_ARRAY_H
#define RGB_PIXEL_ARRAY_H

#include "src/graphics/bitmaps/packet/pixel-array/templates/pixel_array.h"
#include "src/graphics/bitmaps/packet/pixel-array/templates/pixel.h"
#include "src/graphics/bitmaps/packet/pixel-array/rgb/pixel.h"
#include "src/graphics/bitmaps/packet/pixel-array/rgb/pixel_array_values.h"

namespace Pixels {
class RGBPixelArray : public PixelArray<RGBPixel>
{
public:
  RGBPixelArray();
  RGBPixelArray(const RGBPixelArrayValues& values);
};}

#endif