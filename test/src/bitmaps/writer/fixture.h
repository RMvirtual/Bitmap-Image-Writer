#ifndef BITMAP_WRITER_TEST_H
#define BITMAP_WRITER_TEST_H

#include <gtest/gtest.h>

#include "src/bitmaps/writer/writer.h"
#include "src/containers/byte-array/byte_conversion.h"

class BitmapWriterTest : public ::testing::Test
{
public:
  BitmapWriterTest();
  ~BitmapWriterTest();

  void loadBluePixelFileHeader();
  void loadBluePixelDibHeader();
  void loadBluePixelArray();

protected:
  Bitmaps::ImageWriter writer;

  void compare(std::string twoChars, ByteArray bytes);
  void compare(uint16_t integer, ByteArray bytes);
  void compare(uint32_t integer, ByteArray bytes);
};

#endif