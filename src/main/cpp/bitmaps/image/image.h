#pragma once

#include <memory>
#include "src/main/cpp/bitmaps/packet/packet.h"
#include "src/main/cpp/bitmaps/formats/format/format.h"
#include "src/main/cpp/bitmaps/formats/colours/colours.h"

namespace Bitmaps {
class Image
{
public:
  Image();
  Image(Bitmaps::Format format);
  Image(Bitmaps::Packet packet);
  ~Image();

  void fill(Bitmaps::Colours colours);
  void setPixel(int row, int column, Bitmaps::Colours colours);
  int widthInPixels() const;
  int heightInPixels() const;

  Colours defaultColours() const;
  std::shared_ptr<Bitmaps::FileHeader> fileHeader();
  std::shared_ptr<Bitmaps::DibHeader> dibHeader();
  std::shared_ptr<Bitmaps::PixelArray> pixelArray();

private:
  Bitmaps::Packet packet;
  Bitmaps::Format format;
};}