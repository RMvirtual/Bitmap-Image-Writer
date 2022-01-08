#ifndef BITMAP_IMAGE_H
#define BITMAP_IMAGE_H

#include "src/graphics/bitmaps/packet/bitmap_packet.h"
#include "src/graphics/bitmaps/packet/headers/file_header.h"
#include "src/graphics/bitmaps/packet/headers/dib_header.h"
#include "src/graphics/bitmaps/packet/pixels/pixel_array.h"
#include "src/graphics/bitmaps/packet/pixels/pixel_data.h"

class BitmapImage
{
public:
  BitmapImage();

  static BitmapImage fromPacket(BitmapPacket headers);
  static BitmapImage fromFile(std::string filePath);

  void writeToFile(std::string filePath);

  void setFileHeader(BitmapHeaders::FileHeader fileHeader);
  void setDibHeader(BitmapHeaders::DibHeader dibHeader);
  void setPixelArray(Pixels::PixelArray pixelArray);

  int getSizeOfFile();
  int32_t getWidthInPixels();
  int32_t getHeightInPixels();
  int getNumberOfPixels();

  void setSizeOfFile(uint32_t sizeOfBitmapFile);
  void setWidthInPixels(int32_t widthInPixels);
  void setHeightInPixels(int32_t heightInPixels);
  void setPixel(Pixels::PixelData pixelData);

  BitmapHeaders::FileHeader getFileHeader();
  BitmapHeaders::DibHeader getDibHeader();
  Pixels::PixelArray getPixelArray();

private:
  BitmapHeaders::FileHeader fileHeader;
  BitmapHeaders::DibHeader dibHeader;
  Pixels::PixelArray pixelArray;

  void recalculateFileSize();
};

#endif