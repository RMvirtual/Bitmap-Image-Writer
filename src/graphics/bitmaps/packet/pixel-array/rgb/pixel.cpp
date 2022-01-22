#include "src/graphics/bitmaps/packet/pixel-array/rgb/pixel.h"
#include "src/graphics/bitmaps/packet/pixel-array/rgb/colours.h"
#include "src/graphics/bitmaps/packet/pixel-array/templates/pixel.h"

Pixels::RGBPixel::RGBPixel()
: Pixels::Pixel<Pixels::RGBColours> {}
{
  // pass.
}

Pixels::RGBPixel::RGBPixel(const Pixels::RGBColours& colours)
: Pixels::Pixel<Pixels::RGBColours> {colours}
{
  // pass.  
}
