#ifndef PIXEL_ARRAY_VALUES_H
#define PIXEL_ARRAY_VALUES_H

#include "src/graphics/bitmaps/packet/pixel-array/pixel/format.h"

namespace Pixels
{
  struct ArrayValues
  {
    int widthInPixels;
    int heightInPixels;
    Format pixelFormat;
  };
}

#endif