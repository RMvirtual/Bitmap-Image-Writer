#ifndef FILE_OPENER_H
#define FILE_OPENER_H

#include <string>
#include "src/containers/byte-array/byte_array.h"

namespace Utilities
{
  std::string convertFileToString(const std::string& filePath);
  ByteArray convertFileToByteArray(const std::string& filePath);
  int getSizeOfFile(const std::string& filePath);
};

#endif