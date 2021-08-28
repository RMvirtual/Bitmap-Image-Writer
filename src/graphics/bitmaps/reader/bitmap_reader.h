#include <string>

#include "src/graphics/bitmaps/packet/headers/file_header.h"
#include "src/graphics/bitmaps/packet/headers/dib_header.h"
#include "src/graphics/bitmaps/packet/pixels/pixel_array.h"

namespace BitmapReader
{
  BitmapFileHeader getBitmapFileHeader(std::string filePath);
  BitmapDibHeader getBitmapDibHeader(std::string filePath);
  int getPixelArraySizeInBytes(std::string filePath);
  PixelArray getPixelArray(std::string filePath);
};