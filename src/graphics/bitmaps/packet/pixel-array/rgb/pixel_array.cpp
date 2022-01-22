#include "src/graphics/bitmaps/packet/pixel-array/rgb/pixel_array.h"
#include "src/graphics/bitmaps/packet/pixel-array/templates/pixel_array.h"

Pixels::RGBPixelArray::RGBPixelArray()
: Pixels::PixelArray<Pixels::RGBPixel> {}
{

}

Pixels::RGBPixelArray::RGBPixelArray(const RGBPixelArrayValues& values)
: Pixels::PixelArray <Pixels::RGBPixel> {values}
{

}