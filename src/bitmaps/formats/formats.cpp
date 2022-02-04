#include <string>

#include "src/files/pixel_formats.h"
#include "src/bitmaps/formats/format.h"
#include "src/bitmaps/formats/formats.h"

Bitmaps::Format Bitmaps::format(std::string formatName)
{
  Files::PixelFormats formatsFile {};
  int index = formatsFile.indexOf(formatName);

  return Bitmaps::formatByIndex(index);
}

Bitmaps::Format Bitmaps::format(int bitsPerPixel)
{
  Files::PixelFormats formatsFile {};
  int index = formatsFile.indexOf(bitsPerPixel);

  return Bitmaps::formatByIndex(index);
}

Bitmaps::Format Bitmaps::formatByIndex(int index)
{
  Files::PixelFormats formatsFile {};

  Bitmaps::Format format {};
  format.setName(formatsFile.formatName(index));
  format.setColourNames(formatsFile.colours(index));
  format.setBitsPerPixel(formatsFile.bitsPerPixel(index));

  return format;
}