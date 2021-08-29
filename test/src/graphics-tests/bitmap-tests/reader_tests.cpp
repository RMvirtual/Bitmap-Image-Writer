#include <gtest/gtest.h>

#include "src/graphics/bitmaps/packet/pixels/pixel.h"
#include "src/graphics/bitmaps/packet/pixels/pixel_array.h"
#include "src/graphics/bitmaps/reader/bitmap_reader.h"
#include "src/graphics/bitmaps/bitmap_image.h"

BitmapFileHeader setUpBluePixelFileHeader()
{
  BitmapFileHeader fileHeader;

  fileHeader.setSignatureBytes("BM");
  fileHeader.setSizeOfBitmapFile(786486);
  fileHeader.setReservedBytes(0);
  fileHeader.setPixelDataOffset(54);

  return fileHeader;
}

BitmapDibHeader setUpBluePixelDibHeader()
{
  BitmapDibHeader dibHeader = BitmapDibHeader();

  dibHeader.setSizeOfHeaderInBytes(40);
  dibHeader.setWidthInPixels(512);
  dibHeader.setHeightInPixels(512);
  dibHeader.setNumberOfColourPlanes(1);

  return dibHeader;
}

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

BitmapImage setUpBluePixelBitmapImage()
{
  BitmapFileHeader fileHeader = setUpBluePixelFileHeader();
  BitmapDibHeader dibHeader = setUpBluePixelDibHeader();
  PixelArray pixelArray = setUpBluePixelArray();

  BitmapImage bitmapImage {fileHeader, dibHeader, pixelArray};

  return bitmapImage;
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

void compareBitmapImages(BitmapImage image1, BitmapImage image2)
{
  compareBitmapFileHeaders(image1.getFileHeader(), image2.getFileHeader());
  compareBitmapDibHeaders(image1.getDibHeader(), image2.getDibHeader());
  comparePixelArrays(image1.getPixelArray(), image2.getPixelArray());
}

TEST(BitmapReaderTests, ShouldExtractFileHeaderFromFile)
{ 
  char* imageToTest = (
    "C:\\Users\\rmvir\\Desktop\\scc300-Win3D\\test\\output\\" \
    "correct_resources\\blueImage512x512.bmp"
  );

  BitmapFileHeader fileHeader = BitmapReader::getBitmapFileHeader(imageToTest);
  BitmapFileHeader correctFileHeader = setUpBluePixelFileHeader();
  
  compareBitmapFileHeaders(correctFileHeader, fileHeader);
}

TEST(BitmapReaderTests, ShouldExtractDibHeaderFromFile)
{
  char* bmpFile = (
    "C:\\Users\\rmvir\\Desktop\\scc300-Win3D\\test\\output\\" \
    "correct_resources\\blueImage512x512.bmp"
  );

  BitmapDibHeader dibHeader = BitmapReader::getBitmapDibHeader(bmpFile);
  BitmapDibHeader correctDibHeader = setUpBluePixelDibHeader();

  compareBitmapDibHeaders(correctDibHeader, dibHeader);
}

TEST(BitmapReaderTests, ShouldExtractPixelArrayFromFile)
{
  char* imageToTest = (
    "C:\\Users\\rmvir\\Desktop\\scc300-Win3D\\test\\output\\" \
    "correct_resources\\blueImage512x512.bmp"
  );

  PixelArray pixelArrayToTest = BitmapReader::getPixelArray(imageToTest);
  PixelArray correctPixelArray = setUpBluePixelArray();

  comparePixelArrays(correctPixelArray, pixelArrayToTest);
}

TEST(BitmapReaderTests, ShouldExtractPixelArraySizeFromFile)
{
  char* bitmapFile = (
    "C:\\Users\\rmvir\\Desktop\\scc300-Win3D\\test\\output\\" \
    "correct_resources\\blueImage512x512.bmp"
  );

  int correctSize = 786432;
  int payloadSizeInBytes = BitmapReader::getPixelArraySizeInBytes(bitmapFile);

  EXPECT_EQ(correctSize, payloadSizeInBytes);
}

TEST(BitmapReaderTests, ShouldExtractBitmapImageObjectFromFile)
{
  char* imagePath =
    "C:\\Users\\rmvir\\Desktop\\scc300-Win3D\\test\\output\\" \
    "correct_resources\\blueImage512x512.bmp";

  BitmapImage imageToTest = BitmapImage::fromFile(imagePath);
  BitmapImage correctImage = setUpBluePixelBitmapImage();

  compareBitmapImages(correctImage, imageToTest);
}