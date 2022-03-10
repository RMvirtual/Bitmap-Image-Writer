#pragma once

#include <memory>
#include "src/main/cpp/containers/byte-array/byte_array.h"
#include "src/main/cpp/bitmaps/formats/format/format.h"
#include "src/main/cpp/bitmaps/packet/pixel-array/array.h"

namespace Bitmaps {
class PixelArrayReader
{
public:
  PixelArrayReader(const Bitmaps::Format& format);

  std::shared_ptr<Bitmaps::PixelArray> convertBytes(
    std::shared_ptr<ByteArray> bytes);

  void readRowOfPixels(int rowNo);
  void readPixels(int startIndex, int endIndex, int pixelRowNo);
  Bitmaps::Colours readColours(int index);

private:
  Bitmaps::Format format;
  std::shared_ptr<Bitmaps::PixelArray> pixelArray;
  std::shared_ptr<ByteArray> bytes;
};}