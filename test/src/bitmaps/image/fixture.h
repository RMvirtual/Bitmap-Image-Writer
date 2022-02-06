#ifndef BITMAP_IMAGE_TEST_H
#define BITMAP_IMAGE_TEST_H

#include <gtest/gtest.h>
#include <string>

#include "src/bitmaps/image/image.h"
#include "src/bitmaps/packet/packet.h"

class BitmapImageTest : public testing::Test
{
public:
  BitmapImageTest();
  ~BitmapImageTest();

protected:
  Bitmaps::Image image;
  Bitmaps::Format format;
  std::string filePath;

  void setupRGBFormat(int widthInPixels, int heightInPixels);
  void setup2x2Image();
  void setup1x4Image();
  void setup3x5Image();
  Bitmaps::Colours getBlueColours();

  void compareWrittenFile();
  void compare(const Bitmaps::FileHeader& header);
  void compare(const Bitmaps::DibHeader& header);
  void compare(const Bitmaps::PixelArray& pixelArray);
  void compare(
    const Bitmaps::Colours& correctColours, const Bitmaps::Colours& colours);  
};

#endif