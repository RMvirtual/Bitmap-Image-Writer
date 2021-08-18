#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include "src/graphics/bitmap.h"

TEST(GraphicsTests, ShouldCreateBitmap)
{
  BitmapHeader bmpHeader;
  BitmapInfoHeader bmpInfoHeader;
  Pixel pixel;

  std::cout << bmpHeader.bitmapSignatureBytes[0] << endl;

  char* outputPath = "C:\\Users\\rmvir\\Desktop\\scc300-Win3D\\build\\test_bitmap.bmp";
  ofstream fout(outputPath, ios::binary);

  fout.write((char *) &bmpHeader, 14);
  fout.write((char *) &bmpInfoHeader, 40);

  // writing pixel data
  size_t numberOfPixels = bmpInfoHeader.widthInPixels * bmpInfoHeader.heightInPixels;
  
  for (int i = 0; i < numberOfPixels; i++)
    fout.write((char *) &pixel, 3);
  
  fout.close();
}