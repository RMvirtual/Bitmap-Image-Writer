#ifndef BITMAP_FORMATS_H
#define BITMAP_FORMATS_H

#include <string>
#include "src/graphics/bitmaps/formats/format.h"
#include "src/graphics/bitmaps/packet/headers/headers.h"

namespace Bitmaps
{
  Format format(Headers headers);
  Format format(DibHeader headers);
  Format format(std::string formatName);
  Format format(int bitsPerPixel);
  Format formatByIndex(int index);
}

#endif