#include "src/common/filesystem/filesystem.h"
#include "src/common/byte-array/byte_array.h"
#include "src/graphics/bitmaps/packet/bitmap_packet.h"
#include "src/graphics/bitmaps/reader/bitmap_reader.h"
#include "src/graphics/bitmaps/reader/headers/file_header_reader.h"
#include "src/graphics/bitmaps/reader/headers/dib_header_reader.h"
#include "src/graphics/bitmaps/reader/pixel-array/pixel_array_reader.h"

BitmapReader::BitmapReader()
{
  // pass.
}

BitmapPacket BitmapReader::readBitmapPacket(std::string filePath)
{
  this->processIntoPacket(filePath);

  return this->packet;
}

void BitmapReader::processIntoPacket(std::string filePath)
{
  ByteArray bytes = Filesystem::convertFileToByteArray(filePath);
  this->processIntoPacket(bytes);
}

void BitmapReader::processIntoPacket(ByteArray& bytes)
{
  this->processIntoFileHeader(bytes);
  this->processIntoDibHeader(bytes);
  this->processIntoPixelArray(bytes);
}

void BitmapReader::processIntoFileHeader(ByteArray& bytes)
{
  ByteArray headerBytes = bytes.slice(0, 13);
  FileHeaderReader reader {};

  this->packet.fileHeader = reader.convertBytes(headerBytes);
}

void BitmapReader::processIntoDibHeader(ByteArray& bytes)
{
  ByteArray headerBytes = bytes.slice(14, 53);
  DibHeaderReader reader {};

  this->packet.dibHeader = reader.convertBytes(headerBytes);
}

void BitmapReader::processIntoPixelArray(ByteArray& bytes)
{
  int lastByte = this->packet.fileHeader.getSizeOfBitmapFile();
  ByteArray pixelArrayBytes = bytes.slice(54, lastByte);
  PixelArrayReader reader {};

  this->packet.pixelArray = reader.convertBytes(pixelArrayBytes);
}