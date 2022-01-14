#include "src/graphics/bitmaps/packet/pixel-array/pixels/rgba_pixel.h"
#include "src/graphics/bitmaps/packet/pixel-array/pixels/colours/rgba_colours.h"

Pixels::RGBAPixel::RGBAPixel(Pixels::RGBAColours colours)
{
  this->colours = colours;
}

Pixels::RGBAColours Pixels::RGBAPixel::getColours()
{
  return this->colours;
}

void Pixels::RGBAPixel::setColours(Pixels::RGBAColours colours)
{
  this->colours = colours;
}