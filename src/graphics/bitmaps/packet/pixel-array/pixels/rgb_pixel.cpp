#include "src/graphics/bitmaps/packet/pixel-array/pixels/rgb_pixel.h"
#include "src/graphics/bitmaps/packet/pixel-array/pixels/colours/rgb_colours.h"

Pixels::RGBPixel::RGBPixel()
{
  // Pass.
}

Pixels::RGBPixel::RGBPixel(const Pixels::RGBColours& colours)
{
  this->_colours = colours;
}

void Pixels::RGBPixel::setColours(const Pixels::RGBColours& colours) 
{
  this->_colours = colours;
}

Pixels::RGBColours Pixels::RGBPixel::colours() const
{
  return this->_colours;
}