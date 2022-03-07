#include <string>

#include "src/main/cpp/files/pixel-formats/file.h"
#include "src/main/cpp/bitmaps/formats/format/format.h"
#include "src/main/cpp/bitmaps/formats/formats.h"

Bitmaps::Format Bitmaps::format(std::string formatName)
{
  int index = Files::PixelFormats::indexOf(formatName);

  return Bitmaps::formatByIndex(index);
}

Bitmaps::Format Bitmaps::format(int bitsPerPixel)
{
  int index = Files::PixelFormats::indexOf(bitsPerPixel);

  return Bitmaps::formatByIndex(index);
}

Bitmaps::Format Bitmaps::formatByIndex(int index)
{
  Bitmaps::Format format {};
  format.setName(Files::PixelFormats::formatName(index));
  format.setColourNames(Files::PixelFormats::colours(index));
  format.setBitsPerPixel(Files::PixelFormats::bitsPerPixel(index));

  return format;
}