#ifndef RGBA_PIXEL_ARRAY_H
#define RGBA_PIXEL_ARRAY_H

#include "src/common/matrix-2D/matrix_2d.h"
#include "src/graphics/bitmaps/packet/pixel-array/rgba/rgba_pixel.h"
#include "src/graphics/bitmaps/packet/pixel-array/rgba/rgba_pixel_array_values.h"

namespace Pixels {
class RGBAPixelArray
{
public:
  RGBAPixelArray();
  RGBAPixelArray(const Pixels::RGBAPixelArrayValues& values);

  void set(const Pixels::RGBAPixel& pixel, int rowNo, int columnNo);
  void set(const Pixels::RGBAPixel& pixel, int indexNo);
  Pixels::RGBAPixel at(int rowNo, int columnNo) const;
  Pixels::RGBAPixel at(int indexNo) const;
  int sizeInPixels() const;

private:
  Common::Matrix2D<Pixels::RGBAPixel> pixels {0, 0, {}};
};}

#endif