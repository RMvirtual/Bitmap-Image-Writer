#include <gtest/gtest.h>

#include "src/bitmaps/writer/writer.h"
#include "src/containers/byte-array/byte_conversion.h"
#include "test/src/bitmaps/writer/fixture.h"

BitmapWriterTest::BitmapWriterTest()
{
  this->loadFileHeader();
  this->loadDibHeader();
  this->loadPixelArray();
}

BitmapWriterTest::~BitmapWriterTest()
{

}

void BitmapWriterTest::loadFileHeader()
{
  this->packet.fileHeader.setSignatureBytes("BM");
  this->packet.fileHeader.setFileSizeInBytes(786486);
  this->packet.fileHeader.setReservedBytes(0);
  this->packet.fileHeader.setPixelArrayOffsetInBytes(54);
}

void BitmapWriterTest::loadDibHeader()
{
  this->packet.dibHeader.setWidthInPixels(2);
  this->packet.dibHeader.setHeightInPixels(2);
  this->packet.dibHeader.setNumberOfColourPlanes(1);
  this->packet.dibHeader.setBitsPerPixel(24);
}

void BitmapWriterTest::loadPixelArray()
{
  Bitmaps::Format format;
  format.setWidthInPixels(2);
  format.setHeightInPixels(2);
  format.setName("RGB");
  format.setBitsPerPixel(24);
  format.setColourNames({"blue", "green", "red"});

  this->packet.pixelArray = {format};
  this->loadColours();
}

void BitmapWriterTest::loadColours()
{
  Bitmaps::Colours colours;
  colours["blue"] = 255;
  colours["green"] = 255;
  colours["red"] = 100;

  this->packet.pixelArray.fill(colours);
  this->colours = colours;
}

void BitmapWriterTest::compareToFileHeader(ByteArray& bytes)
{
  auto& header = this->packet.fileHeader;

  this->compare(header.signatureBytes(), bytes.slice(0,2));
  this->compare(header.fileSizeInBytes(), bytes.slice(2,6));  
  this->compare(header.reservedBytes(), bytes.slice(6,10));
  this->compare(header.pixelArrayOffsetInBytes(), bytes.slice(10,14));
}

void BitmapWriterTest::compareToDibHeader(ByteArray& bytes)
{
  auto& header = this->packet.dibHeader;

  this->compare((uint32_t) header.headerSizeInBytes(), bytes.slice(0,4));
  this->compare((uint32_t) header.widthInPixels(), bytes.slice(4,8));
  this->compare((uint32_t) header.heightInPixels(), bytes.slice(8,12));
  this->compare(header.numberOfColorPlanes(), bytes.slice(12,14));
  this->compare(header.bitsPerPixel(), bytes.slice(14,16));
  this->compare(header.compressionMethod(), bytes.slice(16,20));
  this->compare(header.sizeOfPixelArray(), bytes.slice(20,24));
  this->compare((uint32_t) header.horizontalResolution(), bytes.slice(24,28));
  this->compare((uint32_t) header.verticalResolution(), bytes.slice(28,32));
  this->compare(header.colorTableEntries(), bytes.slice(32,36));
  this->compare(header.importantColors(), bytes.slice(36,40));
}

void BitmapWriterTest::compareToPixelArray(ByteArray& bytes)
{
  auto& pixelArray = this->packet.pixelArray;

  int bytesPerPixel = pixelArray.format().pixelSizeInBytes();
  int noOfBytes = bytes.size();
  
  for (int byteNo = 0; byteNo < noOfBytes; byteNo += bytesPerPixel) {
    auto correctPixel = pixelArray.at(byteNo / bytesPerPixel);
    int noOfColours = correctPixel.size();
    auto colourNames = correctPixel.names();
    
    auto pixelBytes = bytes.slice(byteNo, byteNo + bytesPerPixel);

    for (int colourNo = 0; colourNo < noOfColours; colourNo++) {
      EXPECT_EQ(correctPixel[colourNames[colourNo]], pixelBytes[colourNo]);
    }
  }
}

void BitmapWriterTest::compare(std::string chars, ByteArray bytes)
{
  int noOfCharacters = chars.size();
  int noOfBytes = bytes.size();

  ASSERT_EQ(noOfCharacters, noOfBytes);

  for (int i = 0; i < noOfCharacters; i++)
    EXPECT_EQ(chars[i], bytes[i]);
}

void BitmapWriterTest::compare(uint16_t integer, ByteArray bytes)
{
  uint16_t bytesValue = ByteConversion::to16BitInt(bytes);
  EXPECT_EQ(integer, bytesValue);
}

void BitmapWriterTest::compare(uint32_t integer, ByteArray bytes)
{
  uint32_t bytesValue = ByteConversion::to32BitInt(bytes);
  EXPECT_EQ(integer, bytesValue);
}

ByteArray BitmapWriterTest::writeBlueFile()
{ 
  return this->writer.convertToBytes(this->packet);
}