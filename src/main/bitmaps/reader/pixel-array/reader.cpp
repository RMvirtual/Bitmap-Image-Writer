#include "src/main/containers/byte-array/byte_array.h"
#include "src/main/bitmaps/formats/format/format.h"
#include "src/main/bitmaps/packet/pixel-array/array.h"
#include "src/main/bitmaps/reader/pixel-array/reader.h"

Bitmaps::PixelArrayReader::PixelArrayReader(const Bitmaps::Format& format)
{
  this->format = format;
}

Bitmaps::PixelArray Bitmaps::PixelArrayReader::convertBytes(
  const ByteArray& bytes)
{
  this->initialise(bytes);
  int noOfPixelRows = this->format.heightInPixels();

  for (int rowNo = 0; rowNo < noOfPixelRows; rowNo++)
    this->readRowOfPixels(rowNo);

  return this->pixelArray;
}

void Bitmaps::PixelArrayReader::initialise(const ByteArray& bytes)
{
  this->pixelArray = {this->format};
  this->bytes = bytes;
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
  int startIndex, int endIndex, int pixelRowNo)
{
  int bytesPerPixel = this->format.bytesPerPixel();
  int pixelsPerRow = this->format.widthInPixels();

  for (int pixelNo = 0; pixelNo < pixelsPerRow; pixelNo++) {
    int byteNo = startIndex + (pixelNo * bytesPerPixel);
    auto colours = this->readColours(byteNo);

    pixelArray.set(colours, pixelRowNo, pixelNo);
  }
}

Bitmaps::Colours Bitmaps::PixelArrayReader::readColours(int byteIndex)
{
  int bytesPerPixel = this->format.bytesPerPixel();
  int endOfPixel = byteIndex + bytesPerPixel;

  auto colours = this->format.colours();
  
  for (int byteNo = byteIndex; byteNo < endOfPixel; byteNo++) {
    int colourIndex = byteNo - byteIndex;
    colours[colourIndex] = this->bytes[byteNo];
  }

  return colours;
}