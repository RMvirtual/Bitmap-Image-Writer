#include "src/graphics/bitmaps/writer/writer.h"
#include "src/common/byte_array_builder.h"
#include "src/common/byte_array.h"
#include "src/graphics/bitmaps/packet/headers/file_header.h"
#include "src/graphics/bitmaps/packet/headers/dib_header.h"
#include "src/graphics/bitmaps/packet/pixels/pixel_array.h"
#include "src/graphics/bitmaps/packet/pixels/pixel.h"
#include "src/graphics/bitmaps/packet/bitmap_packet.h"

BitmapWriter::BitmapWriter()
{
  // pass.
}

ByteArray BitmapWriter::writeFileHeader(BitmapHeaders::FileHeader header)
{
  ByteArrayBuilder byteArrayBuilder {};

  // May not interpret string > char properly here.
  std::string signatureBytes = header.getSignatureBytes();
  byteArrayBuilder.addValue(signatureBytes[0]);
  byteArrayBuilder.addValue(signatureBytes[1]);

  byteArrayBuilder.addValue(header.getSizeOfBitmapFile()); // int may be wrong size.
  byteArrayBuilder.addValue(header.getReservedBytes()); // int may be wrong size.
  byteArrayBuilder.addValue(header.getPixelDataOffset()); // int may be wrong size.

  return byteArrayBuilder.toByteArray();
}

