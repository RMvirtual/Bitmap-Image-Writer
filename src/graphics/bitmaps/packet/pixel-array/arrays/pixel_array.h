#ifndef PIXEL_ARRAY_H
#define PIXEL_ARRAY_H

#include "src/common/matrix-2D/matrix_2d.h"
#include "src/graphics/bitmaps/packet/pixel-array/pixels/rgb_pixel.h"
#include "src/graphics/bitmaps/packet/pixel-array/arrays/pixel_array_values.h"

namespace Pixels {
class PixelArray
{
public:
  PixelArray();
  PixelArray(Pixels::PixelArrayValues values);

  void set(Pixels::RGBPixel pixel, int rowNo, int columnNo);
  Pixels::RGBPixel at(int rowNo, int columnNo);
  Pixels::RGBPixel at(int indexNo);
  int sizeInPixels();

private:
  Common::Matrix2D<Pixels::RGBPixel> pixels {0, 0, {}};
  int widthInPixels;
  int heightInPixels;  
};}

#endif