#include "src/bitmaps/writer/pixel_array_writer.h"

Bitmaps::PixelArrayByteWriter::PixelArrayByteWriter()
{

}

ByteArray Bitmaps::PixelArrayByteWriter::write(
  const Bitmaps::PixelArray& pixelArray)
{
  this->initialise(pixelArray);
  int noOfRows = this->format.heightInPixels();

  for (int rowNo = 0; rowNo < noOfRows; rowNo++)
    this->writeRowOfPixels(rowNo);

  return this->bytes;
}

void Bitmaps::PixelArrayByteWriter::initialise(
  const Bitmaps::PixelArray& pixelArray)
{
  this->pixelArray = pixelArray;
  this->format = this->pixelArray.format();
  this->bytes = {};
}

void Bitmaps::PixelArrayByteWriter::writeRowOfPixels(int rowNo)
{
  auto pixelsPerRow = this->format.widthInPixels();

  int rowStart = rowNo * pixelsPerRow;
  int rowEnd = rowStart + pixelsPerRow;

  this->writePixels(rowStart, rowEnd);
  this->addRowPadding();
}

void Bitmaps::PixelArrayByteWriter::writePixels(int startIndex, int endIndex)
{
  for (int pixelNo = startIndex; pixelNo < endIndex; pixelNo++)
    this->write(this->pixelArray.at(pixelNo));
}

void Bitmaps::PixelArrayByteWriter::write(const Bitmaps::Colours& colours)
{
  for (auto colourAndValue : colours)
    this->bytes.add(colourAndValue.second);
}

void Bitmaps::PixelArrayByteWriter::addRowPadding()
{
  auto padding = this->format.rowPaddingInBytes();

  for (int byteNo = 0; byteNo < padding; byteNo++)
    this->bytes.add((uint8_t) 0);
}