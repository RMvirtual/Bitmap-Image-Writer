#include <gtest/gtest.h>

#include "src/graphics/bitmaps/packet/pixels/pixel.h"
#include "src/graphics/bitmaps/packet/pixels/pixel_array.h"
#include "src/graphics/bitmaps/reader/bitmap_reader.h"

TEST(BitmapReaderTests, ShouldExtractBitmapFileHeaderFromImage)
{ 
  char* bmpFile = (
    "C:\\Users\\rmvir\\Desktop\\scc300-Win3D\\test\\output\\" \
    "correct_resources\\blueImage512x512.bmp"
  );

  BitmapFileHeader bmpFileHeader = BitmapReader::getBitmapFileHeader(bmpFile);

  EXPECT_EQ('B', bmpFileHeader.getSignatureBytes()[0]);
  EXPECT_EQ('M', bmpFileHeader.getSignatureBytes()[1]);  
  EXPECT_EQ("BM", bmpFileHeader.getSignatureBytes());
  EXPECT_EQ(786486, bmpFileHeader.getSizeOfBitmapFile());
  EXPECT_EQ(0, bmpFileHeader.getReservedBytes());
  EXPECT_EQ(54, bmpFileHeader.getPixelDataOffset());
}

TEST(BitmapReaderTests, ShouldExtractBitmapInfoHeaderFromImage)
{
  char* bmpFile = (
    "C:\\Users\\rmvir\\Desktop\\scc300-Win3D\\test\\output\\" \
    "correct_resources\\blueImage512x512.bmp"
  );

  BitmapDibHeader bmpInfoHeader = BitmapReader::getBitmapDibHeader(bmpFile);

  EXPECT_EQ(40, bmpInfoHeader.getSizeOfHeaderInBytes());
  EXPECT_EQ(512, bmpInfoHeader.getWidthInPixels());
  EXPECT_EQ(512, bmpInfoHeader.getHeightInPixels());
  EXPECT_EQ(1, bmpInfoHeader.getNumberOfColorPlanes());
  EXPECT_EQ(0, bmpInfoHeader.getCompressionMethod());
  EXPECT_EQ(0, bmpInfoHeader.getRawBitmapDataSize());
  EXPECT_EQ(0, bmpInfoHeader.getHorizontalPixelsPerMetre());
  EXPECT_EQ(0, bmpInfoHeader.getVerticalPixelsPerMetre());
  EXPECT_EQ(0, bmpInfoHeader.getColorTableEntries());
  EXPECT_EQ(0, bmpInfoHeader.getImportantColors());
}

TEST(BitmapReaderTests, ShouldExtractPixelArrayFromImage)
{
  char* bmpFile = (
    "C:\\Users\\rmvir\\Desktop\\scc300-Win3D\\test\\output\\" \
    "correct_resources\\blueImage512x512.bmp"
  );

  PixelArray pixelArray = BitmapReader::getPixelArray(bmpFile);
  std::vector<Pixel> correctPixels;
  Pixel bluePixel {100, 255, 255};

  int imageWidth = 512, imageHeight = 512;
  int totalPixels = imageWidth * imageHeight;

  for (int pixelNo = 0; pixelNo < totalPixels; pixelNo++)
    correctPixels.push_back(bluePixel);
  
  PixelArray correctPixelArray = PixelArray {
    correctPixels, imageWidth, imageHeight};

  for (int pixelNo = 0; pixelNo < totalPixels; pixelNo++) {
    Pixel pixelToTest = pixelArray.pixels[pixelNo];
    Pixel correctPixel = correctPixelArray.pixels[pixelNo];

    EXPECT_EQ(correctPixel.getRed(), pixelToTest.getRed());
    EXPECT_EQ(correctPixel.getGreen(), pixelToTest.getGreen());
    EXPECT_EQ(correctPixel.getBlue(), pixelToTest.getBlue());
  }
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
