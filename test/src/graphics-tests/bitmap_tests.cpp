#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include "src/graphics/bitmap.h"

TEST(GraphicsTests, ShouldCreateBitmap)
{
  BitmapFileHeader bmpFileHeader;
  BitmapHeaderStruct bmpHeaderStruct;
  BitmapInfoHeader bmpInfoHeader;
  BitmapInfoHeaderStruct bmpInfoHeaderStruct;
  Pixel pixel;

  cout << "Size of bmpHeader: " + to_string(sizeof(bmpHeaderStruct)) << endl;
  cout << "Size of bmpInfoHeader: " + to_string(sizeof(bmpInfoHeader)) << endl;
  cout << "Size of pixel: " + to_string(sizeof(pixel)) << endl;

  char* outputPath = "C:\\Users\\rmvir\\Desktop\\scc300-Win3D\\test\\output\\myImage.bmp";
  ofstream fout(outputPath, ios::binary);

  cout << bmpInfoHeader.toBytes() << endl;

  fout.write(bmpFileHeader.toBytes(), 14);
  // fout.write(bmpInfoHeader.toBytes(), 40);

  // fout.write((char *) &bmpInfoHeaderStruct, 40);
  fout.write((char *) &bmpInfoHeaderStruct.sizeOfThisHeader, 4);
  fout.write((char *) &bmpInfoHeaderStruct.widthInPixels, 4);
  fout.write((char *) &bmpInfoHeaderStruct.heightInPixels, 4);
  fout.write((char *) &bmpInfoHeaderStruct.numberOfColorPlanes, 2);
  fout.write((char *) &bmpInfoHeaderStruct.colorDepth, 2);
  fout.write((char *) &bmpInfoHeaderStruct.compressionMethod, 4);
  fout.write((char *) &bmpInfoHeaderStruct.rawBitmapDataSize, 4);
  fout.write((char *) &bmpInfoHeaderStruct.horizontalResolutionPixelPerMeter, 4);
  fout.write((char *) &bmpInfoHeaderStruct.verticalResolutionPixelsPerMeter, 4);
  fout.write((char *) &bmpInfoHeaderStruct.colorTableEntries, 4);
  fout.write((char *) &bmpInfoHeaderStruct.importantColors, 4);
  

  size_t numberOfPixels = bmpInfoHeader.widthInPixels * bmpInfoHeader.heightInPixels;
  
  for (int i = 0; i < numberOfPixels; i++)
    fout.write((char *) &pixel, 3);
  
  fout.close();
}