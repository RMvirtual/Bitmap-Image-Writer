#ifndef PIXEL_H
#define PIXEL_H

#include <string>
#include "src/graphics/bitmaps/packet/pixel-array/pixel/colours.h"

namespace Pixels {
class Pixel
{
public:
  Pixel();
  Pixel(const Colours& colours);

  Colours colours() const;
  void setColour(std::string colourName, int value);
  void setColours(Colours colours);
  int& operator [](std::string colourName);

private:
  Colours _colours;
};}

#endif