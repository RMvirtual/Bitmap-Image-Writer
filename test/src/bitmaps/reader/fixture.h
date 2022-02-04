#include <gtest/gtest.h>

#include "src/bitmaps/reader/bitmap_reader.h"

class BitmapReaderTest : public testing::Test
{
public:
  BitmapReaderTest();
  ~BitmapReaderTest();

private:
  void setupCorrectPacket();
  void setupFileHeader();
  void setupDibHeader();
  void setupPixelArray();
  void setupColours();

protected:
  Bitmaps::Packet packet;
  Bitmaps::ImageReader reader {};
  ByteArray fileContents;
  
  std::string blueImagePath();

  void compare(const Bitmaps::FileHeader& header);
  void compare(const Bitmaps::DibHeader& header);
  void compare(Bitmaps::PixelArray& array);
};