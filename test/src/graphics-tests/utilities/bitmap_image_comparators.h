#ifndef BITMAP_IMAGE_COMPARATORS_H
#define BITMAP_IMAGE_COMPARATORS_H

#include <gtest/gtest.h>
#include "src/graphics/bitmaps/packet/headers/file-header/file_header.h"
#include "src/graphics/bitmaps/packet/headers/dib-header/dib_header.h"
#include "src/graphics/bitmaps/packet/pixel-array/rgb/rgb_pixel_array.h"

namespace BitmapImageComparison
{
  void compareBitmapFileHeaders(
    const BitmapHeaders::FileHeader& header1, 
    const BitmapHeaders::FileHeader& header2);

  void compareBitmapDibHeaders(
    const BitmapHeaders::DibHeader& header1,
    const BitmapHeaders::DibHeader& header2);

  void comparePixelArrayAttributes(
      const Pixels::RGBPixelArray& pixelArray1,
      const Pixels::RGBPixelArray& pixelArray2);

  void comparePixelArrayContents(
    const Pixels::RGBPixelArray& pixelArray1,
    const Pixels::RGBPixelArray& pixelArray2);
  
  void comparePixelArrays(
    const Pixels::RGBPixelArray& pixelArray1,
    const Pixels::RGBPixelArray& pixelArray2);

  void comparePixels(
    const Pixels::RGBPixel& pixel1,
    const Pixels::RGBPixel& pixel2);

  void compareColours(
    const Pixels::RGBColours& colours1,
    const Pixels::RGBColours& colours2);

  void isGreenPixel(Pixels::RGBPixel pixel);
  void isRedPixel(Pixels::RGBPixel pixel);
}

#endif