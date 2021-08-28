#include "src/graphics/bitmaps/pixel_array.h"
#include "src/graphics/bitmaps/pixel.h"

#include <string>
#include <queue>
#include <vector>
#include <iomanip>
#include <iostream>

using namespace std;

PixelArray::PixelArray(vector<Pixel> pixels, int widthInPixels, int heightInPixels)
{
  if (pixels.size() != widthInPixels * heightInPixels)
    throw length_error(
      "Number of pixels does not match given height and width. " \
      "Number of pixels is " + to_string(pixels.size()) + " while " \
      "correct size from parameters is " + to_string(
        widthInPixels * heightInPixels)
    );

  this->pixels = pixels;
  this->widthInPixels = widthInPixels;
  this->heightInPixels = heightInPixels;

  /*
  queue<Pixel> pixelQueue;

  for (auto pixel : pixels) {
    pixelQueue.push(pixel);
  }

  for (int rowNo = 0; rowNo < heightInPixels; rowNo++) {
    for (int columnNo = 0; columnNo < widthInPixels; columnNo++) {
      Pixel currentPixel = pixelQueue.front();
      pixelQueue.pop();    

      this->pixels.push_back(currentPixel);
    }
  }

  */
}

int PixelArray::sizeInBytes()
{
  int numberOfPixels = this->sizeInPixels();
  int numberOfColourChannels = 3;

  int totalSizeInBytes = numberOfPixels * numberOfColourChannels;

  return totalSizeInBytes;
}

int PixelArray::sizeInPixels()
{
  int numberOfPixels = this->widthInPixels * this->heightInPixels;

  return numberOfPixels;
}