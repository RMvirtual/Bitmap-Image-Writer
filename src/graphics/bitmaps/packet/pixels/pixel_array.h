#ifndef PIXEL_ARRAY_H
#define PIXEL_ARRAY_H

#include <vector>
#include "src/graphics/bitmaps/packet/pixels/pixel.h"

class PixelArray
{
public:
  std::vector<Pixel> pixels;

  PixelArray();
  PixelArray(
    std::vector<Pixel> pixels, int widthInPixels, int heightInPixels);
    
  char* toBytes();
  int sizeInBytes();
  int sizeInPixels();

  void setWidthInPixels(int width);
  void setHeightInPixels(int height);

  int getWidthInPixels();
  int getHeightInPixels();

private:
  int widthInPixels;
  int heightInPixels;
};

#endif