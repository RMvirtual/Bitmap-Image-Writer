#include "src/bitmaps/packet/packet.h"
#include "src/bitmaps/reader/bitmap_reader.h"
#include "src/bitmaps/formats/formats.h"
#include "test/src/bitmaps/reader/fixture.h"

BitmapReaderTest::BitmapReaderTest()
{

}

BitmapReaderTest::~BitmapReaderTest()
{

}

Bitmaps::Packet BitmapReaderTest::readPacket()
{
  return reader.read(this->blueImagePath());
}
