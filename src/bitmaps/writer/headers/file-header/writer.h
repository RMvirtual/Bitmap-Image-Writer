#ifndef BITMAP_FILE_HEADER_WRITER_H
#define BITMAP_FILE_HEADER_WRITER_H

#include "src/bitmaps/packet/headers/file-header/header.h"
#include "src/containers/byte-array/byte_array.h"

namespace Bitmaps {
class FileHeaderWriter
{
public:
  FileHeaderWriter();
  ByteArray write(const Bitmaps::FileHeader& header);

private:
  ByteArray byteAccumulator;
};}

#endif