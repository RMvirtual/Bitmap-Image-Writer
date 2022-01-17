#include <cstdint>
#include "src/graphics/bitmaps/packet/pixel-array/rgba/rgba_colours.h"

Pixels::RGBAColours::RGBAColours()
{
  this->_alpha = 0;
}

void Pixels::RGBAColours::setAlpha(uint8_t alpha)
{
  this->_alpha = alpha;
}

uint8_t Pixels::RGBAColours::alpha() const
{
  return this->_alpha;
}

