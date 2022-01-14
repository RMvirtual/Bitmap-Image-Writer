#ifndef RGB_PIXEL_H
#define RGB_PIXEL_H

#include "src/graphics/bitmaps/packet/pixel-array/pixels/colours/rgb_colours.h"

namespace Pixels {
class RGBPixel
{
public:
  RGBPixel();
  RGBPixel(RGBColours colours);
  
  void setColours(RGBColours colours);
  RGBColours getColours();

private:
  RGBColours colours;
};}

#endif