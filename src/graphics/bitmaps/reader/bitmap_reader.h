#include <string>

#include "src/graphics/bitmaps/packet/headers/file_header.h"
#include "src/graphics/bitmaps/packet/headers/dib_header.h"
#include "src/graphics/bitmaps/packet/pixels/pixel_array.h"

namespace BitmapReader
{
  BitmapHeaders::FileHeader getBitmapFileHeader(std::string filePath);
  BitmapHeaders::DibHeader getBitmapDibHeader(std::string filePath);
  int getPixelArraySizeInBytes(std::string filePath);
  PixelArray getPixelArray(std::string filePath);
};