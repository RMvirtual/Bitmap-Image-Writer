#include "src/main/cpp/containers/byte-array/byte_array.h"
#include "src/main/cpp/bitmaps/formats/format/format.h"
#include "src/main/cpp/bitmaps/packet/pixel-array/array.h"
#include "src/main/cpp/bitmaps/reader/pixel-array/reader.h"

Bitmaps::PixelArrayReader::PixelArrayReader(const Bitmaps::Format& format)
{
  this->format = format;
  this->pixelArray = std::make_shared<Bitmaps::PixelArray>(format);
}

std::shared_ptr<Bitmaps::PixelArray> Bitmaps::PixelArrayReader::convertBytes(
  std::shared_ptr<ByteArray> bytes)
{
  this->bytes = bytes;
  int noOfPixelRows = this->format.heightInPixels();

  for (int rowNo = 0; rowNo < noOfPixelRows; rowNo++)
    this->readRowOfPixels(rowNo);

  return this->pixelArray;
}

void Bitmaps::PixelArrayReader::readRowOfPixels(int rowNo)
{
  int bytesPerRow = this->format.bytesPerRow();
  int bytesPerUnpaddedRow = this->format.bytesPerUnpaddedRow();

  int rowStart = rowNo * bytesPerRow;
  int rowEnd = rowStart + bytesPerUnpaddedRow;

  this->readPixels(rowStart, rowEnd, rowNo);
}

void Bitmaps::PixelArrayReader::readPixels(
  int startIndex, int endIndex, int rowNo)
{
  int bytesPerPixel = this->format.bytesPerPixel();
  int pixelsPerRow = this->format.widthInPixels();

  for (int pixelNo = 0; pixelNo < pixelsPerRow; pixelNo++) {
    int byteNo = startIndex + (pixelNo * bytesPerPixel);
    auto colours = this->readColours(byteNo);

    this->pixelArray->set(colours, rowNo, pixelNo);
  }
}

Bitmaps::Colours Bitmaps::PixelArrayReader::readColours(int byteIndex)
{
  int bytesPerPixel = this->format.bytesPerPixel();
  int endOfPixel = byteIndex + bytesPerPixel;

  auto colours = this->format.colours();
  
  for (int byteNo = byteIndex; byteNo < endOfPixel; byteNo++) {
    int colourIndex = byteNo - byteIndex;
    colours[colourIndex] = this->bytes->at(byteNo);
  }

  return colours;
}