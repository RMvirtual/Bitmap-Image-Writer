#pragma once

#include <memory>
#include "gtest/gtest.h"
#include "src/main/cpp/bitmaps/packet/packet.h"

class PixelArrayTest : public testing::Test
{
public:
  PixelArrayTest();
  ~PixelArrayTest();

protected:
  Bitmaps::PixelArray pixelArray;
  
  void isGreen(Bitmaps::Colours& colour);
  void setupRedPixelArray(int width, int height);
  Bitmaps::Colours redColours();
  Bitmaps::Colours greenColours();
};