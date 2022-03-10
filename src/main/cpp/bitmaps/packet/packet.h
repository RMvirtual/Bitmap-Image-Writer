#pragma once
#include <memory>

#include "src/main/cpp/bitmaps/packet/headers/file-header/header.h"
#include "src/main/cpp/bitmaps/packet/headers/dib-header/header.h"
#include "src/main/cpp/bitmaps/packet/pixel-array/array.h"

namespace Bitmaps {
struct Packet
{
  std::shared_ptr<Bitmaps::FileHeader> fileHeader;
  std::shared_ptr<Bitmaps::DibHeader> dibHeader;
  std::shared_ptr<Bitmaps::PixelArray> pixelArray;
};}