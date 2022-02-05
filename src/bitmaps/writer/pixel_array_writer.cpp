#include "src/bitmaps/writer/pixel_array_writer.h"

Bitmaps::PixelArrayByteWriter::PixelArrayByteWriter()
{

}

ByteArray Bitmaps::PixelArrayByteWriter::write(
  const Bitmaps::PixelArray& pixelArray)
{
  this->format = pixelArray.format();
  this->pixelArray = pixelArray;

  this->byteAccumulator = {};

  int numberOfRows = this->format.heightInPixels();

  for (int rowNo = 0; rowNo < numberOfRows; rowNo++)
    this->writeRowOfPixels(rowNo);

  return this->byteAccumulator;
}

void Bitmaps::PixelArrayByteWriter::writeRowOfPixels(int rowNo)
{
  auto pixelsPerRow = this->format.widthInPixels();

  int startOfRow = rowNo * pixelsPerRow;
  int endOfRow = startOfRow + pixelsPerRow;

  this->writePixels(startOfRow, endOfRow);
  this->addRowPadding();
}

void Bitmaps::PixelArrayByteWriter::writePixels(int startIndex, int endIndex)
{
  for (int pixelNo = startIndex; pixelNo < endIndex; pixelNo++)
    this->write(this->pixelArray.at(pixelNo));
}

void Bitmaps::PixelArrayByteWriter::addRowPadding()
{
  auto padding = this->format.rowPaddingInBytes();

  for (int byteNo = 0; byteNo < padding; byteNo++)
    this->byteAccumulator.add(0);
}

void Bitmaps::PixelArrayByteWriter::write(const Bitmaps::Colours& colours)
{
  for (auto colourAndValue : colours)
    this->byteAccumulator.add(colourAndValue.second);
}