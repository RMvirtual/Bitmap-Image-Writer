#include <gtest/gtest.h>

#include "src/bitmaps/reader/bitmap_reader.h"

class BitmapReaderTest : public testing::Test
{
public:
  BitmapReaderTest();
  ~BitmapReaderTest();

private:
  void initialiseCorrectPacket();

protected:
  Bitmaps::Packet packet;
  Bitmaps::ImageReader reader {};

  void compare(const Bitmaps::FileHeader& header);
  void compare(const Bitmaps::DibHeader& header);
  void compare(Bitmaps::PixelArray& array);

  Bitmaps::Packet readBlueFile();
  std::string blueImagePath();
  void loadCorrectFileHeader();
  void loadCorrectDibHeader();
  void loadCorrectPixelArray();
  void loadBlueColours();
  void loadBlueColoursWithAlpha();
};