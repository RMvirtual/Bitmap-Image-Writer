#ifndef PIXEL_ARRAY_H
#define PIXEL_ARRAY_H

#include <vector>
#include "src/graphics/bitmaps/packet/pixel-array/pixels/rgb_pixel.h"

namespace Pixels {
class PixelArray
{
public:
  std::vector<Pixels::RGBPixel> pixels;

  PixelArray();
  PixelArray(
    std::vector<Pixels::RGBPixel> pixels, int widthInPixels, int heightInPixels);

  void setPixel();

  Pixels::RGBPixel getPixel(int rowNo, int columnNo);
  Pixels::RGBPixel getPixel(int index);
  int getWidthInPixels();
  int getHeightInPixels();
  int sizeInBytes();
  int sizeInPixels();

private:
  int rowSizeInBytes;
  int rowPadding;

  void initialisePixelArray(int widthInPixels, int heightInPixels);
  void populateMissingPixels();
  void addBlankPixels(int numberOfPixelsToAdd);
  void addBlankPixel();
  void calculateRowStride();
  int getRowStride();
  int getNumberOfMissingPixels();
};}

#endif