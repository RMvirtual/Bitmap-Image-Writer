#ifndef BITMAP_IMAGE_WRITER_H
#define BITMAP_IMAGE_WRITER_H

#include <string>

#include "src/main/bitmaps/image/image.h"
#include "src/main/containers/byte-array/byte_array.h"

namespace Bitmaps {
class ImageWriter
{
public:
  ImageWriter();
  ByteArray write(const Bitmaps::Image& image);
  void writeToFile(const Bitmaps::Image& image, std::string filePath);

private:
  ByteArray byteArray;
};}

#endif