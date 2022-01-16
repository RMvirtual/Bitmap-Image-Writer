#include <gtest/gtest.h>

#include "src/graphics/bitmaps/packet/pixel-array/pixels/rgb_pixel.h"
#include "src/graphics/bitmaps/packet/pixel-array/arrays/pixel_array.h"
#include "src/graphics/bitmaps/bitmap_image.h"
#include "test/src/graphics-tests/utilities/bitmap_image_comparators.h"

void BitmapImageComparison::compareBitmapFileHeaders(
  const BitmapHeaders::FileHeader& header1,
  const BitmapHeaders::FileHeader& header2)
{
  EXPECT_EQ(header1.signatureBytes(), header2.signatureBytes());
  EXPECT_EQ(header1.sizeOfBitmapFile(), header2.sizeOfBitmapFile());
  EXPECT_EQ(header1.reservedBytes(), header2.reservedBytes());
  EXPECT_EQ(header2.pixelDataOffset(), header2.pixelDataOffset());
}

void BitmapImageComparison::compareBitmapDibHeaders(
  const BitmapHeaders::DibHeader& header1,
  const BitmapHeaders::DibHeader& header2)
{
  EXPECT_EQ(header1.headerSizeInBytes(), header2.headerSizeInBytes());
  EXPECT_EQ(header1.widthInPixels(), header2.widthInPixels());
  EXPECT_EQ(header1.heightInPixels(), header2.heightInPixels());
  EXPECT_EQ(header1.numberOfColorPlanes(), header2.numberOfColorPlanes());
  EXPECT_EQ(header1.colorDepth(), header2.colorDepth());
  EXPECT_EQ(header1.compressionMethod(), header2.compressionMethod());
  EXPECT_EQ(header1.rawBitmapDataSize(), header2.rawBitmapDataSize());

  EXPECT_EQ(
    header1.horizontalPixelsPerMetre(),header2.horizontalPixelsPerMetre());

  EXPECT_EQ(
    header1.verticalPixelsPerMetre(), header2.verticalPixelsPerMetre());

  EXPECT_EQ(header1.colorTableEntries(), header2.colorTableEntries());
  EXPECT_EQ(header1.importantColors(), header2.importantColors());
}

void BitmapImageComparison::comparePixelArrays(
  const Pixels::PixelArray& pixelArray1,
  const Pixels::PixelArray& pixelArray2)
{  
  BitmapImageComparison::comparePixelArrayContents(pixelArray1, pixelArray2);
}

void BitmapImageComparison::comparePixelArrayContents(
  const Pixels::PixelArray& pixelArray1,
  const Pixels::PixelArray& pixelArray2)
{
  int numberOfPixels = pixelArray1.sizeInPixels();

  // Gets stuck here.
  for (int pixelNo = 0; pixelNo < 2; pixelNo++) {
    auto pixel1Colours = pixelArray1.at(pixelNo).getColours();
    auto pixel2Colours = pixelArray2.at(pixelNo).getColours();

    EXPECT_EQ(pixel1Colours.getBlue(), pixel2Colours.getBlue());
    EXPECT_EQ(pixel1Colours.getGreen(), pixel2Colours.getGreen());
    EXPECT_EQ(pixel1Colours.getRed(), pixel2Colours.getRed());
  }
}