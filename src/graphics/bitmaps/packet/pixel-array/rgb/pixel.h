#ifndef RGB_PIXEL_H
#define RGB_PIXEL_H

#include "src/graphics/bitmaps/packet/pixel-array/templates/pixel.h"
#include "src/graphics/bitmaps/packet/pixel-array/rgb/colours.h"

namespace Pixels {
class RGBPixel : public Pixel<RGBColours>
{
public:
  RGBPixel();
  RGBPixel(const RGBColours& colours);
};}

#endif