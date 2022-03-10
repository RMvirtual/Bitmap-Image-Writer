#include <string>
#include <memory>

#include "src/main/cpp/bitmaps/writer/image/writer.h"
#include "src/main/cpp/bitmaps/writer/headers/file-header/writer.h"
#include "src/main/cpp/bitmaps/writer/headers/dib-header/writer.h"
#include "src/main/cpp/bitmaps/writer/pixel-array/writer.h"
#include "src/main/cpp/containers/byte-array/byte_array.h"
#include "src/main/cpp/files/stream/filestream.h"

#include <iostream>

Bitmaps::ImageWriter::ImageWriter()
{
  // pass.
}

ByteArray Bitmaps::ImageWriter::write(std::shared_ptr<Bitmaps::Image> image)
{
  this->byteArray = {};

  Bitmaps::FileHeaderWriter fileHeaderWriter;
  this->byteArray.add(fileHeaderWriter.write(image->fileHeader()));

  Bitmaps::DibHeaderWriter dibHeaderWriter;
  this->byteArray.add(dibHeaderWriter.write(image->dibHeader()));
    
  Bitmaps::PixelArrayWriter pixelArrayWriter;
  this->byteArray.add(pixelArrayWriter.write(image->pixelArray()));
  std::cout << "Gets pixel array writer.\n";

  return this->byteArray;
}

void Bitmaps::ImageWriter::writeToFile(
  std::shared_ptr<Bitmaps::Image> image, std::string filePath)
{
  auto bytes = this->write(image);
  Files::writeToFile(filePath, bytes);
}