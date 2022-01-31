#include <string>

#include "src/graphics/bitmaps/packet/formats/format.h"
#include "src/files/pixel_formats.h"

namespace Pixels {
Pixels::Format format(std::string formatName)
{
  Files::PixelFormats formatsFile {};
  int index = formatsFile.indexOf(formatName);

  Pixels::Format format {};
  format.name = formatsFile.formatName(index);
  format.colourNames = formatsFile.colours(index);
  format.bitsPerPixel = formatsFile.bitsPerPixel(index);

  return format;
}

Pixels::Format format(int bitsPerPixel)
{
  Files::PixelFormats formatsFile {};
  int index = formatsFile.indexOf(bitsPerPixel);

  Pixels::Format format {};
  format.name = formatsFile.formatName(index);
  format.colourNames = formatsFile.colours(index);
  format.bitsPerPixel = formatsFile.bitsPerPixel(index);

  return format;
};}