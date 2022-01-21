#ifndef PIXEL_ARRAY_H
#define PIXEL_ARRAY_H

#include "src/common/matrix-2D/matrix_2d.h"
#include "src/graphics/bitmaps/packet/pixel-array/rgba/rgba_pixel.h"
#include "src/graphics/bitmaps/packet/pixel-array/rgba/rgba_pixel_array_values.h"
#include "src/graphics/bitmaps/packet/pixel-array/rgb/rgb_pixel_array_values.h"
#include "src/graphics/bitmaps/packet/pixel-array/rgb/rgb_pixel.h"
#include "src/graphics/bitmaps/packet/pixel-array/pixel_array_values.h"

namespace Pixels
{
  template <class PixelType>
  class PixelArray
  {
  public:
    PixelArray();
    PixelArray(const PixelArrayValues<PixelType>& values);

    void set(const PixelType& pixel, int rowNo, int columnNo);
    void set(const PixelType& pixel, int indexNo);
    PixelType at(int rowNo, int columnNo) const;
    PixelType at(int indexNo) const;
    int sizeInPixels() const;

  private:
    Common::Matrix2D<PixelType> pixels {0, 0, {}};
};}

template <class PixelType>
Pixels::PixelArray <PixelType> ::PixelArray()
{
  // pass.
}

template <class PixelType>
Pixels::PixelArray <PixelType> ::PixelArray(
  const Pixels::PixelArrayValues<PixelType>& values)
{
  this->pixels = {
    values.widthInPixels, values.heightInPixels, values.defaultPixel};
}

template <class PixelType>
void Pixels::PixelArray <PixelType> ::set(
  const PixelType& pixel, int rowNo, int columnNo)
{
  this->pixels.set(pixel, rowNo, columnNo);
}

template <class PixelType>
void Pixels::PixelArray <PixelType> ::set(const PixelType& pixel, int indexNo)
{
  this->pixels.set(pixel, indexNo);
}

template <class PixelType>
PixelType Pixels::PixelArray<PixelType>::at(int rowNo, int columnNo) const
{
  return this->pixels.at(rowNo, columnNo);
}

template <class PixelType>
PixelType Pixels::PixelArray<PixelType>::at(int indexNo) const
{
  return this->pixels.at(indexNo);
}

template <class PixelType>
int Pixels::PixelArray <PixelType> ::sizeInPixels() const
{
  return this->pixels.width() * this->pixels.height();
}

#endif