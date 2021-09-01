#ifndef BITMAP_IMAGE_H
#define BITMAP_IMAGE_H

#include "src/graphics/bitmaps/packet/headers/file_header.h"
#include "src/graphics/bitmaps/packet/headers/dib_header.h"
#include "src/graphics/bitmaps/packet/pixels/pixel_array.h"

class BitmapImage
{
public:
  BitmapImage();
  
  BitmapImage(
    BitmapFileHeader fileHeader, BitmapDibHeader dibHeader,
    PixelArray PixelArray
  );

  static BitmapImage fromFile(std::string filePath);

  char* toBytes();
  void writeToFile(std::string filePath);

  void setFileHeader(BitmapFileHeader fileHeader);
  void setDibHeader(BitmapDibHeader dibHeader);
  void setPixelArray(PixelArray pixelArray);

  void setSizeOfBitmapFile(uint32_t sizeOfBitmapFile);
  int getSizeOfFile();

  BitmapFileHeader getFileHeader();
  BitmapDibHeader getDibHeader();
  PixelArray getPixelArray();

private:
  BitmapFileHeader fileHeader;
  BitmapDibHeader dibHeader;
  PixelArray pixelArray;
};

#endif