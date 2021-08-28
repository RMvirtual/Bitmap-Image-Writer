#include <fstream>
#include <gtest/gtest.h>
#include <iostream>
#include <string>

#include "src/graphics/bitmaps/headers/file_header.h"
#include "src/graphics/bitmaps/headers/dib_header.h"
#include "src/graphics/bitmaps/pixel_array.h"
#include "src/graphics/bitmaps/pixel.h"
#include "src/graphics/bitmaps/reader/bitmap_reader.h"
#include "src/common/file_opener.h"

TEST(GraphicsTests, ShouldCreateBitmap)
{
  int widthInPixels = 512, heightInPixels = 512;

  BitmapFileHeader bmpFileHeader {widthInPixels, heightInPixels};
  BitmapDibHeader bmpInfoHeader {widthInPixels, heightInPixels};
  Pixel pixel {100, 255, 255};
  Pixel blackPixel {0, 0, 0};

  char* outputPath = 
    "C:\\Users\\rmvir\\Desktop\\scc300-Win3D\\test\\output\\myImage.bmp";

  std::ofstream fout(outputPath, std::ios::binary);

  char* bmpFileHeaderBytes = bmpFileHeader.toBytes();
  char* bmpInfoHeaderBytes = bmpInfoHeader.toBytes();
  
  fout.write(bmpFileHeaderBytes, bmpFileHeader.getSizeOfHeaderInBytes());
  fout.write(bmpInfoHeaderBytes, bmpInfoHeader.getSizeOfHeaderInBytes());

  delete[] bmpFileHeaderBytes;
  delete[] bmpInfoHeaderBytes;

  size_t numberOfPixels = widthInPixels * heightInPixels;
  
  for (int i = 0; i < numberOfPixels; i++) {
    char* pixelBytes = pixel.toBytes();
    fout.write(pixelBytes, 3);

    delete[] pixelBytes;
  }

  fout.close();

  short int word = 0x0001;
  char *byte = (char *) &word;
  
  std::string string1 = byte[0] ? "Little" : "big";
  std::cout << string1 << std::endl;
}

TEST(GraphicsTests, ShouldGetBitmapLength)
{
  char* bitmapFile = (
    "C:\\Users\\rmvir\\Desktop\\scc300-Win3D\\test\\output\\" \
    "correct_resources\\blueImage512x512.bmp"
  );

  int correctSize = 786432;
  int payloadSizeInBytes = BitmapReader::getLengthOfPixelPayload(bitmapFile);

  EXPECT_EQ(correctSize, payloadSizeInBytes);
}

TEST(GraphicsTests, ShouldGetBitmapFileSize)
{ 
  char* bitmapFile = (
    "C:\\Users\\rmvir\\Desktop\\scc300-Win3D\\test\\output\\" \
    "correct_resources\\blueImage512x512.bmp"
  );

  int correctSize = 786486;
  FileOpener fileOpener;
  int fileSizeInBytes = fileOpener.getSizeOfFile(bitmapFile);

  EXPECT_EQ(correctSize, fileSizeInBytes);
}

TEST(GraphicsTests, ShouldGetBitmapFileHeader)
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

TEST(GraphicsTests, ShouldGetBitmapInfoHeader)
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

TEST(GraphicsTests, ShouldGetPixelArray)
{
  char* bmpFile = (
    "C:\\Users\\rmvir\\Desktop\\scc300-Win3D\\test\\output\\" \
    "correct_resources\\blueImage512x512.bmp"
  );

  PixelArray pixelArray = BitmapReader::getPixelArray(bmpFile);
  PixelArray correctPixelArray = PixelArray{
    std::vector<Pixel>{{0,0,0}},
    1, 1
  };

  for (int pixelNo = 0; pixelNo < pixelArray.pixels.size(); pixelNo++) {
    Pixel pixelToTest = pixelArray.pixels[pixelNo];
    Pixel correctPixel = correctPixelArray.pixels[pixelNo];

    EXPECT_EQ(correctPixel.getRed(), pixelToTest.getRed());
    EXPECT_EQ(correctPixel.getGreen(), pixelToTest.getGreen());
    EXPECT_EQ(correctPixel.getBlue(), pixelToTest.getBlue());

  }

}