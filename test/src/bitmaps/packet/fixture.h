#ifndef BITMAP_PACKET_TEST_H
#define BITMAP_PACKET_TEST_H

#include "src/bitmaps/packet/packet.h"
#include "src/bitmaps/packet/headers/headers.h"
#include "src/bitmaps/formats/format.h"
#include "src/bitmaps/packet/pixel-array/array.h"
#include "src/bitmaps/packet/pixel-array/colours.h"
#include "test/src/bitmaps/fixtures/test.h"

class BitmapPacketTest : public BitmapTest
{
public:
  BitmapPacketTest();
  ~BitmapPacketTest();

protected:
  void loadRedPixelArray();
  Bitmaps::Colours redColours();
  Bitmaps::Colours greenColours();
};

#endif