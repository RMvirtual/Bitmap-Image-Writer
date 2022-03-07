#include <string>

#include "src/main/cpp/files/paths/file.h"
#include "src/main/cpp/files/json-reader/json_reader.h"

std::string Files::FilePaths::path(std::string fileNameAlias)
{
  // Harcoded path here. Relative path finder to be obtained later.
  auto reader = Files::JSONReader::fromArrayFile(
    "C://Users/rmvir/Desktop/scc300-Win3D/resources/filesystem.json");

  return reader.value<std::string>(fileNameAlias);
}