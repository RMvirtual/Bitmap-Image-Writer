#include <fstream>
#include <gtest/gtest.h>
#include <iostream>
#include <string>

#include "src/graphics/bitmaps/bitmap.h"
#include "src/graphics/bitmaps/file_header.h"
#include "src/graphics/bitmaps/info_header.h"

TEST(GraphicsTests, ShouldCreateBitmap)
{
  int widthInPixels = 512, heightInPixels = 512;

  BitmapFileHeader bmpFileHeader {14};
  BitmapHeaderStruct bmpHeaderStruct;
  BitmapInfoHeader bmpInfoHeader {40, widthInPixels, heightInPixels};
  BitmapInfoHeaderStruct bmpInfoHeaderStruct;
  Pixel pixel;

  char* outputPath = 
    "C:\\Users\\rmvir\\Desktop\\scc300-Win3D\\test\\output\\myImage.bmp";

  std::ofstream fout(outputPath, std::ios::binary);

  fout.write(bmpFileHeader.toBytes(), bmpFileHeader.getSizeOfHeaderInBytes());
  fout.write(bmpInfoHeader.toBytes(), bmpInfoHeader.getSizeOfHeaderInBytes());

  size_t numberOfPixels = widthInPixels * heightInPixels;
  
  for (int i = 0; i < numberOfPixels; i++)
    fout.write((char *) &pixel, 3);
  
  fout.close();

  short int word = 0x0001;
  char *byte = (char *) &word;
  
  std::string string1 = byte[0] ? "Little" : "big";
  std::cout << string1 << std::endl;
}