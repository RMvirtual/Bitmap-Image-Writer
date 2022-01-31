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

int Utilities::PixelFormatFile::indexOf(std::string formatName)
{
  int index = 0;
  int numberOfObjects = this->reader.numberOfObjects();

  for (int i = 0; i < numberOfObjects; i++) {
    auto name = this->formatName(i);

    if (name == formatName)
      return index;
  }

  return -1;
}

std::string Utilities::PixelFormatFile::formatName(int index)
{
  return this->reader.value<std::string>(index, "name");
}

int Utilities::PixelFormatFile::bitsPerPixel(int index)
{
  std::string name {"bitsPerPixel"};
  
  return this->reader.value<int>(index, name);
}

std::vector<std::string> Utilities::PixelFormatFile::colours(int index)
{
  return this->reader.value<std::vector<std::string>>(index, "colours");
}