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
    const BitmapHeaders::FileHeader& header1, 
    const BitmapHeaders::FileHeader& header2);

  void compareBitmapDibHeaders(
    const BitmapHeaders::DibHeader& header1,
    const BitmapHeaders::DibHeader& header2);

  void comparePixelArrayAttributes(
      const Pixels::PixelArray& pixelArray1,
      const Pixels::PixelArray& pixelArray2);

  void comparePixelArrayContents(
    const Pixels::PixelArray& pixelArray1,
    const Pixels::PixelArray& pixelArray2);
  
  void comparePixelArrays(
    const Pixels::PixelArray& pixelArray1,
    const Pixels::PixelArray& pixelArray2);
  
  void compareBitmapImages(
    const BitmapImage& image1,
    const BitmapImage& image2);
}

#endif