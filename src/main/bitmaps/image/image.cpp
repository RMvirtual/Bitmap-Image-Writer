#include "src/main/bitmaps/formats/format/format.h"
#include "src/main/bitmaps/formats/formats.h"
#include "src/main/bitmaps/formats/colours/colours.h"
#include "src/main/bitmaps/image/image.h"
#include "src/main/bitmaps/packet/headers/headers.h"
#include "src/main/utilities/filesystem.h"

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

Bitmaps::Image::Image(Bitmaps::Packet packet)
{
  this->packet = packet;

  int bitsPerPixel = this->packet.dibHeader.bitsPerPixel();
  this->format = Bitmaps::format(bitsPerPixel);
  this->format.setHeightInPixels(this->packet.dibHeader.heightInPixels());
  this->format.setWidthInPixels(this->packet.dibHeader.widthInPixels());
}

Bitmaps::Image::~Image()
{

}

void Bitmaps::Image::fill(Bitmaps::Colours colours)
{
  this->packet.pixelArray.fill(colours);
}

int Bitmaps::Image::widthInPixels() const
{
  return this->packet.dibHeader.widthInPixels();
}

int Bitmaps::Image::heightInPixels() const
{
  return this->packet.dibHeader.heightInPixels();
}

Bitmaps::Colours Bitmaps::Image::defaultColours() const
{
  return this->format.colours();
}

Bitmaps::FileHeader Bitmaps::Image::fileHeader() const
{
  return this->packet.fileHeader;
}

Bitmaps::DibHeader Bitmaps::Image::dibHeader() const
{
  return this->packet.dibHeader;
}

Bitmaps::PixelArray Bitmaps::Image::pixelArray() const
{
  return this->packet.pixelArray;
}