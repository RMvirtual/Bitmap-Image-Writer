#ifndef BITMAP_IMAGE_H
#define BITMAP_IMAGE_H

#include "src/graphics/bitmaps/packet/headers/file_header.h"
#include "src/graphics/bitmaps/packet/headers/dib_header.h"
#include "src/graphics/bitmaps/packet/pixels/pixel_array.h"

class BitmapImage
{
public:
  BitmapImage(
    BitmapFileHeader fileHeader, BitmapDibHeader dibHeader,
    PixelArray PixelArray
  );

  char* toBytes();
  int getSizeOfBytes();

  void setFileHeader(BitmapFileHeader fileHeader);
  void setDibHeader(BitmapDibHeader dibHeader);
  void setPixelArray(PixelArray pixelArray);
  BitmapFileHeader getFileHeader();
  BitmapDibHeader getDibHeader();
  PixelArray getPixelArray();

private:
  BitmapFileHeader fileHeader;
  BitmapDibHeader dibHeader;
  PixelArray pixelArray;
};

#endif