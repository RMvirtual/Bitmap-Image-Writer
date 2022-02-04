#include <gtest/gtest.h>
#include "test/src/bitmaps/writer/fixture.h"

void BitmapWriterTest::compareToPacket(ByteArray& bytes)
{
  auto fileHeaderBytes = bytes.slice(0, 14);
  this->compareToFileHeader(fileHeaderBytes);

  auto dibHeaderBytes = bytes.slice(14, 54);
  this->compareToDibHeader(dibHeaderBytes);

  auto pixelArrayBytes = bytes.slice(54, bytes.size());
  this->compareToPixelArray(pixelArrayBytes);
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
      auto correctColour = correctPixel[colourNo];
      auto testColour = pixelBytes[colourNo];

      EXPECT_EQ(correctColour, testColour);
    }
  }
}

void BitmapWriterTest::compareToColours(ByteArray& bytes)
{
  int noOfBytes = bytes.size();
  int noOfColours = this->colours.size();

  ASSERT_EQ(noOfColours, noOfBytes);

  for (int i = 0; i < noOfColours; i++)
    EXPECT_EQ(this->colours[i], bytes[i]);
}