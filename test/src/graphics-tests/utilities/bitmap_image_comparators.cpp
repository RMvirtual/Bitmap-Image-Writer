#include <gtest/gtest.h>

#include "src/graphics/bitmaps/packet/pixel-array/pixels/pixel.h"
#include "src/graphics/bitmaps/packet/pixel-array/pixel_array.h"
#include "src/graphics/bitmaps/bitmap_image.h"
#include "test/src/graphics-tests/utilities/bitmap_image_comparators.h"

void BitmapImageComparison::compareBitmapFileHeaders(
  BitmapHeaders::FileHeader header1, BitmapHeaders::FileHeader header2)
{
  EXPECT_EQ(header1.getSignatureBytes()[0], header2.getSignatureBytes()[0]);
  EXPECT_EQ(header1.getSignatureBytes()[1], header2.getSignatureBytes()[1]);
  EXPECT_EQ(header1.getSizeOfBitmapFile(), header2.getSizeOfBitmapFile());
  EXPECT_EQ(header1.getReservedBytes(), header2.getReservedBytes());
  EXPECT_EQ(header2.getPixelDataOffset(), header2.getPixelDataOffset());
}

void BitmapImageComparison::compareBitmapDibHeaders(
  BitmapHeaders::DibHeader header1, BitmapHeaders::DibHeader header2)
{
  EXPECT_EQ(
    header1.getHeaderSizeInBytes(), header2.getHeaderSizeInBytes());

  EXPECT_EQ(header1.getWidthInPixels(), header2.getWidthInPixels());
  EXPECT_EQ(header1.getHeightInPixels(), header2.getHeightInPixels());
  EXPECT_EQ(
    header1.getNumberOfColorPlanes(), header2.getNumberOfColorPlanes());

  EXPECT_EQ(header1.getColorDepth(), header2.getColorDepth());
  EXPECT_EQ(header1.getCompressionMethod(), header2.getCompressionMethod());
  EXPECT_EQ(header1.getRawBitmapDataSize(), header2.getRawBitmapDataSize());
  EXPECT_EQ(
    header1.getHorizontalPixelsPerMetre(),
    header2.getHorizontalPixelsPerMetre()
  );

  EXPECT_EQ(
    header1.getVerticalPixelsPerMetre(), header2.getVerticalPixelsPerMetre());

  EXPECT_EQ(header1.getColorTableEntries(), header2.getColorTableEntries());
  EXPECT_EQ(header1.getImportantColors(), header2.getImportantColors());
}

void BitmapImageComparison::comparePixelArrayAttributes(
  Pixels::PixelArray pixelArray1, Pixels::PixelArray pixelArray2)
{
  EXPECT_EQ(pixelArray1.getHeightInPixels(), pixelArray2.getHeightInPixels());
  EXPECT_EQ(pixelArray1.getWidthInPixels(), pixelArray2.getWidthInPixels());
  EXPECT_EQ(pixelArray1.sizeInPixels(), pixelArray2.sizeInPixels());
  EXPECT_EQ(pixelArray1.sizeInBytes(), pixelArray2.sizeInBytes());
}

void BitmapImageComparison::comparePixelArrayContents(
  Pixels::PixelArray pixelArray1, Pixels::PixelArray pixelArray2)
{
  int numberOfPixels = pixelArray1.sizeInPixels();

  for (int pixelNo = 0; pixelNo < numberOfPixels; pixelNo++) {
    Pixels::RGBPixel pixel1 = pixelArray1.pixels[pixelNo];
    Pixels::RGBPixel pixel2 = pixelArray2.pixels[pixelNo];

    EXPECT_EQ(pixel1.getBlue(), pixel2.getBlue());
    EXPECT_EQ(pixel1.getGreen(), pixel2.getGreen());
    EXPECT_EQ(pixel1.getRed(), pixel2.getRed());
  }
}

void BitmapImageComparison::comparePixelArrays(
  Pixels::PixelArray pixelArray1, Pixels::PixelArray pixelArray2)
{
  BitmapImageComparison::comparePixelArrayAttributes(
    pixelArray1, pixelArray2);
  
  BitmapImageComparison::comparePixelArrayContents(pixelArray1, pixelArray2);
}

void BitmapImageComparison::compareBitmapImages(
  BitmapImage image1, BitmapImage image2)
{
  BitmapImageComparison::compareBitmapFileHeaders(
    image1.getFileHeader(), image2.getFileHeader());
  
  BitmapImageComparison::compareBitmapDibHeaders(
    image1.getDibHeader(), image2.getDibHeader());
  
  BitmapImageComparison::comparePixelArrays(
    image1.getPixelArray(), image2.getPixelArray());
}