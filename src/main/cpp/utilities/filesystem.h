#ifndef FILE_OPENER_H
#define FILE_OPENER_H

#include <string>
#include "src/main/cpp/containers/byte-array/byte_array.h"

namespace Utilities
{
  std::string readFileToString(const std::string& filePath);
  ByteArray readFileToByteArray(const std::string& filePath);
  void writeToFile(std::string filePath, const ByteArray& byteArray);
  int getSizeOfFile(const std::string& filePath);
};

#endif