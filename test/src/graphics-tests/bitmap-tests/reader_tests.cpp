#include <gtest/gtest.h>

#include "src/graphics/bitmaps/packet/pixels/pixel.h"
#include "src/graphics/bitmaps/packet/pixels/pixel_array.h"
#include "src/graphics/bitmaps/reader/bitmap_reader.h"

PixelArray setUpBluePixelArray()
{
  std::vector<Pixel> pixels;
  Pixel bluePixel {100, 255, 255};

  int imageWidth = 512, imageHeight = 512;
  int totalPixels = imageWidth * imageHeight;

  for (int pixelNo = 0; pixelNo < totalPixels; pixelNo++)
    pixels.push_back(bluePixel);
  
  PixelArray pixelArray = PixelArray {pixels, imageWidth, imageHeight};

  return pixelArray;
}

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

void comparePixelArrays(PixelArray pixelArray1, PixelArray pixelArray2)
{
  EXPECT_EQ(pixelArray1.getHeightInPixels(), pixelArray2.getHeightInPixels());
  EXPECT_EQ(pixelArray1.getWidthInPixels(), pixelArray2.getWidthInPixels());
  EXPECT_EQ(pixelArray1.sizeInPixels(), pixelArray2.sizeInPixels());
  EXPECT_EQ(pixelArray1.sizeInBytes(), pixelArray2.sizeInBytes());

  int numberOfPixels = pixelArray1.sizeInPixels();

  for (int pixelNo = 0; pixelNo < numberOfPixels; pixelNo++) {
    Pixel pixel1 = pixelArray1.pixels[pixelNo];
    Pixel pixel2 = pixelArray2.pixels[pixelNo];

    EXPECT_EQ(pixel1.getBlue(), pixel2.getBlue());
    EXPECT_EQ(pixel1.getGreen(), pixel2.getGreen());
    EXPECT_EQ(pixel1.getRed(), pixel2.getRed());
  }
}



TEST(BitmapReaderTests, ShouldExtractFileHeaderFromImage)
{ 
  char* imageToTest = (
    "C:\\Users\\rmvir\\Desktop\\scc300-Win3D\\test\\output\\" \
    "correct_resources\\blueImage512x512.bmp"
  );

  BitmapFileHeader fileHeader = BitmapReader::getBitmapFileHeader(imageToTest);
  BitmapFileHeader correctFileHeader = BitmapFileHeader();

  correctFileHeader.setSignatureBytes("BM");
  correctFileHeader.setSizeOfBitmapFile(786486);
  correctFileHeader.setReservedBytes(0);
  correctFileHeader.setPixelDataOffset(54);

  compareBitmapFileHeaders(correctFileHeader, fileHeader);
}

TEST(BitmapReaderTests, ShouldExtractDibHeaderFromImage)
{
  char* bmpFile = (
    "C:\\Users\\rmvir\\Desktop\\scc300-Win3D\\test\\output\\" \
    "correct_resources\\blueImage512x512.bmp"
  );

  BitmapDibHeader dibHeader = BitmapReader::getBitmapDibHeader(bmpFile);
  BitmapDibHeader correctDibHeader = BitmapDibHeader();

  correctDibHeader.setSizeOfHeaderInBytes(40);
  correctDibHeader.setWidthInPixels(512);
  correctDibHeader.setHeightInPixels(512);
  correctDibHeader.setNumberOfColourPlanes(1);

  compareBitmapDibHeaders(correctDibHeader, dibHeader);
}

TEST(BitmapReaderTests, ShouldExtractPixelArrayFromImage)
{
  char* imageToTest = (
    "C:\\Users\\rmvir\\Desktop\\scc300-Win3D\\test\\output\\" \
    "correct_resources\\blueImage512x512.bmp"
  );

  PixelArray pixelArrayToTest = BitmapReader::getPixelArray(imageToTest);
  PixelArray correctPixelArray = setUpBluePixelArray();

  comparePixelArrays(correctPixelArray, pixelArrayToTest);
}

TEST(BitmapReaderTests, ShouldExtractPixelArraySizeFromImage)
{
  char* bitmapFile = (
    "C:\\Users\\rmvir\\Desktop\\scc300-Win3D\\test\\output\\" \
    "correct_resources\\blueImage512x512.bmp"
  );

  int correctSize = 786432;
  int payloadSizeInBytes = BitmapReader::getPixelArraySizeInBytes(bitmapFile);

  EXPECT_EQ(correctSize, payloadSizeInBytes);
}
