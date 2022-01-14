#include "src/graphics/bitmaps/packet/pixel-array/pixels/rgb_pixel.h"
#include "src/graphics/bitmaps/packet/pixel-array/arrays/pixel_array.h"
#include "src/common/matrix-2D/matrix_2d.h"

Pixels::PixelArray::PixelArray()
{
  this->widthInPixels = 0;
  this->heightInPixels = 0;
  this->pixels = {this->widthInPixels, this->heightInPixels, {}};
}

Pixels::PixelArray::PixelArray(
  int widthInPixels, int heightInPixels, Pixels::RGBPixel defaultPixel)
{
  this->pixels = {widthInPixels, heightInPixels, defaultPixel};
  this->widthInPixels = widthInPixels;
  this->heightInPixels = heightInPixels;
}

void Pixels::PixelArray::set(Pixels::RGBPixel pixel, int rowNo, int columnNo)
{
  this->pixels.set(pixel, rowNo, columnNo);
}

Pixels::RGBPixel Pixels::PixelArray::at(int rowNo, int columnNo)
{
  return this->pixels.at(rowNo, columnNo);
}

int Pixels::PixelArray::sizeInPixels()
{
  return this->widthInPixels * this->heightInPixels;
}