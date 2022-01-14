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
  byteArrayBuilder.add(signatureBytes[0]);
  byteArrayBuilder.add(signatureBytes[1]);
  byteArrayBuilder.add(header.getSizeOfBitmapFile()); 
  byteArrayBuilder.add(header.getReservedBytes()); 
  byteArrayBuilder.add(header.getPixelDataOffset());

  return byteArrayBuilder.toByteArray();
}

ByteArray BitmapWriter::writeDibHeader(BitmapHeaders::DibHeader header)
{
  ByteArrayBuilder byteArrayBuilder {};

  byteArrayBuilder.add(header.getHeaderSizeInBytes());
  byteArrayBuilder.add(header.getWidthInPixels());
  byteArrayBuilder.add(header.getHeightInPixels());
  byteArrayBuilder.add(header.getNumberOfColorPlanes());
  byteArrayBuilder.add(header.getColorDepth());
  byteArrayBuilder.add(header.getCompressionMethod());
  byteArrayBuilder.add(header.getRawBitmapDataSize());
  byteArrayBuilder.add(header.getHorizontalPixelsPerMetre());
  byteArrayBuilder.add(header.getVerticalPixelsPerMetre());
  byteArrayBuilder.add(header.getColorTableEntries());
  byteArrayBuilder.add(header.getImportantColors());

  return byteArrayBuilder.toByteArray();
}

ByteArray BitmapWriter::writePixelArray(Pixels::PixelArray pixelArray)
{
  ByteArrayBuilder byteArrayBuilder {};
  int numberOfPixels = pixelArray.sizeInPixels();

  // No accounting for row stride yet.
  for (int pixelNo = 0; pixelNo < numberOfPixels; pixelNo++) {
    Pixels::RGBPixel pixel = pixelArray.getPixel(pixelNo);
    ByteArray pixelBytes = this->writePixel(pixel);

    byteArrayBuilder.add(pixelBytes);
  }

  return byteArrayBuilder.toByteArray();
}

ByteArray BitmapWriter::writePixel(Pixels::RGBPixel pixel)
{
  ByteArrayBuilder byteArrayBuilder {};

  byteArrayBuilder.add(pixel.getBlue());
  byteArrayBuilder.add(pixel.getGreen());
  byteArrayBuilder.add(pixel.getRed());

  return byteArrayBuilder.toByteArray();
}