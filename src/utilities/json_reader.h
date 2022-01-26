#ifndef JSON_READER_H
#define JSON_READER_H

#include "lib/nlohmann/json.hpp"
#include <string>

namespace Utilities {
class JSONReader
{
public:
  JSONReader();
  std::string getFormatName(int index);
  int getBitsPerPixel(int index);

  std::string pixelFormatsFilePath;

private:
  nlohmann::json readJsonFromFile(std::string filePath);
};}

#endif