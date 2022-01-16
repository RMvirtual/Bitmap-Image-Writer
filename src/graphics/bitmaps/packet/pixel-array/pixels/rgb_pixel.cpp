#include "src/graphics/bitmaps/packet/pixel-array/pixels/rgb_pixel.h"
#include "src/graphics/bitmaps/packet/pixel-array/pixels/colours/rgb_colours.h"

Pixels::RGBPixel::RGBPixel()
{
  // Pass.
}

Pixels::RGBPixel::RGBPixel(const Pixels::RGBColours& colours)
{
  this->colours = colours;
}

void Pixels::RGBPixel::setColours(const Pixels::RGBColours& colours) 
{
  this->colours = colours;
}

Pixels::RGBColours Pixels::RGBPixel::getColours()
{
  return this->colours;
}