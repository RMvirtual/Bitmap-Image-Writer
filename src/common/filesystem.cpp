#include "src/common/filesystem.h"
#include <fstream>
#include <filesystem>

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

int Filesystem::getSizeOfFile(std::string filePath)
{
  std::filesystem::path pathToFile {filePath};
  int fileSizeInBytes = std::filesystem::file_size(pathToFile);

  return fileSizeInBytes;
}