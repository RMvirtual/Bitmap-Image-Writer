#include "src/main/cpp/bitmaps/packet/headers/dib-header/header.h"
#include "src/main/cpp/bitmaps/writer/headers/dib-header/writer.h"
#include "src/main/cpp/containers/byte-array/byte_array.h"

Bitmaps::DibHeaderWriter::DibHeaderWriter()
{
  // pass.
}

ByteArray Bitmaps::DibHeaderWriter::write(const Bitmaps::DibHeader& header)
{
  ByteArray byteArray {};

  byteArray.add(header.headerSizeInBytes());
  byteArray.add(header.widthInPixels());
  byteArray.add(header.heightInPixels());
  byteArray.add(header.numberOfColorPlanes());
  byteArray.add(header.bitsPerPixel());
  byteArray.add(header.compressionMethod());
  byteArray.add(header.sizeOfPixelArray());
  byteArray.add(header.horizontalResolution());
  byteArray.add(header.verticalResolution());
  byteArray.add(header.colorTableEntries());
  byteArray.add(header.importantColors());

  return byteArray;
}