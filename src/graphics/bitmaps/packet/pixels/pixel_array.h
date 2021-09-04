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

  void populateMissingPixels();
  void setPixel(Pixel pixel, int rowNumber, int columnNo);

  void setWidthInPixels(int width);
  void setHeightInPixels(int height);

  int getWidthInPixels();
  int getHeightInPixels();
  int getRowStride();

private:
  int widthInPixels;
  int heightInPixels;
  int rowSizeInBytes;
  int rowPadding;

  void calculateRowStride();
  char* getRowOfPixelsAsBytes(int rowNo);
  int getPixelIndexByRowAndColumn(int rowNo, int columnNo);
};



#endif