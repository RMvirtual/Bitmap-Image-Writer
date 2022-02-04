#include "test/src/bitmaps/reader/fixture.h"
#include "src/bitmaps/reader/headers/file_header_reader.h"
#include "src/bitmaps/reader/headers/dib_header_reader.h"
#include "src/bitmaps/reader/pixel-array/reader.h"

void BitmapReaderTest::compare(const Bitmaps::FileHeader& header)
{
  auto& correctHeader = this->packet.fileHeader;

  EXPECT_EQ(correctHeader.signatureBytes(), header.signatureBytes());
  EXPECT_EQ(correctHeader.fileSizeInBytes(), header.fileSizeInBytes());
  EXPECT_EQ(correctHeader.reservedBytes(), header.reservedBytes());

  EXPECT_EQ(
    correctHeader.pixelArrayOffsetInBytes(), header.pixelArrayOffsetInBytes());
}

void BitmapReaderTest::compare(const Bitmaps::DibHeader& header)
{
  auto& correctHeader = this->packet.dibHeader;

  EXPECT_EQ(correctHeader.headerSizeInBytes(), header.headerSizeInBytes());
  EXPECT_EQ(correctHeader.widthInPixels(), header.widthInPixels());
  EXPECT_EQ(correctHeader.heightInPixels(), header.heightInPixels());
  EXPECT_EQ(correctHeader.numberOfColorPlanes(), header.numberOfColorPlanes());
  EXPECT_EQ(correctHeader.bitsPerPixel(), header.bitsPerPixel());
  EXPECT_EQ(correctHeader.compressionMethod(), header.compressionMethod());
  EXPECT_EQ(correctHeader.sizeOfPixelArray(), header.sizeOfPixelArray());
  EXPECT_EQ(correctHeader.horizontalResolution(), header.horizontalResolution());
  EXPECT_EQ(correctHeader.verticalResolution(), header.verticalResolution());
  EXPECT_EQ(correctHeader.colorTableEntries(), header.colorTableEntries());
  EXPECT_EQ(correctHeader.importantColors(), header.importantColors());
}

void BitmapReaderTest::compare(Bitmaps::PixelArray& array)
{
  auto& correctArray = this->packet.pixelArray;
  int correctNoOfPixels = correctArray.sizeInPixels();
  int noOfPixels = array.sizeInPixels();

  ASSERT_EQ(correctNoOfPixels, noOfPixels);

  for (int pixelNo = 0; pixelNo < noOfPixels; pixelNo++) {
    auto correctColours = correctArray.at(pixelNo);
    auto colours = correctArray.at(pixelNo);

    int noOfColours = correctColours.size();

    for (int colourNo = 0; colourNo < noOfColours; colourNo++)
      EXPECT_EQ(correctColours[colourNo], colours[colourNo]);
  }  
}