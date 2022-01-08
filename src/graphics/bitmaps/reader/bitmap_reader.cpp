#include "src/graphics/bitmaps/packet/bitmap_packet.h"
#include "src/graphics/bitmaps/reader/bitmap_reader.h"
#include "src/graphics/bitmaps/reader/headers/file_header_reader.h"
#include "src/graphics/bitmaps/reader/headers/dib_header_reader.h"
#include "src/common/filesystem.h"
#include "src/common/byte_array.h"

BitmapReader::BitmapReader()
{
  // pass.
}

BitmapPacket BitmapReader::readBitmapPacket(std::string filePath)
{
  ByteArray bytes = Filesystem::convertFileToByteArray(filePath);

  ByteArray fileHeaderBytes = bytes.slice(0, 13);
  this->packet.fileHeader = BitmapReader::getBitmapFileHeader(fileHeaderBytes);

  // Issues with slicing values here.
  ByteArray dibHeaderBytes = bytes.slice(14, 53);
  this->packet.dibHeader = BitmapReader::getBitmapDibHeader(dibHeaderBytes);

  return this->packet;
}

BitmapHeaders::FileHeader BitmapReader::getBitmapFileHeader(ByteArray bytes)
{
  FileHeaderReader reader {};

  return reader.convertBytes(bytes);
}

BitmapHeaders::DibHeader BitmapReader::getBitmapDibHeader(ByteArray bytes)
{
  DibHeaderReader reader {};

  return reader.convertBytes(bytes);
}