#include "src/bitmaps/packet/headers/file-header/header.h"
#include "src/bitmaps/writer/headers/file-header/writer.h"
#include "src/containers/byte-array/byte_array.h"

Bitmaps::FileHeaderWriter::FileHeaderWriter()
{
  // pass.
}

ByteArray Bitmaps::FileHeaderWriter::write(const Bitmaps::FileHeader& header)
{
  ByteArray byteArray {};
  byteArray.add(header.signatureBytes());
  byteArray.add(header.fileSizeInBytes()); 
  byteArray.add(header.reservedBytes()); 
  byteArray.add(header.pixelArrayOffsetInBytes());

  return byteArray;
}