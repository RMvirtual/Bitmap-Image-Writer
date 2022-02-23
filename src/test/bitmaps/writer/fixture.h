#ifndef BITMAP_WRITER_TEST_H
#define BITMAP_WRITER_TEST_H

#include <gtest/gtest.h>
#include <string>

#include "src/main/bitmaps/writer/image/writer.h"
#include "src/main/containers/byte-array/byte_array.h"

class BitmapWriterTest : public testing::Test
{
public:
  BitmapWriterTest();
  ~BitmapWriterTest();

protected:
  std::string filePath;
  Bitmaps::Image image;
  Bitmaps::ImageWriter writer;

  void setup1x4Image();
  void setup2x2Image();
  void setup3x5Image();
  void setupBlueRGBImage(int widthInPixels, int heightInPixels);

  void compareWrittenFile();
  void compare(const Bitmaps::FileHeader& header);
  void compare(const Bitmaps::DibHeader& header);
  void compare(const Bitmaps::PixelArray& pixelArray);
  void compare(
    const Bitmaps::Colours& correctColours, const Bitmaps::Colours& colours);  

private:
  void setOutputFilePath(std::string fileName);
};

#endif