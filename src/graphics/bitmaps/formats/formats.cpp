#include <string>

#include "src/files/pixel_formats.h"
#include "src/graphics/bitmaps/formats/format.h"
#include "src/graphics/bitmaps/formats/formats.h"
#include "src/graphics/bitmaps/packet/headers/headers.h"

Pixels::Format Pixels::format(BitmapHeaders::Headers headers)
{
  return Pixels::format(headers.dibHeader);
}

Pixels::Format Pixels::format(BitmapHeaders::DibHeader header)
{
  int bitsPerPixel = header.bitsPerPixel();

  auto format = Pixels::format(bitsPerPixel);
  format.setWidthInPixels(header.widthInPixels());
  format.setHeightInPixels(header.heightInPixels());

  return format;
}

Pixels::Format Pixels::format(std::string formatName)
{
  Files::PixelFormats formatsFile {};
  int index = formatsFile.indexOf(formatName);

  return Pixels::formatByIndex(index);
}

Pixels::Format Pixels::format(int bitsPerPixel)
{
  Files::PixelFormats formatsFile {};
  int index = formatsFile.indexOf(bitsPerPixel);

  return Pixels::formatByIndex(index);
}

Pixels::Format Pixels::formatByIndex(int index)
{
  Files::PixelFormats formatsFile {};

  Pixels::Format format {};
  format.setName(formatsFile.formatName(index));
  format.setColourNames(formatsFile.colours(index));
  format.setBitsPerPixel(formatsFile.bitsPerPixel(index));

  return format;
}