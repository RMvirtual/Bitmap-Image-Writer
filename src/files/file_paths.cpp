#include <string>

#include "src/utilities/json_reader.h"
#include "src/files/file_paths.h"

Files::FilePaths::FilePaths()
{
  // Harcoded path here. Relative path finder to be obtained later.
  this->reader.read(
    "C://Users/rmvir/Desktop/scc300-Win3D/resources/filesystem.json");
}

std::string Files::FilePaths::filePath(std::string fileNameAlias)
{
  return this->reader.value<std::string>(fileNameAlias);
}