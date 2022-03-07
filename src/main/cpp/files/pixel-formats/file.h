#pragma once

#include <string>
#include <vector>

#include "src/main/cpp/files/json-reader/json_reader.h"

namespace Files {
namespace PixelFormats
{
  struct Format
  {
    std::string name; 
    int bitsPerPixel;
    std::vector<std::string> colours;
  };

  PixelFormats::Format format(std::string name);
  
  int indexOf(std::string formatName);
  int indexOf(int bitsPerPixel);
  std::string formatName(int index);
  int bitsPerPixel(int index);
  std::vector<std::string> colours(int index);

  Files::JSONReader reader();
};}