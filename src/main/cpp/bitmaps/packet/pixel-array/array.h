#pragma once

#include <memory>
#include "src/main/cpp/containers/matrix-2D/matrix_2d.h"
#include "src/main/cpp/bitmaps/formats/format/format.h"
#include "src/main/cpp/bitmaps/formats/colours/colours.h"

namespace Bitmaps {
class PixelArray
{
public:
  PixelArray(const Format& format);

  void set(const Colours& colours, int row, int column);
  void set(const Colours& colours, int index);
  void fill(const Colours& colours);
  std::shared_ptr<Bitmaps::Colours> at(int row, int column);
  std::shared_ptr<Bitmaps::Colours> at(int index);
  Bitmaps::Colours at(int row, int column) const;
  Bitmaps::Colours at(int index) const;
  int sizeInPixels() const;
  Format format() const;
  void setFormat(const Format& format);

private:
  Format _format;
  std::unique_ptr<Matrix2D<Bitmaps::Colours>> pixels;
};}