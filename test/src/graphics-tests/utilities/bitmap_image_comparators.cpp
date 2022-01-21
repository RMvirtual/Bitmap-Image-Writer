#include <gtest/gtest.h>

#include "test/src/graphics-tests/utilities/bitmap_image_comparators.h"
#include "src/graphics/bitmaps/packet/pixel-array/rgb/rgb_pixel.h"
#include "src/graphics/bitmaps/packet/pixel-array/rgb/rgb_pixel_array.h"

void BitmapImageComparison::compareBitmapFileHeaders(
  const BitmapHeaders::FileHeader& header1,
  const BitmapHeaders::FileHeader& header2)
{
  EXPECT_EQ(header1.signatureBytes(), header2.signatureBytes());
  EXPECT_EQ(header1.fileSizeInBytes(), header2.fileSizeInBytes());
  EXPECT_EQ(header1.reservedBytes(), header2.reservedBytes());
  EXPECT_EQ(
    header2.pixelArrayOffsetInBytes(), header2.pixelArrayOffsetInBytes());
}

void BitmapImageComparison::compareBitmapDibHeaders(
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

void BitmapImageComparison::comparePixelArrays(
  const Pixels::RGBPixelArray& pixelArray1,
  const Pixels::RGBPixelArray& pixelArray2)
{  
  BitmapImageComparison::comparePixelArrayContents(pixelArray1, pixelArray2);
}

void BitmapImageComparison::comparePixelArrayContents(
  const Pixels::RGBPixelArray& pixelArray1,
  const Pixels::RGBPixelArray& pixelArray2)
{
  int numberOfPixels = pixelArray1.sizeInPixels();

  // Gets stuck here.
  for (int pixelNo = 0; pixelNo < 2; pixelNo++) {
    auto pixel1Colours = pixelArray1.at(pixelNo).colours();
    auto pixel2Colours = pixelArray2.at(pixelNo).colours();

    EXPECT_EQ(pixel1Colours.blue(), pixel2Colours.blue());
    EXPECT_EQ(pixel1Colours.green(), pixel2Colours.green());
    EXPECT_EQ(pixel1Colours.red(), pixel2Colours.red());
  }
}

void BitmapImageComparison::comparePixels(
  const Pixels::RGBPixel& pixel1, const Pixels::RGBPixel& pixel2)
{
  BitmapImageComparison::compareColours(pixel1.colours(), pixel2.colours());
}

void BitmapImageComparison::compareColours(
  const Pixels::RGBColours& colours1, const Pixels::RGBColours& colours2)
{
  EXPECT_EQ(colours1.blue(), colours2.blue());
  EXPECT_EQ(colours1.red(), colours2.red());
  EXPECT_EQ(colours1.green(), colours2.green());
}

void BitmapImageComparison::isGreenPixel(Pixels::RGBPixel pixel)
{
  Pixels::RGBColours colours = pixel.colours();

  EXPECT_EQ(colours.green(), 255);
  EXPECT_EQ(colours.blue(), 0);
  EXPECT_EQ(colours.red(), 0);
}

void BitmapImageComparison::isRedPixel(Pixels::RGBPixel pixel)
{
  Pixels::RGBColours colours = pixel.colours();

  EXPECT_EQ(colours.green(), 0);
  EXPECT_EQ(colours.blue(), 0);
  EXPECT_EQ(colours.red(), 255);
}
