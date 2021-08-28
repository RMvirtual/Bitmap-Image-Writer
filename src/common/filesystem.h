#ifndef FILE_OPENER_H
#define FILE_OPENER_H

#include <string>

namespace Filesystem
{
  std::string convertFileToString(std::string filePath);
  int getSizeOfFile(std::string filePath);
};

#endif