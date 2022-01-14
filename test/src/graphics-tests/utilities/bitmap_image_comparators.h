#ifndef BITMAP_IMAGE_COMPARATORS_H
#define BITMAP_IMAGE_COMPARATORS_H

#include <gtest/gtest.h>
#include "src/graphics/bitmaps/packet/headers/file-header/file_header.h"
#include "src/graphics/bitmaps/packet/headers/dib-header/dib_header.h"
#include "src/graphics/bitmaps/packet/pixel-array/arrays/pixel_array.h"
#include "src/graphics/bitmaps/bitmap_image.h"

namespace BitmapImageComparison
{
  void compareBitmapFileHeaders(
    BitmapHeaders::FileHeader header1, BitmapHeaders::FileHeader header2);

  void compareBitmapDibHeaders(
    BitmapHeaders::DibHeader header1, BitmapHeaders::DibHeader header2);

  void comparePixelArrayAttributes(
      Pixels::PixelArray pixelArray1, Pixels::PixelArray pixelArray2);

  void comparePixelArrayContents(
    Pixels::PixelArray pixelArray1, Pixels::PixelArray pixelArray2);
  
  void comparePixelArrays(
    Pixels::PixelArray pixelArray1, Pixels::PixelArray pixelArray2);
  
  void compareBitmapImages(BitmapImage image1, BitmapImage image2);
}

#endif