#ifndef BITMAP_FORMATS_TEST_H
#define BITMAP_FORMATS_TEST_H

#include <gtest/gtest.h>

#include "src/bitmaps/formats/format.h"
#include "src/bitmaps/packet/headers/headers.h"
#include "src/bitmaps/packet/headers/file-header/header.h"
#include "src/bitmaps/packet/headers/dib-header/header.h"
#include "src/bitmaps/formats/colours.h"

class BitmapFormatsTest : public testing::Test
{
public:
  BitmapFormatsTest();
  ~BitmapFormatsTest();

protected:
  Bitmaps::Format format;
  Bitmaps::Colours colours;

  void compare(Bitmaps::Format& format);
  void compareNames(Bitmaps::Format& format);
  void compareBitsPerPixel(Bitmaps::Format& format);
  void compareColours(Bitmaps::Format& format);
  
  void loadRGBAFormat();
  void loadRGBFormat();
  void loadRGBFormat(int width, int height);
  void loadColours();

  Bitmaps::Headers rgbHeaders();
  Bitmaps::FileHeader rgbFileHeader();
  Bitmaps::DibHeader rgbDibHeader();
};

#endif