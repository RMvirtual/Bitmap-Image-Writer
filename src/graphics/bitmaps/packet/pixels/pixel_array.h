#ifndef PIXEL_ARRAY_H
#define PIXEL_ARRAY_H

#include <vector>
#include "src/graphics/bitmaps/packet/pixels/pixel.h"

using namespace std;

class PixelArray
{
public:
  vector<Pixel> pixels;

  PixelArray(vector<Pixel> pixels, int widthInPixels, int heightInPixels);
  int widthInPixels;
  int heightInPixels;
  char* toBytes();
  int sizeInBytes();
  int sizeInPixels();
};

#endif