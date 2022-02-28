#pragma once

#include <string>
#include "src/main/cpp/files/json-reader/json_reader.h"

namespace Files {
class FilePaths
{
public:
  FilePaths();

  std::string filePath(std::string fileNameAlias);

private:
  Files::JSONReader reader;  
};}
