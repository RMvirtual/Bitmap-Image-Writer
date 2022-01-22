#include "src/graphics/bitmaps/packet/pixel-array/rgba/pixel.h"
#include "src/graphics/bitmaps/packet/pixel-array/rgba/colours.h"
#include "src/graphics/bitmaps/packet/pixel-array/templates/pixel.h"

Pixels::RGBAPixel::RGBAPixel()
: Pixels::Pixel<Pixels::RGBAColours> {}
{
  // pass.
}

Pixels::RGBAPixel::RGBAPixel(const Pixels::RGBAColours& colours)
: Pixels::Pixel<Pixels::RGBAColours> {colours}
{
  // pass.
}