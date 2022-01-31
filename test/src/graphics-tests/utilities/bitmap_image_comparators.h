#ifndef BITMAP_IMAGE_COMPARATORS_H
#define BITMAP_IMAGE_COMPARATORS_H

#include <gtest/gtest.h>
#include "src/graphics/bitmaps/packet/headers/file-header/header.h"
#include "src/graphics/bitmaps/packet/headers/dib-header/header.h"
#include "src/graphics/bitmaps/packet/pixel-array/array.h"
#include "src/graphics/bitmaps/packet/pixel-array/colours.h"
#include "src/graphics/bitmaps/formats/format.h"

namespace BitmapImageComparison
{
  void compare(
    const BitmapHeaders::FileHeader& header1, 
    const BitmapHeaders::FileHeader& header2
  );

  void compare(
    const BitmapHeaders::DibHeader& header1,
    const BitmapHeaders::DibHeader& header2
  );
  
  void compare(Pixels::Array& array1, Pixels::Array& array2);
  void compare(Pixels::Colours& colours1, Pixels::Colours& colours2);
  void isGreen(Pixels::Colours& pixel);
  void isRed(Pixels::Colours& pixel);
}

#endif