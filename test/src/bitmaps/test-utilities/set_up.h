#ifndef BITMAP_TEST_SET_UP_H
#define BITMAP_TEST_SET_UP_H

#include <string>

#include "src/bitmaps/packet/headers/dib-header/header.h"
#include "src/bitmaps/packet/headers/file-header/header.h"
#include "src/bitmaps/packet/headers/headers.h"
#include "src/bitmaps/packet/packet.h"
#include "src/bitmaps/packet/pixel-array/array.h"
#include "src/bitmaps/packet/pixel-array/colours.h"
#include "test/src/bitmaps/test-utilities/comparators.h"

namespace BitmapSetUp
{
  std::string blueImagePath();
  Bitmaps::Packet blueBitmapPacket();
  Bitmaps::Headers bluePixelHeaders();
  Bitmaps::FileHeader bluePixelFileHeader();
  Bitmaps::DibHeader bluePixelDibHeader();
  Bitmaps::PixelArray bluePixelArray();
  Bitmaps::PixelArray bluePixelArray(int width, int height);
  Bitmaps::PixelArray redPixelArray();
  Bitmaps::Colours whiteColours();
  Bitmaps::Colours greenColours();
  Bitmaps::Colours redColours();
  Bitmaps::Colours blueColours();
  Bitmaps::Colours blueColoursWithAlpha();

}

#endif