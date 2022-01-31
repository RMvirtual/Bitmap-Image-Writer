#ifndef BITMAP_FORMATS_H
#define BITMAP_FORMATS_H

#include <string>
#include "src/graphics/bitmaps/formats/format.h"
#include "src/graphics/bitmaps/packet/headers/headers.h"

namespace Pixels
{
  Pixels::Format format(BitmapHeaders::Headers headers);
  Pixels::Format format(BitmapHeaders::DibHeader headers);
  Pixels::Format format(std::string formatName);
  Pixels::Format format(int bitsPerPixel);
  Pixels::Format formatByIndex(int index);
}

#endif