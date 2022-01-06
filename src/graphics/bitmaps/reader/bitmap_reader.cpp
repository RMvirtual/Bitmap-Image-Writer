#include "src/graphics/bitmaps/packet/headers/bitmap_image_headers.h"
#include "src/graphics/bitmaps/reader/bitmap_reader.h"

BitmapImageHeaders BitmapReader::getBitmapImageHeaders(std::string filePath)
{
  BitmapHeaders::FileHeader fileHeader = BitmapReader::getBitmapFileHeader(
    filePath);
  
  BitmapHeaders::DibHeader dibHeader = BitmapReader::getBitmapDibHeader(
    filePath);
  
  Pixels::PixelArray pixelArray = BitmapReader::getPixelArray(filePath);

  BitmapImageHeaders bitmapHeaders;
  
  bitmapHeaders.fileHeader = fileHeader;
  bitmapHeaders.dibHeader = dibHeader;
  bitmapHeaders.pixelArray = pixelArray;

  return bitmapHeaders;
}