#include "src/main/cpp/containers/byte-array/byte_array.h"
#include "src/main/cpp/bitmaps/formats/formats.h"
#include "src/main/cpp/bitmaps/image/image.h"
#include "src/main/cpp/bitmaps/packet/packet.h"
#include "src/main/cpp/bitmaps/reader/image/reader.h"
#include "src/main/cpp/bitmaps/reader/headers/file_header_reader.h"
#include "src/main/cpp/bitmaps/reader/headers/dib_header_reader.h"
#include "src/main/cpp/bitmaps/reader/pixel-array/reader.h"
#include "src/main/cpp/bitmaps/packet/headers/headers.h"
#include "src/main/cpp/files/stream/filestream.h"

Bitmaps::ImageReader::ImageReader()
{
  // pass.
}

std::shared_ptr<Bitmaps::Image> Bitmaps::ImageReader::read(
  const std::string& filePath)
{
  this->processIntoPacket(filePath);

  return std::make_shared<Bitmaps::Image>(this->packet);
}

void Bitmaps::ImageReader::processIntoPacket(const std::string& filePath)
{
  ByteArray bytes = Files::readFileToByteArray(filePath);
  this->processIntoPacket(bytes);
}

void Bitmaps::ImageReader::processIntoPacket(const ByteArray& bytes)
{
  this->processIntoFileHeader(bytes);
  this->processIntoDibHeader(bytes);  
  this->processIntoPixelArray(bytes);
}

void Bitmaps::ImageReader::processIntoFileHeader(const ByteArray& bytes)
{
  Bitmaps::FileHeaderReader reader {};
  ByteArray headerBytes = bytes.slice(0, 14);
  
  this->packet.fileHeader = reader.convertBytes(headerBytes);
}

void Bitmaps::ImageReader::processIntoDibHeader(const ByteArray& bytes)
{
  Bitmaps::DibHeaderReader reader {};
  ByteArray headerBytes = bytes.slice(14, 54);

  this->packet.dibHeader = reader.convertBytes(headerBytes);
}

void Bitmaps::ImageReader::processIntoPixelArray(const ByteArray& bytes)
{
  auto pixelArrayBytes = bytes.slice(54, bytes.size());
  auto reader = this->pixelArrayReader();
  
  auto bytesPointer = std::make_shared<ByteArray>(pixelArrayBytes);

  this->packet.pixelArray = reader.convertBytes(bytesPointer);
}

Bitmaps::PixelArrayReader Bitmaps::ImageReader::pixelArrayReader()
{
  auto format = this->pixelArrayFormat();
  
  return {format};
}

Bitmaps::Headers Bitmaps::ImageReader::headers()
{
  Bitmaps::Headers headers {};
  headers.fileHeader = this->packet.fileHeader;
  headers.dibHeader = this->packet.dibHeader;

  return headers;
}

Bitmaps::Format Bitmaps::ImageReader::pixelArrayFormat()
{  
  int bitsPerPixel = this->packet.dibHeader->bitsPerPixel();

  std::string formatName = "RGBA32";

  if (bitsPerPixel == 24)
    formatName = "RGB24";

  auto format = Bitmaps::format(formatName);

  format.setHeightInPixels(this->packet.dibHeader->heightInPixels());
  format.setWidthInPixels(this->packet.dibHeader->widthInPixels());

  return format;
}