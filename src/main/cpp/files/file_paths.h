#ifndef FILE_PATHS_FILE_H
#define FILE_PATHS_FILE_H

#include <string>
#include "src/main/cpp/utilities/json_reader.h"

namespace Files {
class FilePaths
{
public:
  FilePaths();

  std::string filePath(std::string fileNameAlias);

private:
  Utilities::JSONReader reader;
  
};}

#endif