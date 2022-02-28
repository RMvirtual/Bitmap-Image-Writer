#include "src/main/cpp/files/pixel-formats/file.h"
#include "src/main/cpp/files/paths/file.h"

Files::PixelFormats::PixelFormats()
{
  // Hardcoding system path here till a reader is developed.
  std::string systemPath {"C://Users/rmvir/Desktop/scc300-Win3D/"};

  Files::FilePaths files {};
  auto filePath = files.filePath("pixel_formats");

  this->reader = {};
  this->reader.read(systemPath + filePath);
}

int Files::PixelFormats::indexOf(std::string formatName)
{
  int noOfFormats = this->reader.numberOfObjects();

  for (int formatNo = 0; formatNo < noOfFormats; formatNo++) {
    auto name = this->formatName(formatNo);

    if (name == formatName)
      return formatNo;
  }

  return -1;
}

int Files::PixelFormats::indexOf(int bitsPerPixel)
{
  int noOfFormats = this->reader.numberOfObjects();

  for (int formatNo = 0; formatNo < noOfFormats; formatNo++) {
    auto currentBitsPerPixel = this->bitsPerPixel(formatNo);

    if (currentBitsPerPixel == bitsPerPixel)
      return formatNo;
  }

  return -1;
}

std::string Files::PixelFormats::formatName(int index)
{
  return this->reader.value<std::string>(index, "name");
}

int Files::PixelFormats::bitsPerPixel(int index)
{
  std::string name {"bitsPerPixel"};
  
  return this->reader.value<int>(index, name);
}

std::vector<std::string> Files::PixelFormats::colours(int index)
{
  return this->reader.value<std::vector<std::string>>(index, "colours");
}