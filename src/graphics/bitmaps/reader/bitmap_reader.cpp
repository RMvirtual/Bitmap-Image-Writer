#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

#include "src/graphics/bitmaps/reader/bitmap_reader.h"

using namespace std;

BitmapReader::BitmapReader()
{
  // Pass.
}

int BitmapReader::getLengthOfPayload(std::string filePath)
{
  string text;
  ifstream fileStream(filePath);

  while (getline(fileStream, text)) {
    cout << text;
  }

  fileStream.close();

  return 1;
}

int BitmapReader::getSizeOfFile(std::string filePath)
{
  std::filesystem::path pathToFile {filePath};
  int fileSizeInBytes = std::filesystem::file_size(pathToFile);

  cout << "Size is " << fileSizeInBytes << " bytes.\n";

  return fileSizeInBytes;
}