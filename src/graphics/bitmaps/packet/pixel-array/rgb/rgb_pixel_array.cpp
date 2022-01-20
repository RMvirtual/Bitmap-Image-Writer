#include "src/graphics/bitmaps/packet/pixel-array/rgb/rgb_pixel.h"
#include "src/graphics/bitmaps/packet/pixel-array/rgb/rgb_pixel_array.h"
#include "src/graphics/bitmaps/packet/pixel-array/rgb/rgb_pixel_array_values.h"
#include "src/common/matrix-2D/matrix_2d.h"
#include "src/common/index.h"

Pixels::RGBPixelArray::RGBPixelArray()
{
  // pass.
}

Pixels::RGBPixelArray::RGBPixelArray(const Pixels::RGBPixelArrayValues& values)
{
  this->pixels = {
    values.widthInPixels, values.heightInPixels, values.defaultPixel};
}

void Pixels::RGBPixelArray::set(
  const Pixels::RGBPixel& pixel, int rowNo, int columnNo)
{
  this->pixels.set(pixel, rowNo, columnNo);
}

void Pixels::RGBPixelArray::set(const Pixels::RGBPixel& pixel, int indexNo)
{
  this->pixels.set(pixel, indexNo);
}

Pixels::RGBPixel Pixels::RGBPixelArray::at(int rowNo, int columnNo) const
{
  return this->pixels.at(rowNo, columnNo);
}

Pixels::RGBPixel Pixels::RGBPixelArray::at(int indexNo) const
{
  return this->pixels.at(indexNo);
}

int Pixels::RGBPixelArray::sizeInPixels() const
{
  return this->pixels.width() * this->pixels.height();
}