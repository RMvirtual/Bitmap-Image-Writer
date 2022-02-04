#ifndef BITMAP_WRITER_TEST_H
#define BITMAP_WRITER_TEST_H

#include <gtest/gtest.h>

#include "src/bitmaps/writer/writer.h"
#include "src/containers/byte-array/byte_array.h"

class BitmapWriterTest : public testing::Test
{
public:
  BitmapWriterTest();
  ~BitmapWriterTest();

private:
  void setupFileHeader();
  void setupDibHeader();
  void setupPixelArray();
  void setupColours();

protected:
  Bitmaps::Packet packet;
  Bitmaps::ImageWriter writer;
  Bitmaps::Colours colours;

  ByteArray writeBlueFile();

  void compare(std::string twoChars, ByteArray bytes);
  void compare(uint16_t integer, ByteArray bytes);
  void compare(uint32_t integer, ByteArray bytes);
  void compareToFileHeader(ByteArray& bytes);
  void compareToDibHeader(ByteArray& bytes);
  void compareToPixelArray(ByteArray& bytes);

};

#endif