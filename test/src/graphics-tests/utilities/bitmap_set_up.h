#ifndef BITMAP_SET_UP_H
#define BITMAP_SET_UP_H

#include <string>
#include "src/graphics/bitmaps/packet/bitmap_packet.h"
#include "src/graphics/bitmaps/packet/headers/file-header/file_header.h"
#include "src/graphics/bitmaps/packet/headers/dib-header/dib_header.h"
#include "src/graphics/bitmaps/packet/pixel-array/rgb/colours.h"
#include "test/src/graphics-tests/utilities/bitmap_image_comparators.h"
#include "src/graphics/bitmaps/packet/pixel-array/rgb/pixel_array.h"
#include "src/graphics/bitmaps/packet/pixel-array/rgb/pixel.h"

namespace BitmapSetUp
{
  std::string blueImagePath();
  BitmapPacket blueBitmapPacket();
  BitmapHeaders::FileHeader bluePixelFileHeader();
  BitmapHeaders::DibHeader bluePixelDibHeader();
  Pixels::RGBPixelArray bluePixelArray();
  Pixels::RGBPixelArray redPixelArray();
  Pixels::RGBPixel greenRGBPixel();
  Pixels::RGBColours whiteColours();
  Pixels::RGBColours greenColours();
  Pixels::RGBColours redColours();
  Pixels::RGBColours blueColours();
}

#endif