#include "src/bitmaps/image/image.h"
#include "src/bitmaps/formats/format.h"
#include "src/bitmaps/packet/headers/headers.h"
#include "src/utilities/filesystem.h"
#include "src/bitmaps/writer/writer.h"

Bitmaps::Image::Image()
{

}

Bitmaps::Image::Image(Bitmaps::Format format)
{
  Bitmaps::FileHeader fileHeader {format.arraySizeInBytes()};
  Bitmaps::DibHeader dibHeader {format};
  Bitmaps::PixelArray pixelArray {format};

  this->packet.fileHeader = fileHeader;
  this->packet.dibHeader = dibHeader;
  this->packet.pixelArray = pixelArray;
  this->format = format;
}

Bitmaps::Image::~Image()
{

}

void Bitmaps::Image::writeToFile(std::string filePath)
{
  Bitmaps::ByteWriter writer;
  auto bytes = writer.write(this->packet);

  Utilities::writeToFile(filePath, bytes);
}

void Bitmaps::Image::fill(Bitmaps::Colours colours)
{
  this->packet.pixelArray.fill(colours);
}

Bitmaps::Colours Bitmaps::Image::defaultColours()
{
  return this->format.colours();
}