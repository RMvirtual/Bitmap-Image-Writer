#ifndef PIXEL_FORMAT_H
#define PIXEL_FORMAT_H

#include <vector>
#include <string>
#include <src/graphics/bitmaps/packet/pixel-array/colours.h>

namespace Pixels {
struct Format
{
  std::string name;
  int bitsPerPixel;
  std::vector<std::string> colourNames;
  int widthInPixels;
  int heightInPixels;
};}

#endif