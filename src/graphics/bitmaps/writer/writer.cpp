#include "src/graphics/bitmaps/writer/writer.h"
#include "src/common/byte_array_builder.h"
#include "src/common/byte_array.h"
#include "src/graphics/bitmaps/packet/headers/file_header.h"
#include "src/graphics/bitmaps/packet/headers/dib_header.h"
// #include "src/graphics/bitmaps/packet/pixels/pixel_array.h"
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

ByteArray BitmapWriter::writePixelArray(Pixels::PixelArray pixelArray)
{
  return {};
}

ByteArray BitmapWriter::writePixel(Pixels::Pixel pixel)
{
  ByteArrayBuilder byteArrayBuilder {};

  byteArrayBuilder.addValue(pixel.getBlue());
  byteArrayBuilder.addValue(pixel.getGreen());
  byteArrayBuilder.addValue(pixel.getRed());

  return byteArrayBuilder.toByteArray();
}

/*
void Pixels::PixelArray::addAllPixelsToByteArray(
  ByteArrayBuilder* byteArrayBuilder)
{
  for (int rowNo = 0; rowNo < this->heightInPixels; rowNo++) {
    unsigned char* pixelRowBytes = this->getRowOfPixelsAsBytes(rowNo);
    byteArrayBuilder->addValues(pixelRowBytes, this->rowSizeInBytes);

    delete[] pixelRowBytes;
  }
}

void Pixels::PixelArray::addRowOfPixelsToByteArray(
  int rowNo, ByteArrayBuilder* byteArrayBuilder)
{
  for (int columnNo = 0; columnNo < this->widthInPixels; columnNo++)
    this->addPixelByIndexToByteArray(rowNo, columnNo, byteArrayBuilder);
}

void Pixels::PixelArray::addPixelByIndexToByteArray(
  int rowNo, int columnNo, ByteArrayBuilder* byteArrayBuilder)
{
  Pixels::Pixel pixel = this->getPixel(rowNo, columnNo);
  this->addPixelToByteArray(pixel, byteArrayBuilder);
}


void Pixels::PixelArray::addPixelToByteArray(
  Pixels::Pixel pixel, ByteArrayBuilder* byteArrayBuilder)
{
  unsigned char* pixelBytes = pixel.toByte();
  byteArrayBuilder->addValues(pixelBytes, 3);

  delete[] pixelBytes;
}

void Pixels::PixelArray::addPaddingBytesToByteArray(
  ByteArrayBuilder* byteArrayBuilder)
{
  for (int byteNo = 0; byteNo < this->rowPadding; byteNo++)
    byteArrayBuilder->addValue(0);
}

unsigned char* Pixels::PixelArray::getRowOfPixelsAsBytes(int rowNo)
{
  ByteArrayBuilder byteArrayBuilder;

  this->addRowOfPixelsToByteArray(rowNo, &byteArrayBuilder);
  this->addPaddingBytesToByteArray(&byteArrayBuilder);

  return byteArrayBuilder.toBytes();
}
*/