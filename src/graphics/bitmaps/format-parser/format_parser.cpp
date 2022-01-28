#include <string>

#include "src/graphics/bitmaps/format-parser/format_parser.h"

FormatParser::FormatParser()
{
  std::string formatsFile = {
    "C://Users/rmvir/Desktop/scc300-Win3D/resources/pixel_formats.json"};

  this->read(formatsFile);
}
Pixels::Format FormatParser::operator [](std::string formatName)
{
  Pixels::Format format {};

  format.name = this->getFormatName(formatName);
  format.bitsPerPixel = this->getBitsPerPixel();
  format.colourNames = this->getColours();

  return format;
}
