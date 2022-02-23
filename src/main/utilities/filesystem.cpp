#include <fstream>
#include <filesystem>

#include "src/main/containers/byte-array/byte_array.h"
#include "src/main/utilities/filesystem.h"

std::string Utilities::readFileToString(const std::string& filePath)
{
  std::ifstream file(filePath);

  std::string bytes(
    (std::istreambuf_iterator<char>(file)),
    std::istreambuf_iterator<char>()
  );

  file.close();

  return bytes;
}

ByteArray Utilities::readFileToByteArray(const std::string& filePath)
{
  std::string fileContents = Utilities::readFileToString(filePath);

  ByteArray byteArray {};
  byteArray.add(fileContents);

  return byteArray;
}

void Utilities::writeToFile(std::string filePath, const ByteArray& byteArray)
{
  std::ofstream file(filePath);

  for (auto byte : byteArray)
    file << byte;

  file.close();
}

int Utilities::getSizeOfFile(const std::string& filePath)
{
  std::filesystem::path pathToFile {filePath};

  return std::filesystem::file_size(pathToFile);
}