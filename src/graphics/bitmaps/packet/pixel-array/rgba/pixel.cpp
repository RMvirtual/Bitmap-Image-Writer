#include "src/graphics/bitmaps/packet/pixel-array/rgba/pixel.h"
#include "src/graphics/bitmaps/packet/pixel-array/rgba/colours.h"

Pixels::RGBAPixel::RGBAPixel()
{

}

Pixels::RGBAPixel::RGBAPixel(const Pixels::RGBAColours& colours)
{
  this->setColours(colours);
}
