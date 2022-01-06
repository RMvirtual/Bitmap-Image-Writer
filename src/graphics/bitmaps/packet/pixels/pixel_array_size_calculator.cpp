#include "src/graphics/bitmaps/packet/pixels/pixel_array_size_calculator.h"

int Pixels::calculatePixelArraySizeInBytes(
  int widthInPixels, int heightInPixels)
{
  const int rowSizeInBytes = Pixels::calculateRowSizeInBytes(widthInPixels);
  
  return rowSizeInBytes * heightInPixels;
}

int Pixels::calculateRowSizeInBytes(int widthInPixels)
{
  const int padding = Pixels::calculateRowPadding(widthInPixels);
  const int sizeOfPixelInBytes = 3;
  
  return widthInPixels * sizeOfPixelInBytes + padding;
}

int Pixels::calculateRowPadding(int widthInPixels)
{
  const int unpaddedRowSize = Pixels::calculateUnpaddedRowSize(widthInPixels);
  const int differenceInAlignment = unpaddedRowSize % 4;

  return differenceInAlignment ? 4 - differenceInAlignment : 0;
}

int Pixels::calculateUnpaddedRowSize(int widthInPixels)
{
  const int sizeOfPixelsInBytes = 3;
  
  return widthInPixels * sizeOfPixelsInBytes;
}