#include "src/main/cpp/bitmaps/formats/format/format.h"
#include "src/main/cpp/bitmaps/formats/formats.h"
#include "src/main/cpp/bitmaps/formats/colours/colours.h"
#include "src/main/cpp/bitmaps/image/image.h"
#include "src/main/cpp/bitmaps/packet/headers/headers.h"
#include "src/main/cpp/files/stream/filestream.h"

Bitmaps::Image::Image()
{

}

Bitmaps::Image::Image(Bitmaps::Format format)
{
  Bitmaps::FileHeader fileHeader {format.arraySizeInBytes()};
  Bitmaps::DibHeader dibHeader {format};
  Bitmaps::PixelArray pixelArray {format};

  this->packet.fileHeader = std::make_shared<Bitmaps::FileHeader>(
    format.arraySizeInBytes());
  
  this->packet.dibHeader = std::make_shared<Bitmaps::DibHeader>(format);
  this->packet.pixelArray = std::make_shared<Bitmaps::PixelArray>(format);
  this->format = format;
}

Bitmaps::Image::Image(Bitmaps::Packet packet)
{
  this->packet = packet;
  int bitsPerPixel = this->packet.dibHeader->bitsPerPixel();

  std::string formatName = "RGBA32";

  if (bitsPerPixel == 24)
    formatName = "RGB24";

  this->format = Bitmaps::format(formatName);
  this->format.setHeightInPixels(this->packet.dibHeader->heightInPixels());
  this->format.setWidthInPixels(this->packet.dibHeader->widthInPixels());
}

Bitmaps::Image::~Image()
{

}

void Bitmaps::Image::setPixel(int row, int column, Bitmaps::Colours colours)
{
  this->packet.pixelArray->set(colours, row, column);
}

void Bitmaps::Image::fill(Bitmaps::Colours colours)
{
  this->packet.pixelArray->fill(colours);
}

int Bitmaps::Image::widthInPixels() const
{
  return this->packet.dibHeader->widthInPixels();
}

int Bitmaps::Image::heightInPixels() const
{
  return this->packet.dibHeader->heightInPixels();
}

Bitmaps::Colours Bitmaps::Image::defaultColours() const
{
  return this->format.colours();
}

std::shared_ptr<Bitmaps::FileHeader> Bitmaps::Image::fileHeader()
{
  return this->packet.fileHeader;
}

std::shared_ptr<Bitmaps::DibHeader> Bitmaps::Image::dibHeader()
{
  return this->packet.dibHeader;
}

std::shared_ptr<Bitmaps::PixelArray> Bitmaps::Image::pixelArray()
{
  return {this->packet.pixelArray};
}