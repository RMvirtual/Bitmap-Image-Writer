#include "src/graphics/bitmaps/packet/pixel-array/size_calculator.h"

int Pixels::calculatePixelArraySizeInBytes(
  int widthInPixels, int heightInPixels)
{
  int rowSizeInBytes = Pixels::calculateRowSizeInBytes(widthInPixels);
  
  return rowSizeInBytes * heightInPixels;
}

int Pixels::calculateRowSizeInBytes(int widthInPixels)
{
  int padding = Pixels::calculateRowPadding(widthInPixels);
  int sizeOfPixelInBytes = 3;
  
  return widthInPixels * sizeOfPixelInBytes + padding;
}

int Pixels::calculateRowPadding(int widthInPixels)
{
  int unpaddedRowSize = Pixels::calculateUnpaddedRowSize(widthInPixels);
  int differenceInAlignment = unpaddedRowSize % 4;

  return differenceInAlignment ? 4 - differenceInAlignment : 0;
}

int Pixels::calculateUnpaddedRowSize(int widthInPixels)
{
  int sizeOfPixelsInBytes = 3;
  
  return widthInPixels * sizeOfPixelsInBytes;
}