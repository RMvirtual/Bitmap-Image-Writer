#pragma once

#include <gtest/gtest.h>

#include "src/main/cpp/bitmaps/formats/format/format.h"
#include "src/main/cpp/bitmaps/packet/headers/headers.h"
#include "src/main/cpp/bitmaps/packet/headers/file-header/header.h"
#include "src/main/cpp/bitmaps/packet/headers/dib-header/header.h"
#include "src/main/cpp/bitmaps/formats/colours/colours.h"

class BitmapFormatsTest : public testing::Test
{
public:
  BitmapFormatsTest();
  ~BitmapFormatsTest();

protected:
  Bitmaps::Format format;
  Bitmaps::Colours colours;

  void setupRGBAFormat();
  void setupRGBFormat();
  void setupRGBFormat(int width, int height);
  void setupRGBColours();

  void compare(Bitmaps::Format& format);
  void compareNames(Bitmaps::Format& format);
  void compareBitsPerPixel(Bitmaps::Format& format);
  void compareColours(Bitmaps::Format& format);
  
  Bitmaps::Headers rgbHeaders();
  Bitmaps::FileHeader rgbFileHeader();
  Bitmaps::DibHeader rgbDibHeader();
};