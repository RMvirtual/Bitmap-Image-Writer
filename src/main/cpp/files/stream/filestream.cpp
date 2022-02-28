#include <fstream>
#include <filesystem>

#include "src/main/cpp/containers/byte-array/byte_array.h"
#include "src/main/cpp/files/stream/filestream.h"

std::string Files::readFileToString(const std::string& filePath)
{
  std::ifstream file(filePath);

  std::string bytes(
    (std::istreambuf_iterator<char>(file)),
    std::istreambuf_iterator<char>()
  );

  file.close();

  return bytes;
}

ByteArray Files::readFileToByteArray(const std::string& filePath)
{
  std::string fileContents = Files::readFileToString(filePath);

  ByteArray byteArray {};
  byteArray.add(fileContents);

  return byteArray;
}

void Files::writeToFile(std::string filePath, const ByteArray& byteArray)
{
  std::ofstream file(filePath);

  for (auto byte : byteArray)
    file << byte;

  file.close();
}

int Files::getSizeOfFile(const std::string& filePath)
{
  std::filesystem::path pathToFile {filePath};

  return std::filesystem::file_size(pathToFile);
}