#pragma once

#include <string>
#include <vector>

#include "src/main/cpp/bitmaps/formats/colours/colours.h"

namespace Bitmaps {
class PixelFormat
{
public:
  PixelFormat();

  int bitsPerPixel() const;
  int bytesPerPixel() const;
  std::vector<std::string> colourNames() const;
  Colours colours() const;

  void setBitsPerPixel(int bitsPerPixel);
  void setColourNames(std::vector<std::string> colourNames);

private:
  int _bitsPerPixel;
  int _bytesPerPixel;
  Colours _colours;

  void calculateBytesPerPixel();
};}