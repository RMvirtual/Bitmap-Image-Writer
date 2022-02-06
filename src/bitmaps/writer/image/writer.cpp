#include <string>

#include "src/bitmaps/writer/image/writer.h"
#include "src/bitmaps/writer/headers/file-header/writer.h"
#include "src/bitmaps/writer/headers/dib-header/writer.h"
#include "src/bitmaps/writer/pixel-array/writer.h"
#include "src/containers/byte-array/byte_array.h"
#include "src/utilities/filesystem.h"

Bitmaps::ImageWriter::ImageWriter()
{
  // pass.
}

ByteArray Bitmaps::ImageWriter::write(const Bitmaps::Image& image)
{
  this->byteArray = {};

  Bitmaps::FileHeaderWriter fileHeaderWriter;
  this->byteArray.add(fileHeaderWriter.write(image.fileHeader()));

  Bitmaps::DibHeaderWriter dibHeaderWriter;
  this->byteArray.add(dibHeaderWriter.write(image.dibHeader()));
  
  Bitmaps::PixelArrayWriter pixelArrayWriter;
  this->byteArray.add(pixelArrayWriter.write(image.pixelArray()));

  return this->byteArray;
}

void Bitmaps::ImageWriter::writeToFile(
  const Bitmaps::Image& image, std::string filePath)
{
  auto bytes = this->write(image);
  Utilities::writeToFile(filePath, bytes);
}