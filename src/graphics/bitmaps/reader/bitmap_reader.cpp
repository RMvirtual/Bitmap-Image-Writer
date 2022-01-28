#include "src/common/byte-array/byte_array.h"
#include "src/common/filesystem/filesystem.h"
#include "src/graphics/bitmaps/packet/packet.h"
#include "src/graphics/bitmaps/reader/bitmap_reader.h"
#include "src/graphics/bitmaps/reader/headers/file_header_reader.h"
#include "src/graphics/bitmaps/reader/headers/dib_header_reader.h"
#include "src/graphics/bitmaps/reader/pixel-array/pixel_array_reader.h"
#include "src/graphics/bitmaps/packet/headers/headers.h"

BitmapReader::ImageReader::ImageReader()
{
  // pass.
}

RGBABitmapPacket BitmapImageReader::ImageReader::readRGBABitmapPacket(
  const std::string& filePath)
{
  RGBABitmapPacket packet {};
  packet.fileHeader =   
}

RGBBitmapPacket BitmapReader::ImageReader::readBitmapPacket(
  const std::string& filePath)
{
  this->processIntoPacket(filePath);

  return this->packet;
}

void BitmapReader::ImageReader::processIntoPacket(const std::string& filePath)
{
  ByteArray bytes = Filesystem::convertFileToByteArray(filePath);
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
  
  this->packet.pixelArray = reader.toRGBPixelArray(pixelArrayBytes); 
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

BitmapReader::PixelArrayReaderConfig
BitmapReader::ImageReader::pixelArrayConfig()
{
  auto headers = this->packetToHeaders();
  
  return BitmapReader::PixelArrayReaderConfig::fromHeaders(headers);
}