#include "src/graphics/bitmaps/writer/writer.h"
#include "src/common/byte-array/byte_array.h"
#include "src/graphics/bitmaps/packet/headers/file-header/file_header.h"
#include "src/graphics/bitmaps/packet/headers/dib-header/dib_header.h"
#include "src/graphics/bitmaps/packet/pixel-array/array/array.h"
#include "src/graphics/bitmaps/packet/pixel-array/pixel/pixel.h"
#include "src/graphics/bitmaps/packet/bitmap_packet.h"
#include "src/graphics/bitmaps/packet/pixel-array/pixel/format.h"

BitmapWriter::ImageWriter::ImageWriter()
{
  // pass.
}

ByteArray BitmapWriter::ImageWriter::convertToBytes(const BitmapPacket& packet)
{
  ByteArray allBytes {};

  allBytes.add(this->convertToBytes(packet.fileHeader));
  allBytes.add(this->convertToBytes(packet.dibHeader));
  allBytes.add(this->convertToBytes(packet.pixelArray));

  return allBytes;
}

ByteArray BitmapWriter::ImageWriter::convertToBytes(
  const BitmapHeaders::FileHeader& header)
{
  ByteArray byteArray {};
  byteArray.add(header.signatureBytes());
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
  byteArray.add(header.bitsPerPixel());
  byteArray.add(header.compressionMethod());
  byteArray.add(header.sizeOfPixelArray());
  byteArray.add(header.horizontalResolution());
  byteArray.add(header.verticalResolution());
  byteArray.add(header.colorTableEntries());
  byteArray.add(header.importantColors());

  return byteArray;
}

ByteArray BitmapWriter::ImageWriter::convertToBytes(
  const Pixels::Array& pixelArray)
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

ByteArray BitmapWriter::ImageWriter::convertToBytes(const Pixels::Pixel& pixel)
{
  auto colours = pixel.format().colours;
  ByteArray byteArray {};

  byteArray.add(colours["blue"]);
  byteArray.add(colours["green"]);
  byteArray.add(colours["red"]);

  return byteArray;
}