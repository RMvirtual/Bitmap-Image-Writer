#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include "src/graphics/bitmap.h"

TEST(GraphicsTests, ShouldCreateBitmap)
{
  BitmapFileHeader bmpFileHeader;
  BitmapHeaderStruct bmpHeaderStruct;
  BitmapInfoHeader bmpInfoHeader;
  Pixel pixel;

  cout << "Size of bmpHeader: " + to_string(sizeof(bmpHeaderStruct)) << endl;
  cout << "Size of bmpInfoHeader: " + to_string(sizeof(bmpInfoHeader)) << endl;
  cout << "Size of pixel: " + to_string(sizeof(pixel)) << endl;

  char* outputPath = "C:\\Users\\rmvir\\Desktop\\scc300-Win3D\\test\\output\\myImage.bmp";
  ofstream fout(outputPath, ios::binary);

  cout << &bmpHeaderStruct << endl;

  fout.write(bmpFileHeader.toBytesFromString(), 2);
  fout.write((char *) &bmpHeaderStruct.sizeOfBitmapFile, 4);
  fout.write((char *) &bmpHeaderStruct.reservedBytes, 4);
  fout.write((char *) &bmpHeaderStruct.pixelDataOffset, 4);

  fout.write((char *) &bmpInfoHeader, 40);

  size_t numberOfPixels = bmpInfoHeader.widthInPixels * bmpInfoHeader.heightInPixels;
  
  for (int i = 0; i < numberOfPixels; i++)
    fout.write((char *) &pixel, 3);
  
  fout.close();
}