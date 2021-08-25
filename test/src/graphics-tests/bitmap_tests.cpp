#include <fstream>
#include <gtest/gtest.h>
#include <iostream>
#include <string>

#include "src/graphics/bitmaps/headers/file_header.h"
#include "src/graphics/bitmaps/headers/info_header.h"
#include "src/graphics/bitmaps/pixel.h"
#include "src/graphics/bitmaps/reader/bitmap_reader.h"

TEST(GraphicsTests, ShouldCreateBitmap)
{
  int widthInPixels = 512, heightInPixels = 512;

  BitmapFileHeader bmpFileHeader {14, widthInPixels, heightInPixels};
  BitmapInfoHeader bmpInfoHeader {40, widthInPixels, heightInPixels};
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
    Pixel* currentPixel = &blackPixel;
    
    if (i % 100)
      currentPixel = &pixel;

    char* pixelBytes = (*currentPixel).toBytes();
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
  BitmapReader bitmapReader;
  
  char* bitmapFile = (
    "C:\\Users\\rmvir\\Desktop\\scc300-Win3D\\test\\output\\" \
    "correct_resources\\blueImage512x512.bmp"
  );

  int correctSize = 786432;
  int payloadSizeInBytes = bitmapReader.getLengthOfPixelPayload(bitmapFile);

  ASSERT_EQ(correctSize, payloadSizeInBytes);
}

TEST(GraphicsTests, ShouldGetBitmapFileSize)
{
  BitmapReader bitmapReader;
  
  char* bitmapFile = (
    "C:\\Users\\rmvir\\Desktop\\scc300-Win3D\\test\\output\\" \
    "correct_resources\\blueImage512x512.bmp"
  );

  int correctSize = 786486;
  int fileSizeInBytes = bitmapReader.getSizeOfFile(bitmapFile);

  ASSERT_EQ(correctSize, fileSizeInBytes);
}

TEST(GraphicsTests, ShouldGetBitmapFileHeader)
{
  BitmapReader bmpReader;
  
  char* bmpFile = (
    "C:\\Users\\rmvir\\Desktop\\scc300-Win3D\\test\\output\\" \
    "correct_resources\\blueImage512x512.bmp"
  );

  BitmapFileHeader bmpFileHeader = bmpReader.getBitmapFileHeader(bmpFile);

  ASSERT_EQ('B', bmpFileHeader.bitmapSignatureBytes[0]);
  ASSERT_EQ('M', bmpFileHeader.bitmapSignatureBytes[1]);
  ASSERT_EQ(786486, bmpFileHeader.sizeOfBitmapFile);
  ASSERT_EQ(0, bmpFileHeader.reservedBytes);
  ASSERT_EQ(54, bmpFileHeader.pixelDataOffset);
}

TEST(GraphicsTests, ShouldGetBitmapInfoHeader)
{
  BitmapReader bmpReader;
  
  char* bmpFile = (
    "C:\\Users\\rmvir\\Desktop\\scc300-Win3D\\test\\output\\" \
    "correct_resources\\blueImage512x512.bmp"
  );

  BitmapInfoHeader bmpInfoHeader = bmpReader.getBitmapInfoHeader(bmpFile);

  ASSERT_EQ(40, bmpInfoHeader.sizeOfThisHeader);
  ASSERT_EQ(512, bmpInfoHeader.widthInPixels);
  ASSERT_EQ(512, bmpInfoHeader.heightInPixels);

}