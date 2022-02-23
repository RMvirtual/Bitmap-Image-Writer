#ifndef BITMAP_PACKET_HEADERS_H
#define BITMAP_PACKET_HEADERS_H

#include "src/main/cpp/bitmaps/packet/headers/file-header/header.h"
#include "src/main/cpp/bitmaps/packet/headers/dib-header/header.h"

namespace Bitmaps {
struct Headers
{
  FileHeader fileHeader;
  DibHeader dibHeader;
};}

#endif