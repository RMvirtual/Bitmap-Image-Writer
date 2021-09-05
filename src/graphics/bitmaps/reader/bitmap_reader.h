#include <string>
#include <vector>

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

  void parseNumberOfColourPlanes(
    std::string bytes, BitmapHeaders::DibHeader* dibHeader);

  void parseColourDepth(
    std::string bytes, BitmapHeaders::DibHeader* dibHeader);

  void parseCompressionMethod(
    std::string bytes, BitmapHeaders::DibHeader* dibHeader);

  void parseRawBitmapDataSize(
    std::string bytes, BitmapHeaders::DibHeader* dibHeader);

  void parseHorizontalPixelsPerMetre(
    std::string bytes, BitmapHeaders::DibHeader* dibHeader);

  void parseVerticalPixelsPerMetre(
    std::string bytes, BitmapHeaders::DibHeader* dibHeader);

  void parseColourTableEntries(
    std::string bytes, BitmapHeaders::DibHeader* dibHeader);

  void parseImportantColours(
    std::string bytes, BitmapHeaders::DibHeader* dibHeader);

  Pixels::PixelArray parseBytesToVector(
    std::string* bytes, BitmapHeaders::FileHeader fileHeader,
    BitmapHeaders::DibHeader dibHeader);

  void parseRowOfBytesToVector(
    std::string* bytes, std::vector<Pixels::Pixel>* pixels, 
    int widthInPixels, int rowStartingByteNo);

  void parsePixelFromBytesToVector(
    std::string* bytes, std::vector<Pixels::Pixel>* pixels, int startingByteNo);

  Pixels::Pixel parsePixelFromBytes(std::string* bytes, int startingByteNo);

};