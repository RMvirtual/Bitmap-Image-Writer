#include "src/main/cpp/files/pixel-formats/file.h"
#include "src/main/cpp/files/paths/file.h"

Files::PixelFormats::FormatData Files::PixelFormats::format(std::string name)
{
  std::string systemPath {"C://Users/rmvir/Desktop/scc300-Win3D/"};
  auto filePath = Files::FilePaths::path("pixel_formats");

  auto reader = Files::JSONReader::fromArrayFile(systemPath + filePath);
  Files::PixelFormats::FormatData format;

  format.name = name;
  format.bitsPerPixel = reader.value<int>(name, "bitsPerPixel");
  format.colours = reader.value<std::vector<std::string>>(name, "colours");

  return format;
}
