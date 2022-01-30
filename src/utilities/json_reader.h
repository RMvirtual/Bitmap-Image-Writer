#ifndef JSON_READER_H
#define JSON_READER_H

#include "lib/nlohmann/json.hpp"
#include <string>
#include <vector>

namespace Utilities {
class JSONReader
{
public:
  JSONReader();
  void read(std::string filePath);

  std::string getFormatName(int index);
  int getBitsPerPixel(int index);
  std::vector<std::string> getColours(int index);
  std::vector<std::string> fieldNames();
  std::string value(std::string fieldName);

protected:
  nlohmann::json json;

private:
  nlohmann::json readJsonFromFile(std::string filePath);
};}

#endif