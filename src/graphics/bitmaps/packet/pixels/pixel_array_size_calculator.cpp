#include "src/graphics/bitmaps/packet/pixels/pixel_array_size_calculator.h"

int Pixels::calculatePixelArraySizeInBytes(
  int widthInPixels, int heightInPixels)
{
  int rowSizeInBytes = Pixels::calculateRowSizeInBytes(widthInPixels);
  int pixelArraySizeInBytes = rowSizeInBytes * heightInPixels;

  return pixelArraySizeInBytes;
}

int Pixels::calculateRowSizeInBytes(int widthInPixels)
{
  int padding = Pixels::calculateRowPadding(widthInPixels);
  int sizeOfPixelInBytes = 3;
  
  int rowSizeInBytes = widthInPixels * sizeOfPixelInBytes + padding;

  return rowSizeInBytes;
}

int Pixels::calculateRowPadding(int widthInPixels)
{
  int padding = 0;
  int sizeOfPixelsInBytes = 3;
  
  int unpaddedRowSize = widthInPixels * sizeOfPixelsInBytes;
  int differenceInAlignment = unpaddedRowSize % 4;

  if (differenceInAlignment)
    padding = 4 - differenceInAlignment;

  return padding;
}