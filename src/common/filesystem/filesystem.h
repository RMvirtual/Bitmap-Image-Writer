#ifndef FILE_OPENER_H
#define FILE_OPENER_H

#include <string>
#include "src/common/byte-array/byte_array.h"

namespace Filesystem
{
  std::string convertFileToString(std::string filePath);
  ByteArray convertFileToByteArray(std::string filePath);
  int getSizeOfFile(std::string filePath);
};

#endif