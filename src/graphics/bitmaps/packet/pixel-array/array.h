#ifndef PIXEL_ARRAY_H
#define PIXEL_ARRAY_H

#include "src/containers/matrix-2D/matrix_2d.h"
#include "src/graphics/bitmaps/formats/format.h"
#include "src/graphics/bitmaps/packet/pixel-array/colours.h"

namespace Pixels {
class Array
{
public:
  Array();
  Array(const Format& format);

  void set(const Colours& colours, int row, int column);
  void set(const Colours& colours, int index);
  void fill(const Colours& colours);
  Colours& at(int row, int column);
  Colours& at(int index);
  Colours at(int row, int column) const;
  Colours at(int index) const;
  int sizeInPixels() const;
  Format format() const;
  void setFormat(const Format& format);

private:
  Format _format;
  Matrix2D<Colours> pixels {0, 0, {}};
};}

#endif