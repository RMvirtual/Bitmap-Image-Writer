#include <cstdint>
#include "src/graphics/bitmaps/packet/pixel-array/pixels/colours/rgba_colours.h"

Pixels::RGBAColours::RGBAColours()
{
  this->alpha = 0;
}

void Pixels::RGBAColours::setAlpha(uint8_t alpha)
{
  this->alpha = alpha;
}

uint8_t Pixels::RGBAColours::getAlpha()
{
  return this->alpha;
}

