#ifndef BITMAP_DIB_HEADER_WRITER_H
#define BITMAP_DIB_HEADER_WRITER_H

#include "src/main/cpp/bitmaps/packet/headers/dib-header/header.h"
#include "src/main/cpp/containers/byte-array/byte_array.h"

namespace Bitmaps {
class DibHeaderWriter
{
public:
  DibHeaderWriter();
  ByteArray write(const Bitmaps::DibHeader& header);

private:
  ByteArray byteAccumulator;
};}

#endif