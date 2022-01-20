#include "src/common/byte-array/byte_array.h"
#include "src/common/filesystem/filesystem.h"
#include "src/graphics/bitmaps/packet/rgb_bitmap_packet.h"
#include "src/graphics/bitmaps/reader/bitmap_reader.h"
#include "src/graphics/bitmaps/reader/headers/file_header_reader.h"
#include "src/graphics/bitmaps/reader/headers/dib_header_reader.h"
#include "src/graphics/bitmaps/reader/pixel-array/pixel_array_reader.h"

BitmapReader::ImageReader::ImageReader()
{
  // pass.
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
  auto config = BitmapReader::PixelArrayReaderConfig::fromHeaders(
    this->packet.fileHeader, this->packet.dibHeader);

  PixelArrayReader reader {config};
 
  auto pixelArrayBytes = bytes.slice(54, bytes.size());
  this->packet.pixelArray = reader.convertBytesToRGBPixels(pixelArrayBytes); 
}