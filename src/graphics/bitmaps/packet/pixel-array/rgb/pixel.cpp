#include "src/graphics/bitmaps/packet/pixel-array/rgb/pixel.h"
#include "src/graphics/bitmaps/packet/pixel-array/rgb/colours.h"

Pixels::RGBPixel::RGBPixel()
{

}

Pixels::RGBPixel::RGBPixel(const Pixels::RGBColours& colours)
{
  this->setColours(colours);
}
