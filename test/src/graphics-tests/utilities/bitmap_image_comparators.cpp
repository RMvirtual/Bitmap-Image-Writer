#include <gtest/gtest.h>

#include "src/bitmaps/packet/pixel-array/array.h"
#include "src/bitmaps/packet/pixel-array/colours.h"
#include "src/bitmaps/formats/format.h"
#include "test/src/graphics-tests/utilities/bitmap_image_comparators.h"

void BitmapImageComparison::compare(
  const Bitmaps::FileHeader& header1, 
  const Bitmaps::FileHeader& header2)
{  
  EXPECT_EQ(header1.signatureBytes(), header2.signatureBytes());
  EXPECT_EQ(header1.fileSizeInBytes(), header2.fileSizeInBytes());
  EXPECT_EQ(header1.reservedBytes(), header2.reservedBytes());
  EXPECT_EQ(
    header2.pixelArrayOffsetInBytes(), header2.pixelArrayOffsetInBytes());
}

void BitmapImageComparison::compare(
  const Bitmaps::DibHeader& header1,
  const Bitmaps::DibHeader& header2)
{
  EXPECT_EQ(header1.headerSizeInBytes(), header2.headerSizeInBytes());
  EXPECT_EQ(header1.widthInPixels(), header2.widthInPixels());
  EXPECT_EQ(header1.heightInPixels(), header2.heightInPixels());
  EXPECT_EQ(header1.numberOfColorPlanes(), header2.numberOfColorPlanes());
  EXPECT_EQ(header1.bitsPerPixel(), header2.bitsPerPixel());
  EXPECT_EQ(header1.compressionMethod(), header2.compressionMethod());
  EXPECT_EQ(header1.sizeOfPixelArray(), header2.sizeOfPixelArray());
  EXPECT_EQ(header1.horizontalResolution(),header2.horizontalResolution());
  EXPECT_EQ(header1.verticalResolution(), header2.verticalResolution());
  EXPECT_EQ(header1.colorTableEntries(), header2.colorTableEntries());
  EXPECT_EQ(header1.importantColors(), header2.importantColors());
}

void BitmapImageComparison::compare(
  Bitmaps::PixelArray& pixelArray1, Bitmaps::PixelArray& pixelArray2)
{
  ASSERT_EQ(pixelArray1.sizeInPixels(), pixelArray2.sizeInPixels());

  int numberOfPixels = 5; // hardcoded for now as big test image.
  // Need smaller one adding later.

  for (int pixelNo = 0; pixelNo < 5; pixelNo++)
    BitmapImageComparison::compare(
      pixelArray1.at(pixelNo), pixelArray2.at(pixelNo));
}

void BitmapImageComparison::compare(
  Bitmaps::Colours& correctColours, Bitmaps::Colours& colours)
{
  ASSERT_EQ(correctColours.names().size(), colours.names().size());

  for (auto name : correctColours.names())
    EXPECT_EQ(correctColours[name], colours[name]);
}

void BitmapImageComparison::isGreen(Bitmaps::Colours& colours)
{
  EXPECT_EQ(colours["green"], 255);
  EXPECT_EQ(colours["blue"], 0);
  EXPECT_EQ(colours["red"], 0);
}

void BitmapImageComparison::isRed(Bitmaps::Colours& colours)
{
  EXPECT_EQ(colours["green"], 0);
  EXPECT_EQ(colours["blue"], 0);
  EXPECT_EQ(colours["red"], 255);
}