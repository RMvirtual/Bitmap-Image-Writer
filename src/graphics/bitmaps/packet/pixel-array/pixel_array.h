#ifndef PIXEL_ARRAY_H
#define PIXEL_ARRAY_H

#include "src/common/matrix-2D/matrix_2d.h"
#include "src/graphics/bitmaps/packet/pixel-array/rgba/rgba_pixel.h"
#include "src/graphics/bitmaps/packet/pixel-array/rgba/rgba_pixel_array_values.h"
#include "src/graphics/bitmaps/packet/pixel-array/rgb/rgb_pixel_array_values.h"
#include "src/graphics/bitmaps/packet/pixel-array/rgb/rgb_pixel.h"
#include "src/graphics/bitmaps/packet/pixel-array/pixel_array_types.h"

namespace Pixels {
template<PixelTypes T>
class PixelArray
{
public:
  PixelArray();
  PixelArray(const RGBPixelArrayValues& values);

  void set(const RGBPixel& pixel, int rowNo, int columnNo);
  void set(const RGBPixel& pixel, int indexNo);
  RGBPixel at(int rowNo, int columnNo) const;
  RGBPixel at(int indexNo) const;
  int sizeInPixels() const;

private:
  Common::Matrix2D<RGBPixel> pixels {0, 0, {}};
};

template<>
class PixelArray <PixelTypes::RGBA> 
{
public:
  PixelArray();
  PixelArray(const RGBAPixelArrayValues& values);

  void set(const RGBAPixel& pixel, int rowNo, int columnNo);
  void set(const RGBAPixel& pixel, int indexNo);
  RGBAPixel at(int rowNo, int columnNo) const;
  RGBAPixel at(int indexNo) const;
  int sizeInPixels() const;

private:
  Common::Matrix2D<RGBAPixel> pixels {0, 0, {}};
};}

template <Pixels::PixelTypes T>
Pixels::PixelArray<T>::PixelArray()
{
  // pass.
}

template <Pixels::PixelTypes T>
Pixels::PixelArray<T>::PixelArray(const Pixels::RGBPixelArrayValues& values)
{
  this->pixels = {
    values.widthInPixels, values.heightInPixels, values.defaultPixel};
}

template <Pixels::PixelTypes T>
void Pixels::PixelArray<T>::set(
  const Pixels::RGBPixel& pixel, int rowNo, int columnNo)
{
  this->pixels.set(pixel, rowNo, columnNo);
}

template <Pixels::PixelTypes T>
void Pixels::PixelArray<T>::set(const Pixels::RGBPixel& pixel, int indexNo)
{
  this->pixels.set(pixel, indexNo);
}

template <Pixels::PixelTypes T>
Pixels::RGBPixel Pixels::PixelArray<T>::at(int rowNo, int columnNo) const
{
  return this->pixels.at(rowNo, columnNo);
}

template <Pixels::PixelTypes T>
Pixels::RGBPixel Pixels::PixelArray<T>::at(int indexNo) const
{
  return this->pixels.at(indexNo);
}

template <Pixels::PixelTypes T>
int Pixels::PixelArray<T>::sizeInPixels() const
{
  return this->pixels.width() * this->pixels.height();
}

Pixels::PixelArray<Pixels::PixelTypes::RGBA>::PixelArray()
{
  // pass.
}

Pixels::PixelArray<Pixels::PixelTypes::RGBA>::PixelArray(
  const Pixels::RGBAPixelArrayValues& values)
{
  this->pixels = {
    values.widthInPixels, values.heightInPixels, values.defaultPixel};
}

void Pixels::PixelArray<Pixels::PixelTypes::RGBA>::set(
  const Pixels::RGBAPixel& pixel, int rowNo, int columnNo)
{
  this->pixels.set(pixel, rowNo, columnNo);
}

void Pixels::PixelArray<Pixels::PixelTypes::RGBA>::set(
  const Pixels::RGBAPixel& pixel, int indexNo)
{
  this->pixels.set(pixel, indexNo);
}

Pixels::RGBAPixel Pixels::PixelArray<Pixels::PixelTypes::RGBA>::at(
  int rowNo, int columnNo) const
{
  return this->pixels.at(rowNo, columnNo);
}

Pixels::RGBAPixel Pixels::PixelArray<Pixels::PixelTypes::RGBA>::at(
  int indexNo) const
{
  return this->pixels.at(indexNo);
}

int Pixels::PixelArray<Pixels::PixelTypes::RGBA>::sizeInPixels() const
{
  return this->pixels.width() * this->pixels.height();
}

#endif