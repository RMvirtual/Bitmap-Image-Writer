#include "src/bitmaps/formats/bitmap/format.h"
#include "src/bitmaps/formats/colours/colours.h"
#include "src/bitmaps/image/image.h"
#include "src/bitmaps/packet/headers/headers.h"
#include "src/utilities/filesystem.h"

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