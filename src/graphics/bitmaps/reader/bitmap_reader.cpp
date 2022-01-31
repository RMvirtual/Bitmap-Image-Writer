#include "src/containers/byte-array/byte_array.h"
#include "src/graphics/bitmaps/packet/packet.h"
#include "src/graphics/bitmaps/reader/bitmap_reader.h"
#include "src/graphics/bitmaps/reader/headers/file_header_reader.h"
#include "src/graphics/bitmaps/reader/headers/dib_header_reader.h"
#include "src/graphics/bitmaps/reader/pixel-array/reader.h"
#include "src/graphics/bitmaps/packet/headers/headers.h"
#include "src/utilities/filesystem.h"

BitmapReader::ImageReader::ImageReader()
{
  // pass.
}

BitmapPacket BitmapReader::ImageReader::readBitmapPacket(
  const std::string& filePath)
{
  this->processIntoPacket(filePath);

  return this->packet;
}

void BitmapReader::ImageReader::processIntoPacket(const std::string& filePath)
{
  ByteArray bytes = Utilities::convertFileToByteArray(filePath);
  this->processIntoPacket(bytes);
}

void BitmapReader::ImageReader::processIntoPacket(const ByteArray& bytes)
{
  this->processIntoFileHeader(bytes);
  this->processIntoDibHeader(bytes);
  this->processIntoPixelArray(bytes);
}

void BitmapReader::ImageReader::processIntoFileHeader(const ByteArray& bytes)
{
  ByteArray headerBytes = bytes.slice(0, 14);
  FileHeaderReader reader {};
  this->packet.fileHeader = reader.convertBytes(headerBytes);
}

void BitmapReader::ImageReader::processIntoDibHeader(const ByteArray& bytes)
{
  ByteArray headerBytes = bytes.slice(14, 54);
  DibHeaderReader reader {};
  this->packet.dibHeader = reader.convertBytes(headerBytes);
}

void BitmapReader::ImageReader::processIntoPixelArray(const ByteArray& bytes)
{
  auto pixelArrayBytes = bytes.slice(54, bytes.size());
  auto reader = this->pixelArrayReader();
  
  this->packet.pixelArray = reader.toPixelArray(pixelArrayBytes); 
}

BitmapReader::PixelArrayReader BitmapReader::ImageReader::pixelArrayReader()
{
  return {this->pixelArrayConfig()};
}

BitmapHeaders::Headers BitmapReader::ImageReader::packetToHeaders()
{
  BitmapHeaders::Headers headers {};
  headers.fileHeader = this->packet.fileHeader;
  headers.dibHeader = this->packet.dibHeader;

  return headers;
}

BitmapReader::PixelArrayConfig
BitmapReader::ImageReader::pixelArrayConfig()
{
  auto headers = this->packetToHeaders();
  
  return BitmapReader::PixelArrayConfig::fromHeaders(headers);
}