#ifndef PIXEL_ARRAY_H
#define PIXEL_ARRAY_H

#include "src/graphics/bitmaps/packet/pixel-array/pixels/rgb_pixel.h"
#include "src/common/matrix-2D/matrix_2d.h"

namespace Pixels {
class PixelArray
{
public:
  PixelArray();
  
  PixelArray(
    int widthInPixels, int heightInPixels, Pixels::RGBPixel defaultPixel);

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