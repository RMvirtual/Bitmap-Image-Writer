#include "test/src/bitmaps/fixtures/test.h"

BitmapTest::BitmapTest()
{

}

BitmapTest::~BitmapTest()
{

}

void BitmapTest::compare(const Bitmaps::FileHeader& header)
{
  EXPECT_EQ(this->fileHeader.signatureBytes(), header.signatureBytes());
  EXPECT_EQ(this->fileHeader.fileSizeInBytes(), header.fileSizeInBytes());
  EXPECT_EQ(this->fileHeader.reservedBytes(), header.reservedBytes());
  
  EXPECT_EQ(
    this->fileHeader.pixelArrayOffsetInBytes(),
    header.pixelArrayOffsetInBytes()
  );
}

void BitmapTest::compare(const Bitmaps::DibHeader& header)
{
  EXPECT_EQ(this->dibHeader.headerSizeInBytes(), header.headerSizeInBytes());
  EXPECT_EQ(this->dibHeader.widthInPixels(), header.widthInPixels());
  EXPECT_EQ(this->dibHeader.heightInPixels(), header.heightInPixels());
  EXPECT_EQ(
    this->dibHeader.numberOfColorPlanes(), header.numberOfColorPlanes());
  
  EXPECT_EQ(this->dibHeader.bitsPerPixel(), header.bitsPerPixel());
  EXPECT_EQ(this->dibHeader.compressionMethod(), header.compressionMethod());
  EXPECT_EQ(this->dibHeader.sizeOfPixelArray(), header.sizeOfPixelArray());
  
  EXPECT_EQ(
    this->dibHeader.horizontalResolution(), header.horizontalResolution());
  
  EXPECT_EQ(this->dibHeader.verticalResolution(), header.verticalResolution());
  EXPECT_EQ(this->dibHeader.colorTableEntries(), header.colorTableEntries());
  EXPECT_EQ(this->dibHeader.importantColors(), header.importantColors());
}

void BitmapTest::compare(Bitmaps::PixelArray& array)
{
  ASSERT_EQ(this->pixelArray.sizeInPixels(), array.sizeInPixels());

  int numberOfPixels = 4; // hardcoded for now as big test image.
  // Need smaller one adding later.

  for (int pixelNo = 0; pixelNo < 5; pixelNo++)
    this->compare(this->pixelArray.at(pixelNo), array.at(pixelNo));
}

void BitmapTest::compare(
  Bitmaps::Colours& correctColours, Bitmaps::Colours& colours)
{
  ASSERT_EQ(correctColours.names().size(), colours.names().size());

  for (auto name : correctColours.names())
    EXPECT_EQ(correctColours[name], colours[name]);
}

void BitmapTest::compare(Bitmaps::Format& format)
{
  EXPECT_EQ(this->format.name(), format.name());
  EXPECT_EQ(this->format.bitsPerPixel(), format.bitsPerPixel());
  EXPECT_EQ(this->format.colourNames().size(), format.colourNames().size());

  for (int col = 0; col < this->format.colourNames().size(); col++)
    EXPECT_EQ(this->format.colourNames()[col], format.colourNames()[col]);
}

void BitmapTest::isGreen(Bitmaps::Colours& colour)
{
  EXPECT_EQ(colour["green"], 255);
  EXPECT_EQ(colour["blue"], 0);
  EXPECT_EQ(colour["red"], 0);
}

void BitmapTest::isRed(Bitmaps::Colours& colour)
{
  EXPECT_EQ(colour["green"], 0);
  EXPECT_EQ(colour["blue"], 0);
  EXPECT_EQ(colour["red"], 255);
}