#ifndef BITMAP_PACKET_TEST_H
#define BITMAP_PACKET_TEST_H

#include <gtest/gtest.h>

#include "src/bitmaps/packet/packet.h"
#include "src/bitmaps/packet/headers/headers.h"
#include "src/bitmaps/formats/bitmap/format.h"
#include "src/bitmaps/packet/pixel-array/array.h"
#include "src/bitmaps/formats/colours/colours.h"

class BitmapPacketTest : public testing::Test
{
public:
  BitmapPacketTest();
  ~BitmapPacketTest();

protected:
  Bitmaps::PixelArray pixelArray;
  
  void isGreen(Bitmaps::Colours& colour);
  void setupRedPixelArray();
  Bitmaps::Colours redColours();
  Bitmaps::Colours greenColours();
};

#endif