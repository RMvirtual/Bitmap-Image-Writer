#ifndef BITMAP_FORMATS_H
#define BITMAP_FORMATS_H

#include <string>
#include "src/main/bitmaps/formats/format/format.h"

namespace Bitmaps
{
  Format format(std::string formatName);
  Format format(int bitsPerPixel);
  Format formatByIndex(int index);
}

#endif