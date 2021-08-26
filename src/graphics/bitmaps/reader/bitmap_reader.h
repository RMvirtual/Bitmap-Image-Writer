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
  BitmapDibHeader getBitmapDibHeader(std::string filePath);

  std::string getStringOfBytesFromFile(std::string filePath); 
  uint32_t getFourBytesFromString(std::string bytes, int startingByteIndex);
  uint16_t getTwoBytesFromString(std::string bytes, int startingByteIndex);
  uint32_t convertStringTo32BitInteger(std::string bytesString);
  uint16_t convertStringTo16BitInteger(std::string bytesString);
};