#ifndef BITMAP_PACKET_TEST_H
#define BITMAP_PACKET_TEST_H

#include <gtest/gtest.h>

#include "src/bitmaps/packet/packet.h"
#include "src/bitmaps/packet/headers/headers.h"
#include "src/bitmaps/formats/format.h"
#include "src/bitmaps/packet/pixel-array/array.h"
#include "src/bitmaps/packet/pixel-array/colours.h"

class BitmapPacketTest : public testing::Test
{
public:
  BitmapPacketTest();
  ~BitmapPacketTest();

protected:
  Bitmaps::PixelArray pixelArray;
  
  void isGreen(Bitmaps::Colours& colour);
  void loadRedPixelArray();
  Bitmaps::Colours redColours();
  Bitmaps::Colours greenColours();
};

#endif