#include <gtest/gtest.h>

#include "src/graphics/bitmaps/packet/pixels/pixel.h"
#include "src/graphics/bitmaps/packet/pixels/pixel_array.h"
#include "src/graphics/bitmaps/reader/bitmap_reader.h"
#include "src/graphics/bitmaps/bitmap_image.h"

void compareBitmapFileHeaders(
  BitmapFileHeader header1, BitmapFileHeader header2)
{
  EXPECT_EQ(header1.getSignatureBytes()[0], header2.getSignatureBytes()[0]);
  EXPECT_EQ(header1.getSignatureBytes()[1], header2.getSignatureBytes()[1]);
  EXPECT_EQ(header1.getSizeOfBitmapFile(), header2.getSizeOfBitmapFile());
  EXPECT_EQ(header1.getReservedBytes(), header2.getReservedBytes());
  EXPECT_EQ(header2.getPixelDataOffset(), header2.getPixelDataOffset());
}

void compareBitmapDibHeaders(
  BitmapDibHeader header1, BitmapDibHeader header2)
{
  EXPECT_EQ(
    header1.getSizeOfHeaderInBytes(), header2.getSizeOfHeaderInBytes());

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

void comparePixelArrayAttributes(
  PixelArray pixelArray1, PixelArray pixelArray2)
{
  EXPECT_EQ(pixelArray1.getHeightInPixels(), pixelArray2.getHeightInPixels());
  EXPECT_EQ(pixelArray1.getWidthInPixels(), pixelArray2.getWidthInPixels());
  EXPECT_EQ(pixelArray1.sizeInPixels(), pixelArray2.sizeInPixels());
  EXPECT_EQ(pixelArray1.sizeInBytes(), pixelArray2.sizeInBytes());
}

void comparePixelArrayContents(PixelArray pixelArray1, PixelArray pixelArray2)
{
  int numberOfPixels = pixelArray1.sizeInPixels();

  for (int pixelNo = 0; pixelNo < numberOfPixels; pixelNo++) {
    Pixel pixel1 = pixelArray1.pixels[pixelNo];
    Pixel pixel2 = pixelArray2.pixels[pixelNo];

    EXPECT_EQ(pixel1.getBlue(), pixel2.getBlue());
    EXPECT_EQ(pixel1.getGreen(), pixel2.getGreen());
    EXPECT_EQ(pixel1.getRed(), pixel2.getRed());
  }
}

void comparePixelArrays(PixelArray pixelArray1, PixelArray pixelArray2)
{
  comparePixelArrayAttributes(pixelArray1, pixelArray2);
  comparePixelArrayContents(pixelArray1, pixelArray2);
}

void compareBitmapImages(BitmapImage image1, BitmapImage image2)
{
  compareBitmapFileHeaders(image1.getFileHeader(), image2.getFileHeader());
  compareBitmapDibHeaders(image1.getDibHeader(), image2.getDibHeader());
  comparePixelArrays(image1.getPixelArray(), image2.getPixelArray());
}