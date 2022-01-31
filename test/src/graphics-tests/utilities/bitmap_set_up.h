#ifndef BITMAP_SET_UP_H
#define BITMAP_SET_UP_H

#include <string>
#include "src/graphics/bitmaps/packet/packet.h"
#include "src/graphics/bitmaps/packet/headers/file-header/header.h"
#include "src/graphics/bitmaps/packet/headers/dib-header/header.h"
#include "test/src/graphics-tests/utilities/bitmap_image_comparators.h"
#include "src/graphics/bitmaps/packet/pixel-array/array.h"
#include "src/graphics/bitmaps/packet/headers/headers.h"
#include "src/graphics/bitmaps/packet/pixel-array/colours.h"

namespace BitmapSetUp
{
  std::string blueImagePath();
  Bitmaps::Packet blueBitmapPacket();
  Bitmaps::Headers bluePixelHeaders();
  Bitmaps::FileHeader bluePixelFileHeader();
  Bitmaps::DibHeader bluePixelDibHeader();
  Bitmaps::PixelArray bluePixelArray();
  Bitmaps::PixelArray redPixelArray();
  Bitmaps::Colours whiteColours();
  Bitmaps::Colours greenColours();
  Bitmaps::Colours redColours();
  Bitmaps::Colours blueColours();
}

#endif