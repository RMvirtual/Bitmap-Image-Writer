#include <gtest/gtest.h>

#include "src/graphics/bitmaps/writer/writer.h"
#include "src/graphics/bitmaps/packet/headers/file_header.h"
#include "test/src/graphics-tests/utilities/bitmap_set_up.h"

TEST(BitmapHeaderWriterTests, ShouldWriteFileHeaderToByteArray)
{ 
  BitmapHeaders::FileHeader header = BitmapSetUp::setUpBluePixelFileHeader();
  BitmapWriter writer {};
  ByteArray bytes = writer.writeFileHeader(header);

  // Signature bytes.
  EXPECT_EQ(header.getSignatureBytes()[0], bytes[0].value);
  EXPECT_EQ(header.getSignatureBytes()[1], bytes[1].value);

  // Bitmap file size.
  EXPECT_EQ(
    (unsigned char) (header.getSizeOfBitmapFile()), bytes[2].value);

  EXPECT_EQ(
    (unsigned char) (header.getSizeOfBitmapFile() >> 8), bytes[3].value);

  EXPECT_EQ(
    (unsigned char) (header.getSizeOfBitmapFile() >> 16), bytes[4].value);

  EXPECT_EQ(
    (unsigned char) (header.getSizeOfBitmapFile() >> 24), bytes[5].value);

  // Bitmap reserved bytes.
  EXPECT_EQ(
    (unsigned char) (header.getReservedBytes()), bytes[6].value);

  EXPECT_EQ(
    (unsigned char) (header.getReservedBytes() >> 8), bytes[7].value);

  EXPECT_EQ(
    (unsigned char) (header.getReservedBytes() >> 16), bytes[8].value);

  EXPECT_EQ(
    (unsigned char) (header.getReservedBytes() >> 24), bytes[9].value);

  // Bitmap pixel data offset value.
  EXPECT_EQ(
    (unsigned char) (header.getPixelDataOffset()), bytes[10].value);
  
  EXPECT_EQ(
    (unsigned char) (header.getPixelDataOffset() >> 8), bytes[11].value);
  
  EXPECT_EQ(
    (unsigned char) (header.getPixelDataOffset() >> 16), bytes[12].value);
  
  EXPECT_EQ(
    (unsigned char) (header.getPixelDataOffset() >> 24), bytes[13].value);
}