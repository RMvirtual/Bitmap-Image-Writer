#ifndef BITMAP_SET_UP_H
#define BITMAP_SET_UP_H

#include <string>
#include "src/graphics/bitmaps/packet/rgb_bitmap_packet.h"
#include "src/graphics/bitmaps/packet/headers/file-header/file_header.h"
#include "src/graphics/bitmaps/packet/headers/dib-header/dib_header.h"
#include "src/graphics/bitmaps/packet/pixel-array/rgb/rgb_pixel_array.h"
#include "src/graphics/bitmaps/packet/pixel-array/rgb/rgb_colours.h"
#include "test/src/graphics-tests/utilities/bitmap_image_comparators.h"

namespace BitmapSetUp
{
  RGBBitmapPacket setUpBlueBitmapPacket();
  BitmapHeaders::FileHeader setUpBluePixelFileHeader();
  BitmapHeaders::DibHeader setUpBluePixelDibHeader();
  Pixels::RGBPixelArray setUpBluePixelArray();
  std::string getBlueImagePath();
  Pixels::RGBColours getWhiteColours();
  Pixels::RGBColours getGreenColours();
  Pixels::RGBColours getRedColours();
  Pixels::RGBColours getBlueColours();
}

#endif