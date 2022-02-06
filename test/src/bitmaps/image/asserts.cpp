#include "src/bitmaps/formats/colours/colours.h"
#include "src/bitmaps/packet/packet.h"
#include "src/bitmaps/packet/headers/headers.h"
#include "src/bitmaps/reader/bitmap_reader.h"
#include "test/src/bitmaps/image/fixture.h"

void BitmapImageTest::compareWrittenFile()
{
  Bitmaps::ImageReader reader {};
  auto packet = reader.read(this->filePath);

  this->compare(packet.fileHeader);
  this->compare(packet.dibHeader);
  this->compare(packet.pixelArray);
}

void BitmapImageTest::compare(const Bitmaps::FileHeader& header)
{
  auto correctHeader = this->image.fileHeader();

  EXPECT_EQ(correctHeader.signatureBytes(), header.signatureBytes());
  EXPECT_EQ(correctHeader.fileSizeInBytes(), header.fileSizeInBytes());
  EXPECT_EQ(correctHeader.reservedBytes(), header.reservedBytes());
  
  EXPECT_EQ(
    correctHeader.pixelArrayOffsetInBytes(), header.pixelArrayOffsetInBytes());
}

void BitmapImageTest::compare(const Bitmaps::DibHeader& header)
{
  auto correctHeader = this->image.dibHeader();

  EXPECT_EQ(correctHeader.headerSizeInBytes(), header.headerSizeInBytes());
  EXPECT_EQ(correctHeader.widthInPixels(), header.widthInPixels());
  EXPECT_EQ(correctHeader.heightInPixels(), header.heightInPixels());
  EXPECT_EQ(correctHeader.numberOfColorPlanes(), header.numberOfColorPlanes());
  EXPECT_EQ(correctHeader.bitsPerPixel(), header.bitsPerPixel());
  EXPECT_EQ(correctHeader.compressionMethod(), header.compressionMethod());
  EXPECT_EQ(correctHeader.sizeOfPixelArray(), header.sizeOfPixelArray());

  EXPECT_EQ(
    correctHeader.horizontalResolution(), header.horizontalResolution());

  EXPECT_EQ(correctHeader.verticalResolution(), header.verticalResolution());
  EXPECT_EQ(correctHeader.colorTableEntries(), header.colorTableEntries());
  EXPECT_EQ(correctHeader.importantColors(), header.importantColors());
}

void BitmapImageTest::compare(const Bitmaps::PixelArray& pixelArray)
{
  auto correctPixelArray = this->image.pixelArray();

  int correctNoOfPixels = correctPixelArray.sizeInPixels();
  int noOfPixels = pixelArray.sizeInPixels();

  ASSERT_EQ(correctNoOfPixels, noOfPixels);

  for (int pixelNo = 0; pixelNo < noOfPixels; pixelNo++) {
    auto correctColours = correctPixelArray.at(pixelNo);
    auto colours = pixelArray.at(pixelNo);

    this->compare(correctColours, colours);
  }
}

void BitmapImageTest::compare(
  const Bitmaps::Colours& correctColours, const Bitmaps::Colours& colours)
{
  int correctNoOfColours = correctColours.size();
  int noOfColours = colours.size();

  ASSERT_EQ(correctNoOfColours, noOfColours);

  for (int colourNo = 0; colourNo < noOfColours; colourNo++) {
    auto correctColour = correctColours[colourNo];
    auto colour = colours[colourNo];

    EXPECT_EQ(correctColour, colour);
  }
}