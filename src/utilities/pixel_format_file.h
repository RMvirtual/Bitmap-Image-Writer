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

  int indexByName(std::string formatName);
  std::string getFormatName(int index);
  int getBitsPerPixel(int index);
  std::vector<std::string> getColours(int index);

private:
  JSONReader reader;
};}

#endif