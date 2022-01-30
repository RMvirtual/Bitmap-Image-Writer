#ifndef PIXEL_FORMAT_FILE_READER_H
#define PIXEL_FORMAT_FILE_READER_H

#include <string>
#include "src/utilities/json_reader.h"

namespace Utilities {
class PixelFormatFileReader : public JSONReader
{
public:
  PixelFormatFileReader();

  std::string getFormatName(int index);
  int getBitsPerPixel(int index);
  std::vector<std::string> getColours(int index);
};}

#endif