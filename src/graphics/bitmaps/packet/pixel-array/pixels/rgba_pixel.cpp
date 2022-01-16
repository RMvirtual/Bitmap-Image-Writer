#include "src/graphics/bitmaps/packet/pixel-array/pixels/rgba_pixel.h"
#include "src/graphics/bitmaps/packet/pixel-array/pixels/colours/rgba_colours.h"

Pixels::RGBAPixel::RGBAPixel(Pixels::RGBAColours colours)
{
  this->_colours = colours;
}

Pixels::RGBAColours Pixels::RGBAPixel::colours() const
{
  return this->_colours;
}

void Pixels::RGBAPixel::setColours(const Pixels::RGBAColours& colours)
{
  this->_colours = colours;
}