#ifndef PIXEL_ARRAY_H
#define PIXEL_ARRAY_H

#include <vector>
#include "src/graphics/bitmaps/pixel.h"

using namespace std;

class PixelArray
{
public:
  vector<Pixel> pixels;

  PixelArray();
  int widthInPixels;
  int heightInPixels;
};

#endif