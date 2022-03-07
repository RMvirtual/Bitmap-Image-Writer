#include "src/main/cpp/files/pixel-formats/file.h"
#include "src/main/cpp/files/paths/file.h"

Files::JSONReader Files::PixelFormats::reader()
{
  std::string systemPath {"C://Users/rmvir/Desktop/scc300-Win3D/"};
  auto filePath = Files::FilePaths::path("pixel_formats");

  return Files::JSONReader::fromArrayFile(systemPath + filePath);
}

int Files::PixelFormats::indexOf(std::string formatName)
{
  auto reader = Files::PixelFormats::reader();
  int noOfFormats = reader.numberOfObjects();

  for (int formatNo = 0; formatNo < noOfFormats; formatNo++) {
    auto name = Files::PixelFormats::formatName(formatNo);

    if (name == formatName)
      return formatNo;
  }

  return -1;
}

int Files::PixelFormats::indexOf(int bitsPerPixel)
{
  auto reader = Files::PixelFormats::reader();
  int noOfFormats = reader.numberOfObjects();

  for (int formatNo = 0; formatNo < noOfFormats; formatNo++) {
    auto currentBitsPerPixel = Files::PixelFormats::bitsPerPixel(formatNo);

    if (currentBitsPerPixel == bitsPerPixel)
      return formatNo;
  }

  return -1;
}

std::string Files::PixelFormats::formatName(int index)
{
  auto reader = Files::PixelFormats::reader();  
  return reader.value<std::string>(index, "name");
}

int Files::PixelFormats::bitsPerPixel(int index)
{
  auto reader = Files::PixelFormats::reader();  
  
  return reader.value<int>(index, "bitsPerPixel");
}

std::vector<std::string> Files::PixelFormats::colours(int index)
{
  auto reader = Files::PixelFormats::reader();

  return reader.value<std::vector<std::string>>(index, "colours");
}