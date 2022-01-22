#ifndef RGBA_COLOURS_H
#define RGBA_COLOURS_H

#include <cstdint>
#include "src/graphics/bitmaps/packet/pixel-array/rgb/colours.h"

namespace Pixels {
struct RGBAColours : public RGBColours
{
  uint8_t alpha;
};}

#endif