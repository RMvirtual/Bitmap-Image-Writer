#include <fstream>
#include <filesystem>

#include "src/containers/byte-array/byte_array.h"
#include "src/utilities/filesystem.h"

std::string Utilities::convertFileToString(const std::string& filePath)
{
  std::ifstream file(filePath);

  std::string bytes(
    (std::istreambuf_iterator<char>(file)),
    std::istreambuf_iterator<char>()
  );

  file.close();

  return bytes;
}

ByteArray Utilities::convertFileToByteArray(const std::string& filePath)
{
  std::string fileContents = Utilities::convertFileToString(filePath);

  ByteArray byteArray {};
  byteArray.add(fileContents);

  return byteArray;
}

int Utilities::getSizeOfFile(const std::string& filePath)
{
  std::filesystem::path pathToFile {filePath};

  return std::filesystem::file_size(pathToFile);
}