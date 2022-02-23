#include "src/main/bitmaps/writer/pixel-array/writer.h"

Bitmaps::PixelArrayWriter::PixelArrayWriter()
{

}

ByteArray Bitmaps::PixelArrayWriter::write(const Bitmaps::PixelArray& array)
{
  this->initialise(array);
  int noOfRows = this->format.heightInPixels();

  for (int rowNo = 0; rowNo < noOfRows; rowNo++)
    this->writeRowOfPixels(rowNo);

  return this->bytes;
}

void Bitmaps::PixelArrayWriter::initialise(const Bitmaps::PixelArray& array)
{
  this->pixelArray = array;
  this->format = this->pixelArray.format();
  this->bytes = {};
}

void Bitmaps::PixelArrayWriter::writeRowOfPixels(int rowNo)
{
  auto pixelsPerRow = this->format.widthInPixels();

  int rowStart = rowNo * pixelsPerRow;
  int rowEnd = rowStart + pixelsPerRow;

  this->writePixels(rowStart, rowEnd);
  this->addRowPadding();
}

void Bitmaps::PixelArrayWriter::writePixels(int startIndex, int endIndex)
{
  for (int pixelNo = startIndex; pixelNo < endIndex; pixelNo++)
    this->write(this->pixelArray.at(pixelNo));
}

void Bitmaps::PixelArrayWriter::write(const Bitmaps::Colours& colours)
{
  for (auto colourAndValue : colours)
    this->bytes.add(colourAndValue.second);
}

void Bitmaps::PixelArrayWriter::addRowPadding()
{
  auto padding = this->format.bytesPaddingPerRow();

  for (int byteNo = 0; byteNo < padding; byteNo++)
    this->bytes.add((uint8_t) 0);
}