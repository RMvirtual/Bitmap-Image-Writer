#include "src/bitmaps/packet/packet.h"
#include "src/bitmaps/reader/bitmap_reader.h"
#include "test/src/bitmaps/fixtures/test.h"

class BitmapReaderTest : public BitmapTest
{
public:
  BitmapReaderTest();
  ~BitmapReaderTest();

protected:
  Bitmaps::ImageReader reader {};

  Bitmaps::Packet readPacket();
};