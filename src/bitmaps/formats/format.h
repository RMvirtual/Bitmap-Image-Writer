#ifndef PIXEL_FORMAT_H
#define PIXEL_FORMAT_H

#include <string>
#include <vector>

#include "src/bitmaps/formats/colours.h"

namespace Bitmaps {
class Format
{
public:
  Format();

  std::string name() const;
  int bitsPerPixel() const;
  int pixelSizeInBytes() const;
  std::vector<std::string> colourNames() const;
  Colours colours() const;
  int widthInPixels() const;
  int heightInPixels() const;
  int rowPaddingInBytes() const;
  int rowSizeInBytes() const;
  int arraySizeInBytes() const;
  int unpaddedRowSize() const;
  
  void setName(std::string name);
  void setBitsPerPixel(int bitsPerPixel);
  void setColourNames(std::vector<std::string> colourNames);
  void setWidthInPixels(int width);
  void setHeightInPixels(int height);

private:
  std::string _name;
  int _bitsPerPixel;
  int _pixelSizeInBytes;
  Colours _colours;
  int _widthInPixels;
  int _heightInPixels;
  int _rowPaddingInBytes;
  int _rowSizeInBytes;

  void processRowPaddingInBytes();
  void processRowSizeInBytes();
  void processPixelSizeInBytes();
};}

#endif