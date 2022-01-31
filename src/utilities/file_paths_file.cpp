#include <string>

#include "src/utilities/json_reader.h"
#include "src/utilities/file_paths_file.h"

Utilities::FilePathsFile::FilePathsFile()
{
  // Harcoded path here. Relative path finder to be obtained later.
  this->reader.read(
    "C://Users/rmvir/Desktop/scc300-Win3D/resources/filesystem.json");
}

std::string Utilities::FilePathsFile::filePath(std::string fileNameAlias)
{
  return this->reader.value<std::string>(fileNameAlias);
}
