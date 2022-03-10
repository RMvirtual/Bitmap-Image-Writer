#pragma once

#include <memory>
#include "gtest/gtest.h"
#include "src/main/cpp/bitmaps/packet/packet.h"

class BitmapPacketTest : public testing::Test
{
public:
  BitmapPacketTest();
  ~BitmapPacketTest();

protected:
  std::shared_ptr<Bitmaps::PixelArray> pixelArray;
  
  void isGreen(Bitmaps::Colours& colour);
  void setupRedPixelArray();
  Bitmaps::Colours redColours();
  Bitmaps::Colours greenColours();
};