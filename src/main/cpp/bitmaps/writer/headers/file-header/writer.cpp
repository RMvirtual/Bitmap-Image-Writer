#include "src/main/cpp/bitmaps/packet/headers/file-header/header.h"
#include "src/main/cpp/bitmaps/writer/headers/file-header/writer.h"
#include "src/main/cpp/containers/byte-array/byte_array.h"

Bitmaps::FileHeaderWriter::FileHeaderWriter()
{
  // pass.
}

ByteArray Bitmaps::FileHeaderWriter::write(
  std::shared_ptr<Bitmaps::FileHeader> header)
{
  ByteArray byteArray {};
  byteArray.add(header->signatureBytes());
  byteArray.add(header->fileSizeInBytes()); 
  byteArray.add(header->reservedBytes()); 
  byteArray.add(header->pixelArrayOffsetInBytes());

  return byteArray;
}