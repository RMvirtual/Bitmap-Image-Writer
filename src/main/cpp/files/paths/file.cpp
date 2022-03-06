#include <string>

#include "src/main/cpp/files/paths/file.h"
#include "src/main/cpp/files/json-reader/json_reader.h"

Files::FilePaths::FilePaths()
{
  // Harcoded path here. Relative path finder to be obtained later.
  this->reader = Files::JSONReader::fromArrayFile(
    "C://Users/rmvir/Desktop/scc300-Win3D/resources/filesystem.json");
}

std::string Files::FilePaths::filePath(std::string fileNameAlias)
{
  return this->reader.value<std::string>(fileNameAlias);
}