#ifndef PIXEL_FORMAT_H
#define PIXEL_FORMAT_H

#include <string>
#include <vector>

#include "src/bitmaps/formats/colours/colours.h"

namespace Bitmaps {
class PixelFormat
{
public:
  PixelFormat();

  int bitsPerPixel() const;
  int pixelSizeInBytes() const;
  std::vector<std::string> colourNames() const;
  Colours colours() const;

  void setBitsPerPixel(int bitsPerPixel);
  void setColourNames(std::vector<std::string> colourNames);

private:
  int _bitsPerPixel;
  int _pixelSizeInBytes;
  Colours _colours;

  void processPixelSizeInBytes();

};}

#endif