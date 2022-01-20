#include "src/graphics/bitmaps/packet/pixel-array/rgba/rgba_pixel.h"
#include "src/graphics/bitmaps/packet/pixel-array/rgba/rgba_pixel_array.h"
#include "src/graphics/bitmaps/packet/pixel-array/rgba/rgba_pixel_array_values.h"
#include "src/common/matrix-2D/matrix_2d.h"
#include "src/common/index.h"

Pixels::RGBAPixelArray::RGBAPixelArray()
{
  // pass.
}

Pixels::RGBAPixelArray::RGBAPixelArray(
  const Pixels::RGBAPixelArrayValues& values)
{
  this->pixels = {
    values.widthInPixels, values.heightInPixels, values.defaultPixel};
}

void Pixels::RGBAPixelArray::set(
  const Pixels::RGBAPixel& pixel, int rowNo, int columnNo)
{
  this->pixels.set(pixel, rowNo, columnNo);
}

void Pixels::RGBAPixelArray::set(const Pixels::RGBAPixel& pixel, int indexNo)
{
  this->pixels.set(pixel, indexNo);
}

Pixels::RGBAPixel Pixels::RGBAPixelArray::at(int rowNo, int columnNo) const
{
  return this->pixels.at(rowNo, columnNo);
}

Pixels::RGBAPixel Pixels::RGBAPixelArray::at(int indexNo) const
{
  return this->pixels.at(indexNo);
}

int Pixels::RGBAPixelArray::sizeInPixels() const
{
  return this->pixels.width() * this->pixels.height();
}