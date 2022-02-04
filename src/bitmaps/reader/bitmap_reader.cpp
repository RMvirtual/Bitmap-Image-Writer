#include "src/containers/byte-array/byte_array.h"
#include "src/bitmaps/formats/formats.h"
#include "src/bitmaps/packet/packet.h"
#include "src/bitmaps/reader/bitmap_reader.h"
#include "src/bitmaps/reader/headers/file_header_reader.h"
#include "src/bitmaps/reader/headers/dib_header_reader.h"
#include "src/bitmaps/reader/pixel-array/reader.h"
#include "src/bitmaps/packet/headers/headers.h"
#include "src/utilities/filesystem.h"

Bitmaps::ImageReader::ImageReader()
{
  // pass.
}

Bitmaps::Packet Bitmaps::ImageReader::read(const std::string& filePath)
{
  this->processIntoPacket(filePath);

  return this->packet;
}

void Bitmaps::ImageReader::processIntoPacket(const std::string& filePath)
{
  ByteArray bytes = Utilities::readFileToByteArray(filePath);
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
  ByteArray headerBytes = bytes.slice(0, 14);
  FileHeaderReader reader {};
  this->packet.fileHeader = reader.convertBytes(headerBytes);
}

void Bitmaps::ImageReader::processIntoDibHeader(const ByteArray& bytes)
{
  ByteArray headerBytes = bytes.slice(14, 54);
  DibHeaderReader reader {};
  this->packet.dibHeader = reader.convertBytes(headerBytes);
}

void Bitmaps::ImageReader::processIntoPixelArray(const ByteArray& bytes)
{
  auto pixelArrayBytes = bytes.slice(54, bytes.size());
  auto reader = this->pixelArrayReader();
  
  this->packet.pixelArray = reader.toPixelArray(pixelArrayBytes); 
}

Bitmaps::PixelArrayReader Bitmaps::ImageReader::pixelArrayReader()
{
  return {this->pixelArrayFormat()};
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
  int bitsPerPixel = this->packet.dibHeader.bitsPerPixel();
  
  return Bitmaps::format(bitsPerPixel);
}