#include "src/common/file_opener.h"
#include <fstream>
#include <filesystem>

using namespace std;

std::string FileOpener::convertFileToString(std::string filePath)
{
  ifstream file(filePath);

  string bytes(
    (std::istreambuf_iterator<char>(file)),
    std::istreambuf_iterator<char>()
  );

  file.close();

  return bytes;   
}

int FileOpener::getSizeOfFile(string filePath)
{
  filesystem::path pathToFile {filePath};
  int fileSizeInBytes = filesystem::file_size(pathToFile);

  return fileSizeInBytes;
}