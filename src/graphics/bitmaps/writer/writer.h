#ifndef BITMAP_WRITER_H
#define BITMAP_WRITER_H

#include "src/graphics/bitmaps/packet/headers/file_header.h"
#include "src/graphics/bitmaps/packet/headers/dib_header.h"

class BitmapWriter
{
public:
  BitmapWriter();
  ByteArray writeFileHeader(BitmapHeaders::FileHeader header);
  
private:

};

#endif