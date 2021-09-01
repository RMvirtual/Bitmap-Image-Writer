#ifndef BITMAP_SET_UP_H
#define BITMAP_SET_UP_H

#include "src/graphics/bitmaps/packet/pixels/pixel.h"
#include "src/graphics/bitmaps/packet/pixels/pixel_array.h"
#include "src/graphics/bitmaps/reader/bitmap_reader.h"
#include "src/graphics/bitmaps/bitmap_image.h"
#include "test/src/graphics-tests/utilities/bitmap_image_comparators.h"

namespace BitmapSetUp {
  BitmapFileHeader setUpBluePixelFileHeader();
  BitmapDibHeader setUpBluePixelDibHeader();
  PixelArray setUpBluePixelArray();
  BitmapImage setUpBlueBitmapImage();
  std::string getBlueImagePath();
}

#endif