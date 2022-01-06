#ifndef PIXEL_DATA_H
#define PIXEL_DATA_H

#include <cstdint>

#include "src/graphics/colours/colours.h"

namespace Pixels
{
  struct PixelData
  {
    Colours colours;
    int rowNo;
    int columnNo;
  };
}

#endif