#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include "src/graphics/bitmaps/bitmap.h"

TEST(GraphicsTests, ShouldCreateBitmap)
{
  BitmapFileHeader bmpFileHeader {14};
  BitmapHeaderStruct bmpHeaderStruct;
  BitmapInfoHeader bmpInfoHeader;
  BitmapInfoHeaderStruct bmpInfoHeaderStruct;
  Pixel pixel;

  char* outputPath = 
    "C:\\Users\\rmvir\\Desktop\\scc300-Win3D\\test\\output\\myImage.bmp";

  ofstream fout(outputPath, ios::binary);

  fout.write(bmpFileHeader.toBytes(), bmpFileHeader.getSizeOfHeaderInBytes());
  fout.write(bmpInfoHeader.toBytes(), bmpInfoHeader.getSizeOfHeaderInBytes());

  size_t numberOfPixels = bmpInfoHeader.widthInPixels * bmpInfoHeader.heightInPixels;
  
  for (int i = 0; i < numberOfPixels; i++)
    fout.write((char *) &pixel, 3);
  
  fout.close();

  short int word = 0x0001;
  char *byte = (char *) &word;
  
  string string1 = byte[0] ? "Little" : "big";
  cout << string1 << endl;

}