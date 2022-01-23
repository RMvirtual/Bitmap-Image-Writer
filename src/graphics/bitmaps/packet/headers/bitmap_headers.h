#ifndef BITMAP_PACKET_HEADERS_H
#define BITMAP_PACKET_HEADERS_H

#include "src/graphics/bitmaps/packet/headers/file-header/file_header.h"
#include "src/graphics/bitmaps/packet/headers/dib-header/dib_header.h"

namespace BitmapHeaders {
struct Headers
{
  FileHeader fileHeader;
  DibHeader dibHeader;
};}

#endif