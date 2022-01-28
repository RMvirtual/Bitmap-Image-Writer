#ifndef BITMAP_SET_UP_H
#define BITMAP_SET_UP_H

#include <string>
#include "src/graphics/bitmaps/packet/packet.h"
#include "src/graphics/bitmaps/packet/headers/file-header/header.h"
#include "src/graphics/bitmaps/packet/headers/dib-header/header.h"
#include "src/graphics/bitmaps/packet/pixel-array/pixel/format.h"
#include "test/src/graphics-tests/utilities/bitmap_image_comparators.h"
#include "src/graphics/bitmaps/packet/pixel-array/array/array.h"
#include "src/graphics/bitmaps/packet/pixel-array/pixel/pixel.h"
#include "src/graphics/bitmaps/packet/headers/headers.h"

namespace BitmapSetUp
{
  std::string blueImagePath();
  BitmapPacket blueBitmapPacket();
  BitmapHeaders::Headers bluePixelHeaders();
  BitmapHeaders::FileHeader bluePixelFileHeader();
  BitmapHeaders::DibHeader bluePixelDibHeader();
  Pixels::Array bluePixelArray();
  Pixels::Array redPixelArray();
  Pixels::Pixel greenPixel();
  Pixels::Colours whiteColours();
  Pixels::Colours greenColours();
  Pixels::Colours redColours();
  Pixels::Colours blueColours();
}

#endif