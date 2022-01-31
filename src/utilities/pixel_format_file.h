#ifndef PIXEL_FORMAT_FILE_H
#define PIXEL_FORMAT_FILE_H

#include <string>
#include <vector>

#include "src/utilities/json_reader.h"

namespace Utilities {
class PixelFormatFile
{
public:
  PixelFormatFile();

  int indexOf(std::string formatName);
  int indexOf(int bitsPerPixel);
  std::string formatName(int index);
  int bitsPerPixel(int index);
  std::vector<std::string> colours(int index);

private:
  JSONReader reader;
};}

#endif