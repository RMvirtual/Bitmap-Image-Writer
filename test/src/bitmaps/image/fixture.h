#ifndef BITMAP_IMAGE_TEST_H
#define BITMAP_IMAGE_TEST_H

#include <gtest/gtest.h>
#include "src/bitmaps/image/image.h"

class BitmapImageTest : public testing::Test
{
public:
  BitmapImageTest();
  ~BitmapImageTest();

protected:
  Bitmaps::Image image;
  Bitmaps::Format format;

  void setupRGBFormat();
  Bitmaps::Colours getBlueColours();
};

#endif