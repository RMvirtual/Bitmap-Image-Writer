#ifndef PIXEL_H
#define PIXEL_H

#include <cstdint>
#include "src/graphics/colours/colours.h"

namespace Pixels
{
  class Pixel
  {
    public:
      Pixel(Colours colours);
      unsigned char* toBytes();

      void setColours(Colours colours);
      void setRed(uint8_t value);
      void setGreen(uint8_t value);
      void setBlue(uint8_t value);

      Colours getColours();
      uint8_t getRed();
      uint8_t getGreen();
      uint8_t getBlue();

    private:
      Colours colours;
  };
}

#endif