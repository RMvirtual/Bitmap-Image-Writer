#include <string>

#include "src/main/cpp/files/pixel-formats/file.h"
#include "src/main/cpp/bitmaps/formats/format/format.h"
#include "src/main/cpp/bitmaps/formats/formats.h"

Bitmaps::Format Bitmaps::format(std::string formatName)
{
  auto formatData = Files::PixelFormats::format(formatName);

  Bitmaps::Format format {};
  format.setName(formatData.name);
  format.setColourNames(formatData.colours);
  format.setBitsPerPixel(formatData.bitsPerPixel);

  return format;
}