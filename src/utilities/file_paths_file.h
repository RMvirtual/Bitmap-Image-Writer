#ifndef FILE_PATHS_FILE_H
#define FILE_PATHS_FILE_H

#include <string>
#include "src/utilities/json_reader.h"

namespace Utilities {
class FilePathsFile
{
public:
  FilePathsFile();

  std::string filePath(std::string fileNameAlias);

private:
  JSONReader reader;
  
};}

#endif