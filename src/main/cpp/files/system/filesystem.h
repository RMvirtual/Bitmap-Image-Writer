#pragma once

#include <string>
#include "src/main/cpp/containers/byte-array/byte_array.h"

namespace Files
{
  std::string readFileToString(const std::string& filePath);
  ByteArray readFileToByteArray(const std::string& filePath);
  void writeToFile(std::string filePath, const ByteArray& byteArray);
  int getSizeOfFile(const std::string& filePath);
};