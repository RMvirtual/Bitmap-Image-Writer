#include <fstream>
#include <gtest/gtest.h>
#include <iostream>
#include <string>

#include "src/graphics/bitmaps/packet/headers/file_header.h"
#include "src/graphics/bitmaps/packet/headers/dib_header.h"
#include "src/graphics/bitmaps/packet/pixels/pixel_array.h"
#include "src/graphics/bitmaps/packet/pixels/pixel.h"
#include "src/graphics/bitmaps/reader/bitmap_reader.h"
#include "src/common/filesystem.h"

TEST(BitmapWriterTests, ShouldCreateBitmap)
{
  int widthInPixels = 512, heightInPixels = 512;

  BitmapFileHeader bmpFileHeader {widthInPixels, heightInPixels};
  BitmapDibHeader bmpInfoHeader {widthInPixels, heightInPixels};
  Pixel bluePixel {100, 255, 255};

  size_t numberOfPixels = widthInPixels * heightInPixels;
  std::vector<Pixel> pixelsToAdd;

  for (int i = 0; i < numberOfPixels; i++)
    pixelsToAdd.push_back(bluePixel);

  PixelArray pixelArray {pixelsToAdd, widthInPixels, heightInPixels};

  char* outputPath = 
    "C:\\Users\\rmvir\\Desktop\\scc300-Win3D\\test\\output\\myImage.bmp";

  std::ofstream fout(outputPath, std::ios::binary);

  char* bmpFileHeaderBytes = bmpFileHeader.toBytes();
  char* bmpInfoHeaderBytes = bmpInfoHeader.toBytes();
  
  fout.write(bmpFileHeaderBytes, bmpFileHeader.getSizeOfHeaderInBytes());
  fout.write(bmpInfoHeaderBytes, bmpInfoHeader.getSizeOfHeaderInBytes());
  
  for (auto pixel : pixelArray.pixels) {
    char* pixelBytes = pixel.toBytes();
    fout.write(pixelBytes, 3);

    delete[] pixelBytes;
  }

  delete[] bmpFileHeaderBytes;
  delete[] bmpInfoHeaderBytes;

  fout.close();

  char* correctImage =
    "C:\\Users\\rmvir\\Desktop\\scc300-Win3D\\test\\output\\" \
    "correct_resources\\blueImage512x512.bmp";

  BitmapFileHeader correctFileHeader 
    = BitmapReader::getBitmapFileHeader(correctImage);

  BitmapDibHeader correctDibHeader =
    BitmapReader::getBitmapDibHeader(correctImage);

  PixelArray correctPixels = BitmapReader::getPixelArray(correctImage);
  
  int correctPixelSizeInBytes
    = BitmapReader::getPixelArraySizeInBytes(correctImage);

  char* myImage = 
    "C:\\Users\\rmvir\\Desktop\\scc300-Win3D\\test\\output\\myImage.bmp";
  
  BitmapFileHeader myImageFileHeader 
    = BitmapReader::getBitmapFileHeader(myImage);

  BitmapDibHeader myImageDibHeader =
    BitmapReader::getBitmapDibHeader(myImage);

  PixelArray myImageCorrectPixels = BitmapReader::getPixelArray(myImage);
  
  int myImageCorrectPixelSizeInBytes
    = BitmapReader::getPixelArraySizeInBytes(myImage);
}
