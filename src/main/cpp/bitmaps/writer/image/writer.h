#pragma once

#include <string>
#include "src/main/cpp/bitmaps/image/image.h"
#include "src/main/cpp/containers/byte-array/byte_array.h"

namespace Bitmaps {
class ImageWriter
{
public:
  ImageWriter();
  
  ByteArray write(std::shared_ptr<Bitmaps::Image> image);
  
  void writeToFile(
    std::shared_ptr<Bitmaps::Image> image, std::string filePath);

private:
  ByteArray byteArray;
};}