#ifndef PIXEL_ARRAY_H
#define PIXEL_ARRAY_H

#include "src/common/matrix-2D/matrix_2d.h"
#include "src/graphics/bitmaps/packet/pixel-array/array/values.h"
#include "src/graphics/bitmaps/packet/pixel-array/pixel/pixel.h"

namespace Pixels
{
  class Array
  {
  public:
    Array();
    Array(const ArrayValues& values);

    void set(const Pixel& pixel, int rowNo, int columnNo);
    void set(const Pixel& pixel, int indexNo);
    void fill(const Colours& colours);
    Pixel at(int rowNo, int columnNo) const;
    Pixel at(int indexNo) const;
    int sizeInPixels() const;

  private:
    Common::Matrix2D<Pixel> pixels {0, 0, {}};
};}

#endif