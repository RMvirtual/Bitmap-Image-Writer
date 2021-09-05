#include <string>

#include "src/graphics/bitmaps/packet/headers/file_header.h"
#include "src/graphics/bitmaps/packet/headers/dib_header.h"
#include "src/graphics/bitmaps/packet/pixels/pixel_array.h"

namespace BitmapReader
{
  BitmapHeaders::FileHeader getBitmapFileHeader(std::string filePath);
  BitmapHeaders::DibHeader getBitmapDibHeader(std::string filePath);
  int getPixelArraySizeInBytes(std::string filePath);
  Pixels::PixelArray getPixelArray(std::string filePath);

  BitmapHeaders::FileHeader parseFileHeader(std::string bytes);
  BitmapHeaders::DibHeader parseDibHeader(std::string bytes);

  void parseSignatureBytes(
    std::string bytes, BitmapHeaders::FileHeader* fileHeader);

  void parseSizeOfBitmapFile(
    std::string bytes, BitmapHeaders::FileHeader* fileHeader);

  void parseReservedBytes(
    std::string bytes, BitmapHeaders::FileHeader* fileHeader);

  void parsePixelDataOffset(
    std::string bytes, BitmapHeaders::FileHeader* fileHeader);

  void parseHeaderSize(
    std::string bytes, BitmapHeaders::DibHeader* dibHeader);

  void parseWidthInPixels(
    std::string bytes, BitmapHeaders::DibHeader* dibHeader);

  void parseHeightInPixels(
    std::string bytes, BitmapHeaders::DibHeader* dibHeader);

};