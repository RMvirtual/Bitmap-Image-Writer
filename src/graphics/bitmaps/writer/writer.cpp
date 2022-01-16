#include "src/graphics/bitmaps/writer/writer.h"
#include "src/common/byte-array/byte_array.h"
#include "src/graphics/bitmaps/packet/headers/file-header/file_header.h"
#include "src/graphics/bitmaps/packet/headers/dib-header/dib_header.h"
#include "src/graphics/bitmaps/packet/pixel-array/arrays/pixel_array.h"
#include "src/graphics/bitmaps/packet/pixel-array/pixels/rgb_pixel.h"
#include "src/graphics/bitmaps/packet/bitmap_packet.h"

BitmapWriter::ImageWriter::ImageWriter()
{
  // pass.
}

ByteArray BitmapWriter::ImageWriter::convertToBytes(const BitmapPacket& packet)
{
  auto fileHeaderBytes = this->convertToBytes(packet.fileHeader);
  auto dibHeaderBytes = this->convertToBytes(packet.dibHeader);
  auto pixelArrayBytes = this->convertToBytes(packet.pixelArray);

  ByteArray allBytes {};

  allBytes.add(fileHeaderBytes);
  allBytes.add(dibHeaderBytes);
  allBytes.add(pixelArrayBytes);

  return allBytes;
}

ByteArray BitmapWriter::ImageWriter::convertToBytes(
  const BitmapHeaders::FileHeader& header)
{
  ByteArray byteArray {};
  auto signatureBytes = header.signatureBytes();
  
  byteArray.add(signatureBytes[0]);
  byteArray.add(signatureBytes[1]);
  byteArray.add(header.fileSizeInBytes()); 
  byteArray.add(header.reservedBytes()); 
  byteArray.add(header.pixelArrayOffsetInBytes());

  return byteArray;
}

ByteArray BitmapWriter::ImageWriter::convertToBytes(
  const BitmapHeaders::DibHeader& header)
{
  ByteArray byteArray {};

  byteArray.add(header.headerSizeInBytes());
  byteArray.add(header.widthInPixels());
  byteArray.add(header.heightInPixels());
  byteArray.add(header.numberOfColorPlanes());
  byteArray.add(header.colorDepth());
  byteArray.add(header.compressionMethod());
  byteArray.add(header.rawBitmapDataSize());
  byteArray.add(header.horizontalResolution());
  byteArray.add(header.verticalResolution());
  byteArray.add(header.colorTableEntries());
  byteArray.add(header.importantColors());

  return byteArray;
}

ByteArray BitmapWriter::ImageWriter::convertToBytes(
  const Pixels::PixelArray& pixelArray)
{
  ByteArray byteArray {};
  int numberOfPixels = pixelArray.sizeInPixels();

  // No accounting for row stride yet.
  for (int pixelNo = 0; pixelNo < numberOfPixels; pixelNo++) {
    auto pixel = pixelArray.at(pixelNo);
    auto pixelBytes = this->convertToBytes(pixel);

    byteArray.add(pixelBytes);
  }

  return byteArray;
}

ByteArray BitmapWriter::ImageWriter::convertToBytes(
  const Pixels::RGBPixel& pixel)
{
  auto colours = pixel.colours();
  ByteArray byteArray {};

  byteArray.add(colours.blue());
  byteArray.add(colours.green());
  byteArray.add(colours.red());

  return byteArray;
}