#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include "src/graphics/bitmap.h"

TEST(GraphicsTests, ShouldCreateBitmap)
{
  BitmapHeader bmpHeader;
  BitmapInfoHeader bmpInfoHeader;
  Pixel pixel;

  cout << "Size of bmpHeader: " + to_string(sizeof(bmpHeader)) << endl;
  cout << "Size of bmpInfoHeader: " + to_string(sizeof(bmpInfoHeader)) << endl;
  cout << "Size of pixel: " + to_string(sizeof(pixel)) << endl;

  char* outputPath = "C:\\Users\\rmvir\\Desktop\\scc300-Win3D\\test\\output\\myImage.bmp";
  ofstream fout(outputPath, ios::binary);

  fout.write((char *) &bmpHeader.bitmapSignatureBytes[0], 1);
  fout.write((char *) &bmpHeader.bitmapSignatureBytes[1], 1);
  fout.write((char *) &bmpHeader.sizeOfBitmapFile, 4);
  fout.write((char *) &bmpHeader.reservedBytes, 4);
  fout.write((char *) &bmpHeader.pixelDataOffset, 4);

  fout.write((char *) &bmpInfoHeader, 40);

  // writing pixel data
  size_t numberOfPixels = bmpInfoHeader.widthInPixels * bmpInfoHeader.heightInPixels;
  
  for (int i = 0; i < numberOfPixels; i++)
    fout.write((char *) &pixel, 3);
  
  fout.close();
}