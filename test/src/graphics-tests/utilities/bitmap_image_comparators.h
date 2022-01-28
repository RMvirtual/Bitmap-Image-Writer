#ifndef BITMAP_IMAGE_COMPARATORS_H
#define BITMAP_IMAGE_COMPARATORS_H

#include <gtest/gtest.h>
#include "src/graphics/bitmaps/packet/headers/file-header/header.h"
#include "src/graphics/bitmaps/packet/headers/dib-header/header.h"
#include "src/graphics/bitmaps/packet/pixel-array/array/array.h"
#include "src/graphics/bitmaps/packet/pixel-array/pixel/pixel.h"
#include "src/graphics/bitmaps/packet/pixel-array/pixel/format.h"

namespace BitmapImageComparison
{
  void compareBitmapFileHeaders(
    const BitmapHeaders::FileHeader& header1, 
    const BitmapHeaders::FileHeader& header2
  );

  void compareBitmapDibHeaders(
    const BitmapHeaders::DibHeader& header1,
    const BitmapHeaders::DibHeader& header2
  );
  
  void comparePixelArrays(
    const Pixels::Array& array1, const Pixels::Array& array2);

  void comparePixels(const Pixels::Pixel& pixel1, const Pixels::Pixel& pixel2);
  void compareColours(Pixels::Colours& colours1, Pixels::Colours& colours2);
  void isGreenPixel(const Pixels::Pixel& pixel);
  void isRedPixel(const Pixels::Pixel& pixel);
}

#endif