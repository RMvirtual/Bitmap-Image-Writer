#include <fstream>
#include <filesystem>

#include "src/common/filesystem/filesystem.h"
#include "src/common/byte-array/byte_array_builder.h"
#include "src/common/byte-array/byte_array.h"

std::string Filesystem::convertFileToString(std::string filePath)
{
  std::ifstream file(filePath);

  std::string bytes(
    (std::istreambuf_iterator<char>(file)),
    std::istreambuf_iterator<char>()
  );

  file.close();

  return bytes;   
}

ByteArray Filesystem::convertFileToByteArray(std::string filePath)
{
  std::string fileContents = Filesystem::convertFileToString(filePath);

  ByteArrayBuilder byteArrayBuilder {};
  byteArrayBuilder.add(fileContents);

  return byteArrayBuilder.toByteArray();
}

int Filesystem::getSizeOfFile(std::string filePath)
{
  std::filesystem::path pathToFile {filePath};

  return std::filesystem::file_size(pathToFile);
}
