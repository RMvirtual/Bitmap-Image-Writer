#ifndef BITMAP_TEST
#define BITMAP_TEST

#include <gtest/gtest.h>

#include "src/bitmaps/packet/headers/file-header/header.h"
#include "src/bitmaps/packet/headers/dib-header/header.h"
#include "src/bitmaps/packet/pixel-array/array.h"
#include "src/bitmaps/packet/pixel-array/colours.h"
#include "src/bitmaps/formats/format.h"

class BitmapTest : public ::testing::Test
{
public:
  BitmapTest();
  ~BitmapTest();

protected:
  Bitmaps::FileHeader fileHeader;
  Bitmaps::DibHeader dibHeader;
  Bitmaps::PixelArray pixelArray;
  Bitmaps::Colours colours;
  Bitmaps::Format format;

  void compare(const Bitmaps::FileHeader& header);
  void compare(const Bitmaps::DibHeader& header);
  void compare(Bitmaps::PixelArray& array);
  void compare(Bitmaps::Colours& correctColours, Bitmaps::Colours& colours);
  void compare(Bitmaps::Format& format);
  void isGreen(Bitmaps::Colours& colour);
  void isRed(Bitmaps::Colours& colour);
};

#endif