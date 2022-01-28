#ifndef PIXEL_FORMAT_H
#define PIXEL_FORMAT_H

#include <vector>
#include <string>
#include <src/graphics/bitmaps/packet/pixel-array/pixel/colours.h>

namespace Pixels {
struct Format
{
  std::string name;
  int bitsPerPixel;
  std::vector<std::string> colourNames;
};}

#endif