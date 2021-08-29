#include <fstream>
#include <gtest/gtest.h>
#include <iostream>
#include <string>

#include "src/graphics/bitmaps/packet/headers/file_header.h"
#include "src/graphics/bitmaps/packet/headers/dib_header.h"
#include "src/graphics/bitmaps/packet/pixels/pixel_array.h"
#include "src/graphics/bitmaps/packet/pixels/pixel.h"
#include "src/graphics/bitmaps/reader/bitmap_reader.h"
#include "src/common/filesystem.h"
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

BitmapImage setupBlueBitmapImage()
{
  int widthInPixels = 512, heightInPixels = 512;

  BitmapFileHeader bmpFileHeader {widthInPixels, heightInPixels};
  BitmapDibHeader bmpInfoHeader {widthInPixels, heightInPixels};
  Pixel bluePixel {100, 255, 255};

  size_t numberOfPixels = widthInPixels * heightInPixels;
  std::vector<Pixel> pixelsToAdd;

  for (int i = 0; i < numberOfPixels; i++)
    pixelsToAdd.push_back(bluePixel);

  PixelArray pixelArray {pixelsToAdd, widthInPixels, heightInPixels};

  BitmapImage bitmapImage {bmpFileHeader, bmpInfoHeader, pixelArray};

  return bitmapImage;
}

void writeBitmapImage(BitmapImage bitmapImage)
{
  char* outputPath = 
    "C:\\Users\\rmvir\\Desktop\\scc300-Win3D\\test\\output\\myImage.bmp";

  char* bitmapImageBytes = bitmapImage.toBytes();
  int bitmapImageSize = bitmapImage.getSizeOfBytes();

  std::ofstream fout(outputPath, std::ios::binary);
  fout.write(bitmapImageBytes, bitmapImageSize);  
  fout.close();

  delete[] bitmapImageBytes;
}

TEST(BitmapWriterTests, ShouldCreateBitmap)
{
  BitmapImage bitmapImage = setupBlueBitmapImage();
  writeBitmapImage(bitmapImage);

  char* correctImage =
    "C:\\Users\\rmvir\\Desktop\\scc300-Win3D\\test\\output\\" \
    "correct_resources\\blueImage512x512.bmp";

  BitmapFileHeader correctFileHeader 
    = BitmapReader::getBitmapFileHeader(correctImage);

  BitmapDibHeader correctDibHeader =
    BitmapReader::getBitmapDibHeader(correctImage);

  PixelArray correctPixels = BitmapReader::getPixelArray(correctImage);
  
  int correctPixelSizeInBytes
    = BitmapReader::getPixelArraySizeInBytes(correctImage);

  char* myImage = 
    "C:\\Users\\rmvir\\Desktop\\scc300-Win3D\\test\\output\\myImage.bmp";
  
  BitmapFileHeader myImageFileHeader 
    = BitmapReader::getBitmapFileHeader(myImage);

  BitmapDibHeader myImageDibHeader =
    BitmapReader::getBitmapDibHeader(myImage);

  PixelArray myImageCorrectPixels = BitmapReader::getPixelArray(myImage);
  
  int myImageCorrectPixelSizeInBytes
    = BitmapReader::getPixelArraySizeInBytes(myImage);

  compareBitmapFileHeaders(correctFileHeader, myImageFileHeader);
  compareBitmapDibHeaders(correctDibHeader, myImageDibHeader);
  comparePixelArrays(correctPixels, myImageCorrectPixels);
}