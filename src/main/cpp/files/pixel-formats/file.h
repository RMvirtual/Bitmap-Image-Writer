#pragma once

#include <string>
#include <vector>

#include "src/main/cpp/files/json-reader/json_reader.h"

namespace Files {
namespace PixelFormats
{
  struct FormatData
  {
    std::string name; 
    int bitsPerPixel;
    std::vector<std::string> colours;
  };

  FormatData format(std::string name);
};}