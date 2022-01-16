#ifndef BITMAP_SET_UP_H
#define BITMAP_SET_UP_H

#include "src/graphics/bitmaps/packet/pixel-array/pixels/rgb_pixel.h"
#include "src/graphics/bitmaps/packet/pixel-array/arrays/pixel_array.h"
#include "src/graphics/bitmaps/bitmap_image.h"
#include "test/src/graphics-tests/utilities/bitmap_image_comparators.h"

namespace BitmapSetUp
{
  BitmapImage setUpBlueBitmapImage();
  BitmapHeaders::FileHeader setUpBluePixelFileHeader();
  BitmapHeaders::DibHeader setUpBluePixelDibHeader();
  Pixels::PixelArray setUpBluePixelArray();
  std::string getBlueImagePath();
  Pixels::RGBColours getWhiteColours();
  Pixels::RGBColours getGreenColours();
  Pixels::RGBColours getRedColours();
  Pixels::RGBColours getBlueColours();
}

#endif