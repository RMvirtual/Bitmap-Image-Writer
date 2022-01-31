#include "src/utilities/pixel_format_file.h"
#include "src/utilities/file_paths_file.h"
#include "src/utilities/json_reader.h"

Utilities::PixelFormatFile::PixelFormatFile()
{
  // Hardcoding system path here till a reader is developed.
  std::string systemPath {"C://Users/rmvir/Desktop/scc300-Win3D/"};

  Utilities::FilePathsFile files {};
  auto filePath = files.filePath("pixel_formats");

  this->reader = {};
  this->reader.read(systemPath + filePath);
}

int Utilities::PixelFormatFile::indexByName(std::string formatName)
{
  int index = 0;

  for (auto name : this->reader.fieldNames()) {
    if (name == formatName)
      return index;

    index++;
  }

  return -1;
}

std::string Utilities::PixelFormatFile::getFormatName(int index)
{
  return this->reader.value<std::string>(index, "name");
}

int Utilities::PixelFormatFile::getBitsPerPixel(int index)
{
  std::string name {"bitsPerPixel"};
  
  return this->reader.value<int>(index, name);
}

std::vector<std::string> Utilities::PixelFormatFile::getColours(int index)
{
  return this->reader.value<std::vector<std::string>>(index, "colours");
}