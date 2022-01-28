#ifndef PIXEL_H
#define PIXEL_H

#include <string>

#include "src/graphics/bitmaps/packet/pixel-array/pixel/format.h"
#include "src/graphics/bitmaps/packet/pixel-array/pixel/colours.h"

namespace Pixels {
class Pixel
{
public:
  Pixel();
  Pixel(const Format& format);

  Colours colours() const;
  Format format() const;
  void setColour(std::string colourName, int value);
  void setColours(Colours colours);
  void setFormat(const Format& format);
  int& operator [](std::string colourName);

private:
  Format _format;
  Colours _colours;
};}

#endif