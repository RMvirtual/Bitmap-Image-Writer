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

  int getSizeOfFile();
  int32_t getWidthInPixels();
  int32_t getHeightInPixels();

  void setSizeOfFile(uint32_t sizeOfBitmapFile);
  void setWidthInPixels(int32_t widthInPixels);
  void setHeightInPixels(int32_t heightInPixels);

  BitmapFileHeader getFileHeader();
  BitmapDibHeader getDibHeader();
  PixelArray getPixelArray();

private:
  BitmapFileHeader fileHeader;
  BitmapDibHeader dibHeader;
  PixelArray pixelArray;
};

#endif