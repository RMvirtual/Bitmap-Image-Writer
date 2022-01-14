#ifndef RGBA_PIXEL_H
#define RGBA_PIXEL_H

#include "src/graphics/bitmaps/packet/pixel-array/pixels/colours/rgba_colours.h"

namespace Pixels {
class RGBAPixel
{
public:
  RGBAPixel(RGBAColours colours);

  void setColours(RGBAColours colours);  
  RGBAColours getColours();

private:
  RGBAColours colours;
};}

#endif