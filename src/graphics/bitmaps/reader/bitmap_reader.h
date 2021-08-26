#include <string>

#include "src/graphics/bitmaps/headers/file_header.h"
#include "src/graphics/bitmaps/headers/dib_header.h"

class BitmapReader
{
public:
  BitmapReader();
  int getLengthOfPixelPayload(std::string filePath);
  int getSizeOfFile(std::string filePath);
  BitmapFileHeader getBitmapFileHeader(std::string filePath);
  BitmapDibHeader getBitmapInfoHeader(std::string filePath);
  uint32_t convert32BitStringToInteger(std::string bytesString);
  uint16_t convert16BitStringToInteger(std::string bytesString);
};