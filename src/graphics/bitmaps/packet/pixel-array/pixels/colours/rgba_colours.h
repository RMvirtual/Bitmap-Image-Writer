#ifndef RGBA_COLOURS_H
#define RGBA_COLOURS_H

#include <cstdint>
#include "src/graphics/bitmaps/packet/pixel-array/pixels/colours/rgb_colours.h"

namespace Pixels {
class RGBAColours : public RGBColours
{
public:
  RGBAColours();
  
  void setAlpha(uint8_t alpha);
  uint8_t alpha() const;

private:
  uint8_t _alpha;
};}

#endif