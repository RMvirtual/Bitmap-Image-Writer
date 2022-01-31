#ifndef BITMAP_FORMATS_H
#define BITMAP_FORMATS_H

#include <string>
#include "src/graphics/bitmaps/formats/format.h"
#include "src/graphics/bitmaps/packet/headers/headers.h"

namespace Bitmaps
{
  Bitmaps::Format format(Bitmaps::Headers headers);
  Bitmaps::Format format(Bitmaps::DibHeader headers);
  Bitmaps::Format format(std::string formatName);
  Bitmaps::Format format(int bitsPerPixel);
  Bitmaps::Format formatByIndex(int index);
}

#endif