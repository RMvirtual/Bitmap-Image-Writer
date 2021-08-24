#include <fstream>
#include <gtest/gtest.h>
#include <iostream>
#include <string>

#include "src/graphics/bitmaps/file_header.h"
#include "src/graphics/bitmaps/info_header.h"
#include "src/graphics/bitmaps/pixel.h"

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