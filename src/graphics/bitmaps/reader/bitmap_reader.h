#include <string>

#include "src/graphics/bitmaps/headers/file_header.h"
#include "src/graphics/bitmaps/headers/dib_header.h"
#include "src/graphics/bitmaps/pixel_array.h"

class BitmapReader
{
public:
  BitmapReader();

  BitmapFileHeader getBitmapFileHeader(std::string filePath);
  BitmapDibHeader getBitmapDibHeader(std::string filePath);
  int getLengthOfPixelPayload(std::string filePath);
  PixelArray getPixelArray(std::string filePath);
};