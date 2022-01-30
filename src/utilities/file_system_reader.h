#ifndef FILE_SYSTEM_READER_H
#define FILE_SYSTEM_READER_H

#include <string>

#include "src/utilities/json_reader.h"

namespace Utilities {
class FileSystemReader : public JSONReader
{
public:
  FileSystemReader();

  std::string filePath(std::string fileNameAlias);  
};}

#endif