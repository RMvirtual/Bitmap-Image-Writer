#include <string>

#include "src/graphics/bitmaps/headers/file_header.h"
#include "src/graphics/bitmaps/headers/dib_header.h"

class BitmapReader
{
public:
  BitmapReader();

  BitmapFileHeader getBitmapFileHeader(std::string filePath);
  BitmapDibHeader getBitmapDibHeader(std::string filePath);
  int getSizeOfFile(std::string filePath);
  int getLengthOfPixelPayload(std::string filePath);

private:
};