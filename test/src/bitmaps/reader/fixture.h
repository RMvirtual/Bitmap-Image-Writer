#include "src/bitmaps/packet/packet.h"
#include "src/bitmaps/reader/bitmap_reader.h"
#include "test/src/bitmaps/fixtures/test.h"

class BitmapReaderTest : public BitmapTest
{
public:
  BitmapReaderTest();
  ~BitmapReaderTest();

private:
  void initialiseFileHeader();
  void initialiseDibHeader();
  void initialisePixelArray();
  void initialiseColours();

protected:
  Bitmaps::ImageReader reader {};

  Bitmaps::Packet readPacket();
  std::string blueImagePath();
  Bitmaps::Packet blueBitmapPacket();
  Bitmaps::Headers bluePixelHeaders();
  void loadBluePixelFileHeader();
  void loadBluePixelDibHeader();
  void loadBluePixelArray();
  void loadBluePixelArray(int width, int height);
  void loadBlueColours();
  void loadBlueColoursWithAlpha();
  void loadWhiteColours();

};