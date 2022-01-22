#ifndef RGBA_PIXEL_H
#define RGBA_PIXEL_H

#include "src/graphics/bitmaps/packet/pixel-array/templates/pixel.h"
#include "src/graphics/bitmaps/packet/pixel-array/rgba/colours.h"

namespace Pixels {
class RGBAPixel : public Pixel<RGBAColours>
{
public:
  RGBAPixel();
  RGBAPixel(const RGBAColours& colours);
};}

#endif