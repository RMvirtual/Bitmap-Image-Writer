#ifndef PIXEL_ARRAY_H
#define PIXEL_ARRAY_H

#include "src/containers/matrix-2D/matrix_2d.h"
#include "src/graphics/bitmaps/packet/pixel-array/colours.h"
#include "src/graphics/bitmaps/packet/formats/format.h"

namespace Pixels {
class Array
{
public:
  Array();
  Array(const Format& format);

  void set(const Colours& colours, int rowNo, int columnNo);
  void set(const Colours& colours, int indexNo);
  void fill(const Colours& colours);
  Colours& at(int rowNo, int columnNo);
  Colours& at(int indexNo);
  Colours at(int rowNo, int columnNo) const;
  Colours at(int indexNo) const;
  int sizeInPixels() const;
  Format format() const;
  void setFormat(const Format& format);

private:
  Format _format;
  Matrix2D<Colours> pixels {0, 0, {}};
};}

#endif