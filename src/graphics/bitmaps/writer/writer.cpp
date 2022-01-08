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

  std::string signatureBytes = header.getSignatureBytes();
  byteArrayBuilder.addValue(signatureBytes[0]);
  byteArrayBuilder.addValue(signatureBytes[1]);
  byteArrayBuilder.addValue(header.getSizeOfBitmapFile()); 
  byteArrayBuilder.addValue(header.getReservedBytes()); 
  byteArrayBuilder.addValue(header.getPixelDataOffset());

  return byteArrayBuilder.toByteArray();
}

ByteArray BitmapWriter::writeDibHeader(BitmapHeaders::DibHeader header)
{
  ByteArrayBuilder byteArrayBuilder {};

  byteArrayBuilder.addValue(header.getHeaderSizeInBytes());
  byteArrayBuilder.addValue(header.getWidthInPixels());
  byteArrayBuilder.addValue(header.getHeightInPixels());
  byteArrayBuilder.addValue(header.getNumberOfColorPlanes());
  byteArrayBuilder.addValue(header.getColorDepth());
  byteArrayBuilder.addValue(header.getCompressionMethod());
  byteArrayBuilder.addValue(header.getRawBitmapDataSize());
  byteArrayBuilder.addValue(header.getHorizontalPixelsPerMetre());
  byteArrayBuilder.addValue(header.getVerticalPixelsPerMetre());
  byteArrayBuilder.addValue(header.getColorTableEntries());
  byteArrayBuilder.addValue(header.getImportantColors());

  return byteArrayBuilder.toByteArray();
}