#pragma once

#include "src/main/cpp/bitmaps/packet/headers/file-header/header.h"
#include "src/main/cpp/bitmaps/packet/headers/dib-header/header.h"

namespace Bitmaps {
struct Headers
{
  FileHeader fileHeader;
  DibHeader dibHeader;
};}