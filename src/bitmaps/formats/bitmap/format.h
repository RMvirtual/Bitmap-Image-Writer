#ifndef BITMAP_FORMAT_H
#define BITMAP_FORMAT_H

#include <string>
#include <vector>

#include "src/bitmaps/formats/colours/colours.h"
#include "src/bitmaps/formats/pixel/format.h"

namespace Bitmaps {
class Format
{
public:
  Format();

  std::string name() const;
  int bitsPerPixel() const;
  int bytesPerPixel() const;
  std::vector<std::string> colourNames() const;
  Colours colours() const;
  int widthInPixels() const;
  int heightInPixels() const;
  int bytesPaddingPerRow() const;
  int bytesPerRow() const;
  int arraySizeInBytes() const;
  int bytesPerUnpaddedRow() const;
  
  void setName(std::string name);
  void setBitsPerPixel(int bitsPerPixel);
  void setColourNames(std::vector<std::string> colourNames);
  void setWidthInPixels(int width);
  void setHeightInPixels(int height);

private:
  std::string _name;
  PixelFormat pixelFormat;
  int _widthInPixels;
  int _heightInPixels;
  int _bytesPaddingPerRow;
  int _bytesPerRow;

  void calculateRowPadding();
  void calculateBytesPerRow();
};}

#endif