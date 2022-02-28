#pragma once

#include <string>
#include "src/main/cpp/bitmaps/formats/format/format.h"

namespace Bitmaps
{
  Format format(std::string formatName);
  Format format(int bitsPerPixel);
  Format formatByIndex(int index);
}