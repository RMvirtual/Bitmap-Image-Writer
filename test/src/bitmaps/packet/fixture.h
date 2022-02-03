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

private:
  void initialiseFileHeader();
  void initialiseDibHeader();
  void initialisePixelArray();
  void initialiseColours();

protected:
  std::string blueImagePath();
  Bitmaps::Packet blueBitmapPacket();
  Bitmaps::Headers bluePixelHeaders();
  Bitmaps::FileHeader bluePixelFileHeader();
  Bitmaps::DibHeader bluePixelDibHeader();
  Bitmaps::PixelArray bluePixelArray();
  Bitmaps::PixelArray bluePixelArray(int width, int height);
  void loadRedPixelArray();
  Bitmaps::Colours redColours();
  Bitmaps::Colours greenColours();
  Bitmaps::Colours blueColours();
  Bitmaps::Colours blueColoursWithAlpha();
  Bitmaps::Colours whiteColours();
};

#endif