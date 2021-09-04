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
    BitmapFileHeader fileHeader, BitmapHeaders::DibHeader dibHeader,
    PixelArray PixelArray
  );

  static BitmapImage fromFile(std::string filePath);

  char* toBytes();
  void writeToFile(std::string filePath);

  void setFileHeader(BitmapFileHeader fileHeader);
  void setDibHeader(BitmapHeaders::DibHeader dibHeader);
  void setPixelArray(PixelArray pixelArray);

  int getSizeOfFile();
  int32_t getWidthInPixels();
  int32_t getHeightInPixels();
  int getNumberOfPixels();

  void setSizeOfFile(uint32_t sizeOfBitmapFile);
  void setWidthInPixels(int32_t widthInPixels);
  void setHeightInPixels(int32_t heightInPixels);
  void setPixel(int row, int column, Pixel pixel);

  BitmapFileHeader getFileHeader();
  BitmapHeaders::DibHeader getDibHeader();
  PixelArray getPixelArray();

private:
  BitmapFileHeader fileHeader;
  BitmapHeaders::DibHeader dibHeader;
  PixelArray pixelArray;

  void recalculateFileSize();
};

#endif