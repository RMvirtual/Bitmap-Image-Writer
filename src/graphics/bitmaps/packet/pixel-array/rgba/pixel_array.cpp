#include "src/graphics/bitmaps/packet/pixel-array/rgba/pixel_array.h"
#include "src/graphics/bitmaps/packet/pixel-array/templates/pixel_array.h"
#include "src/graphics/bitmaps/packet/pixel-array/rgba/pixel_array_values.h"
#include "src/graphics/bitmaps/packet/pixel-array/rgba/pixel.h"

Pixels::RGBAPixelArray::RGBAPixelArray()
: Pixels::PixelArray <Pixels::RGBAPixel> {}
{

}

Pixels::RGBAPixelArray::RGBAPixelArray(
    const Pixels::RGBAPixelArrayValues& values)
: Pixels::PixelArray <Pixels::RGBAPixel> {values}
{

}
