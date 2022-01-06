#ifndef PIXEL_DATA_H
#define PIXEL_DATA_H

#include <cstdint>

namespace Pixels
{
  struct PixelData
  {
    uint8_t red;
    uint8_t green;
    uint8_t blue;
    int rowNo;
    int columnNo;
  };
}

#endif