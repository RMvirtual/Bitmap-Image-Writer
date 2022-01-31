#include <string>

#include "src/graphics/bitmaps/packet/formats/format.h"
#include "src/utilities/pixel_format_file.h"

namespace Pixels {
Pixels::Format format(std::string formatName)
{
  Utilities::PixelFormatFile reader {};
  
  int index = reader.indexOf(formatName);

  Pixels::Format format {};
  format.name = reader.formatName(index);
  format.colourNames = reader.colours(index);
  format.bitsPerPixel = reader.bitsPerPixel(index);

  return format;
};}