#ifndef BITMAP_IMAGE_COMPARATORS_H
#define BITMAP_IMAGE_COMPARATORS_H

#include <gtest/gtest.h>
#include "src/graphics/bitmaps/packet/headers/file-header/file_header.h"
#include "src/graphics/bitmaps/packet/headers/dib-header/dib_header.h"
#include "src/graphics/bitmaps/packet/pixel-array/pixel_array.h"
#include "src/graphics/bitmaps/packet/pixel-array/pixel.h"
#include "src/graphics/bitmaps/packet/pixel-array/colours/rgb_colours.h"

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
    const Pixels::PixelArray <Pixels::Pixel<Pixels::RGBColours>>& pixelArray1,
    const Pixels::PixelArray <Pixels::Pixel<Pixels::RGBColours>>& pixelArray2
  );

  void comparePixels(
    const Pixels::Pixel<Pixels::RGBColours>& pixel1,
    const Pixels::Pixel<Pixels::RGBColours>& pixel2
  );

  void compareColours(
    const Pixels::RGBColours& colours1,
    const Pixels::RGBColours& colours2
  );

  void isGreenPixel(Pixels::Pixel<Pixels::RGBColours>& pixel);
  void isRedPixel(Pixels::Pixel<Pixels::RGBColours>& pixel);
}

#endif