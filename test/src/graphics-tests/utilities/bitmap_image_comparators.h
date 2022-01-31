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
    const Bitmaps::FileHeader& header1, 
    const Bitmaps::FileHeader& header2
  );

  void compare(
    const Bitmaps::DibHeader& header1,
    const Bitmaps::DibHeader& header2
  );
  
  void compare(Bitmaps::PixelArray& array1, Bitmaps::PixelArray& array2);
  void compare(Bitmaps::Colours& colours1, Bitmaps::Colours& colours2);
  void isGreen(Bitmaps::Colours& pixel);
  void isRed(Bitmaps::Colours& pixel);
}

#endif