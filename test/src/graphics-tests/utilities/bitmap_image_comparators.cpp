#include <gtest/gtest.h>

#include "src/graphics/bitmaps/packet/pixel-array/array.h"
#include "src/graphics/bitmaps/packet/pixel-array/colours.h"
#include "src/graphics/bitmaps/packet/pixel-array/format.h"
#include "test/src/graphics-tests/utilities/bitmap_image_comparators.h"

void BitmapImageComparison::compare(
  const BitmapHeaders::FileHeader& header1, 
  const BitmapHeaders::FileHeader& header2)
{
  EXPECT_EQ(header1.signatureBytes(), header2.signatureBytes());
  EXPECT_EQ(header1.fileSizeInBytes(), header2.fileSizeInBytes());
  EXPECT_EQ(header1.reservedBytes(), header2.reservedBytes());
  EXPECT_EQ(
    header2.pixelArrayOffsetInBytes(), header2.pixelArrayOffsetInBytes());
}

void BitmapImageComparison::compare(
  const BitmapHeaders::DibHeader& header1,
  const BitmapHeaders::DibHeader& header2)
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
  const Pixels::Array& pixelArray1, const Pixels::Array& pixelArray2)
{
  ASSERT_EQ(pixelArray1.sizeInPixels(), pixelArray2.sizeInPixels());

  int numberOfPixels = pixelArray1.sizeInPixels();

  for (int pixelNo = 0; pixelNo < numberOfPixels; pixelNo++)
    BitmapImageComparison::compare(
      pixelArray1.at(pixelNo), 
      pixelArray2.at(pixelNo)
    );
}

void BitmapImageComparison::compare(
  Pixels::Colours& colours1, Pixels::Colours& colours2)
{

  EXPECT_EQ(colours1["blue"], colours2["blue"]);
  EXPECT_EQ(colours1["red"], colours2["red"]);
  EXPECT_EQ(colours1["green"], colours2["green"]);
}

void BitmapImageComparison::isGreen(Pixels::Colours& colours)
{
  EXPECT_EQ(colours["green"], 255);
  EXPECT_EQ(colours["blue"], 0);
  EXPECT_EQ(colours["red"], 0);
}

void BitmapImageComparison::isRed(Pixels::Colours& colours)
{
  EXPECT_EQ(colours["green"], 0);
  EXPECT_EQ(colours["blue"], 0);
  EXPECT_EQ(colours["red"], 255);
}