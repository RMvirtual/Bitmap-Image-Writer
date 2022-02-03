#ifndef BITMAP_FORMATS_TEST_H
#define BITMAP_FORMATS_TEST_H

#include <gtest/gtest.h>

#include "src/bitmaps/formats/format.h"
#include "src/bitmaps/packet/headers/headers.h"
#include "src/bitmaps/packet/headers/file-header/header.h"
#include "src/bitmaps/packet/headers/dib-header/header.h"

class BitmapFormatsTest : public ::testing::Test
{
public:
  BitmapFormatsTest();
  ~BitmapFormatsTest();

protected:
  Bitmaps::Format format;

  void BitmapFormatsTest::compare(Bitmaps::Format& format);
  void loadRGBAFormat();
  void loadRGBFormat();
  void loadRGBFormat(int width, int height);
  Bitmaps::Headers rgbHeaders();
  Bitmaps::FileHeader rgbFileHeader();
  Bitmaps::DibHeader rgbDibHeader();
};

#endif