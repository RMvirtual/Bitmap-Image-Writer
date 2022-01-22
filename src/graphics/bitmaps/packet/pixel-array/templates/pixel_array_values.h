#ifndef PIXEL_ARRAY_VALUES_H
#define PIXEL_ARRAY_VALUES_H

namespace Pixels
{
  template <class PixelType>
  struct PixelArrayValues
  {
    int widthInPixels;
    int heightInPixels;
    PixelType defaultPixel;
  };
}

#endif