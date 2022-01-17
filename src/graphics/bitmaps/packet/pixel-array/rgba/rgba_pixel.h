#ifndef RGBA_PIXEL_H
#define RGBA_PIXEL_H

#include "src/graphics/bitmaps/packet/pixel-array/rgba/rgba_colours.h"

namespace Pixels {
class RGBAPixel
{
public:
  RGBAPixel(RGBAColours colours);

  RGBAColours colours() const;
  void setColours(const RGBAColours& colours);

private:
  RGBAColours _colours;
};}

#endif