#ifndef PIXEL_FORMAT_H
#define PIXEL_FORMAT_H

#include <string>
#include <vector>

namespace Pixels {
class Format
{
public:
  Format();

  std::string name() const;
  int bitsPerPixel() const;
  int pixelSizeInBytes() const;
  std::vector<std::string> colourNames() const;
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
  std::vector<std::string> _colourNames;
  int _widthInPixels;
  int _heightInPixels;
  int _rowPaddingInBytes;
  int _rowSizeInBytes;

  void processRowPaddingInBytes();
  void processRowSizeInBytes();
  void processPixelSizeInBytes();
};}

#endif