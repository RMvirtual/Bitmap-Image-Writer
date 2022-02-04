#include "src/bitmaps/formats/colours.h"
#include "src/bitmaps/formats/format.h"
#include "src/bitmaps/packet/headers/dib-header/header.h"
#include "src/bitmaps/packet/headers/file-header/header.h"
#include "src/bitmaps/packet/packet.h"
#include "src/bitmaps/packet/pixel-array/array.h"
#include "src/bitmaps/writer/writer.h"
#include "src/containers/byte-array/byte_array.h"
#include "src/utilities/filesystem.h"

Bitmaps::ByteWriter::ByteWriter()
{
  // pass.
}

void Bitmaps::ByteWriter::writeToFile(
  std::string filePath, const Bitmaps::Packet& packet)
{
  auto bytes = this->write(packet);
  Utilities::writeToFile(filePath, bytes);
}

ByteArray Bitmaps::ByteWriter::write(const Bitmaps::Packet& packet)
{
  ByteArray allBytes {};

  allBytes.add(this->write(packet.fileHeader));
  allBytes.add(this->write(packet.dibHeader));
  allBytes.add(this->write(packet.pixelArray));

  return allBytes;
}

ByteArray Bitmaps::ByteWriter::write(const Bitmaps::FileHeader& header)
{
  ByteArray byteArray {};
  byteArray.add(header.signatureBytes());
  byteArray.add(header.fileSizeInBytes()); 
  byteArray.add(header.reservedBytes()); 
  byteArray.add(header.pixelArrayOffsetInBytes());

  return byteArray;
}

ByteArray Bitmaps::ByteWriter::write(const Bitmaps::DibHeader& header)
{
  ByteArray byteArray {};

  byteArray.add(header.headerSizeInBytes());
  byteArray.add(header.widthInPixels());
  byteArray.add(header.heightInPixels());
  byteArray.add(header.numberOfColorPlanes());
  byteArray.add(header.bitsPerPixel());
  byteArray.add(header.compressionMethod());
  byteArray.add(header.sizeOfPixelArray());
  byteArray.add(header.horizontalResolution());
  byteArray.add(header.verticalResolution());
  byteArray.add(header.colorTableEntries());
  byteArray.add(header.importantColors());

  return byteArray;
}

ByteArray Bitmaps::ByteWriter::write(const Bitmaps::PixelArray& pixelArray)
{
  ByteArray byteArray {};
  int numberOfPixels = pixelArray.sizeInPixels();
  
  for (int pixelNo = 0; pixelNo < numberOfPixels; pixelNo++) {
    auto colours = pixelArray.at(pixelNo);
    auto colourBytes = this->write(colours);

    byteArray.add(colourBytes);
  }

  return byteArray;
}

ByteArray Bitmaps::ByteWriter::write(const Bitmaps::Colours& colours)
{
  ByteArray byteArray {};

  for (auto colourAndValue : colours)
    byteArray.add(colourAndValue.second);

  return byteArray;
}