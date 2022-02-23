#include <gtest/gtest.h>
#include "src/test/cpp/bitmaps/writer/fixture.h"
#include "src/main/cpp/bitmaps/reader/image/reader.h"

void BitmapWriterTest::compareWrittenFile()
{
  Bitmaps::ImageReader reader {};
  auto writtenImage = reader.read(this->filePath);

  this->compare(writtenImage.fileHeader());
  this->compare(writtenImage.dibHeader());
  this->compare(writtenImage.pixelArray());
}

void BitmapWriterTest::compare(const Bitmaps::FileHeader& header)
{
  auto correctHeader = this->image.fileHeader();

  EXPECT_EQ(correctHeader.signatureBytes(), header.signatureBytes());
  EXPECT_EQ(correctHeader.fileSizeInBytes(), header.fileSizeInBytes());
  EXPECT_EQ(correctHeader.reservedBytes(), header.reservedBytes());
  
  EXPECT_EQ(
    correctHeader.pixelArrayOffsetInBytes(), header.pixelArrayOffsetInBytes());
}

void BitmapWriterTest::compare(const Bitmaps::DibHeader& header)
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

void BitmapWriterTest::compare(const Bitmaps::PixelArray& pixelArray)
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

void BitmapWriterTest::compare(
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