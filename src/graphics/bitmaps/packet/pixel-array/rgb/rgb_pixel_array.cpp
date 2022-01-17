#include "src/graphics/bitmaps/packet/pixel-array/rgb/rgb_pixel.h"
#include "src/graphics/bitmaps/packet/pixel-array/rgb/rgb_pixel_array.h"
#include "src/graphics/bitmaps/packet/pixel-array/rgb/rgb_pixel_array_values.h"
#include "src/common/matrix-2D/matrix_2d.h"
#include "src/common/index.h"

Pixels::PixelArray::PixelArray()
{
  this->widthInPixels = 0;
  this->heightInPixels = 0;
  this->pixels = {this->widthInPixels, this->heightInPixels, {}};
}

Pixels::PixelArray::PixelArray(const Pixels::PixelArrayValues& values)
{
  this->pixels = {
    values.widthInPixels, values.heightInPixels, values.defaultPixel};
    
  this->widthInPixels = values.widthInPixels;
  this->heightInPixels = values.heightInPixels;
}

void Pixels::PixelArray::set(
  const Pixels::RGBPixel& pixel, int rowNo, int columnNo)
{
  this->pixels.set(pixel, rowNo, columnNo);
}

void Pixels::PixelArray::set(const Pixels::RGBPixel& pixel, int indexNo)
{
  this->pixels.set(pixel, indexNo);
}

Pixels::RGBPixel Pixels::PixelArray::at(int rowNo, int columnNo) const
{
  return this->pixels.at(rowNo, columnNo);
}

Pixels::RGBPixel Pixels::PixelArray::at(int indexNo) const
{
  return this->pixels.at(indexNo);
}

int Pixels::PixelArray::sizeInPixels() const
{
  return this->widthInPixels * this->heightInPixels;
}