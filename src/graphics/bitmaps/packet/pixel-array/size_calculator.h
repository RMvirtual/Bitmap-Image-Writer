namespace Pixels
{
  int calculatePixelArraySizeInBytes(int widthInPixels, int heightInPixels);
  int calculateRowSizeInBytes(int widthInPixels);
  int calculateRowPadding(int widthInPixels);
  int calculateUnpaddedRowSize(int widthInPixels);
  int calculatePixelSizeInBytes(int bitsPerPixel);
};