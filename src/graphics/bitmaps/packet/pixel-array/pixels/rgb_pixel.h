#ifndef RGB_PIXEL_H
#define RGB_PIXEL_H

#include "src/graphics/bitmaps/packet/pixel-array/pixels/colours/rgb_colours.h"

namespace Pixels {
class RGBPixel
{
public:
  RGBPixel();
  RGBPixel(const RGBColours& colours);
  
  void setColours(const RGBColours& colours);
  RGBColours colours() const;

private:
  RGBColours _colours;
};}

#endif