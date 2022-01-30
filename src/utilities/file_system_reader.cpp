#include <string>
#include "src/utilities/file_system_reader.h"

Utilities::FileSystemReader::FileSystemReader()
{
  // Harcoded path here. Relative path finder to be obtained later.
  this->read("C://Users/rmvir/Desktop/scc300-Win3D/resources/filesystem.json");
}

std::string Utilities::FileSystemReader::filePath(std::string fileNameAlias)
{
  return "Fail";
}

