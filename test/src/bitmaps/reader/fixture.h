#include <gtest/gtest.h>

#include "src/bitmaps/image/image.h"
#include "src/bitmaps/reader/image/reader.h"

class BitmapReaderTest : public testing::Test
{
public:
  BitmapReaderTest();
  ~BitmapReaderTest();

private:
  void setupCorrectImage();
  void setupFileHeader();
  void setupDibHeader();
  void setupPixelArray();
  void setupColours();

protected:
  Bitmaps::Image image;
  Bitmaps::ImageReader reader {};
  ByteArray fileContents;
  
  std::string blueImagePath();

  void compare(const Bitmaps::Image image);
  void compare(const Bitmaps::FileHeader& header);
  void compare(const Bitmaps::DibHeader& header);
  void compare(Bitmaps::PixelArray& array);
};