#include <gtest/gtest.h>

#include "src/graphics/bitmaps/writer/writer.h"
#include "src/common/byte-array/byte_array.h"
#include "src/graphics/bitmaps/packet/pixel-array/pixels/colours/rgb_colours.h"
#include "src/graphics/bitmaps/packet/headers/file-header/file_header.h"
#include "test/src/graphics-tests/utilities/bitmap_set_up.h"

TEST(BitmapWriterTests, ShouldWriteFileHeaderToByteArray)
{ 
  BitmapHeaders::FileHeader header = BitmapSetUp::setUpBluePixelFileHeader();
  BitmapWriter writer {};
  ByteArray bytes = writer.writeFileHeader(header);

  // Signature bytes.
  EXPECT_EQ(header.signatureBytes()[0], bytes[0].value);
  EXPECT_EQ(header.signatureBytes()[1], bytes[1].value);

  // Bitmap file size.
  EXPECT_EQ(
    (unsigned char) (header.sizeOfBitmapFile()), bytes[2].value);

  EXPECT_EQ(
    (unsigned char) (header.sizeOfBitmapFile() >> 8), bytes[3].value);

  EXPECT_EQ(
    (unsigned char) (header.sizeOfBitmapFile() >> 16), bytes[4].value);

  EXPECT_EQ(
    (unsigned char) (header.sizeOfBitmapFile() >> 24), bytes[5].value);

  // Bitmap reserved bytes.
  EXPECT_EQ(
    (unsigned char) (header.reservedBytes()), bytes[6].value);

  EXPECT_EQ(
    (unsigned char) (header.reservedBytes() >> 8), bytes[7].value);

  EXPECT_EQ(
    (unsigned char) (header.reservedBytes() >> 16), bytes[8].value);

  EXPECT_EQ(
    (unsigned char) (header.reservedBytes() >> 24), bytes[9].value);

  // Bitmap pixel data offset value.
  EXPECT_EQ(
    (unsigned char) (header.pixelDataOffset()), bytes[10].value);
  
  EXPECT_EQ(
    (unsigned char) (header.pixelDataOffset() >> 8), bytes[11].value);
  
  EXPECT_EQ(
    (unsigned char) (header.pixelDataOffset() >> 16), bytes[12].value);
  
  EXPECT_EQ(
    (unsigned char) (header.pixelDataOffset() >> 24), bytes[13].value);
}

TEST(BitmapWriterTests, ShouldWriteDibHeaderToByteArray)
{ 
  BitmapHeaders::DibHeader header = BitmapSetUp::setUpBluePixelDibHeader();
  BitmapWriter writer {};
  ByteArray bytes = writer.writeDibHeader(header);

  // Header size in bytes.
  EXPECT_EQ(
    (unsigned char) (header.headerSizeInBytes()), bytes[0].value);

  EXPECT_EQ(
    (unsigned char) (header.headerSizeInBytes() >> 8), bytes[1].value);

  EXPECT_EQ(
    (unsigned char) (header.headerSizeInBytes() >> 16), bytes[2].value);

  EXPECT_EQ(
    (unsigned char) (header.headerSizeInBytes() >> 24), bytes[3].value);

  // Width in pixels.
  EXPECT_EQ(
    (unsigned char) (header.widthInPixels()), bytes[4].value);

  EXPECT_EQ(
    (unsigned char) (header.widthInPixels() >> 8), bytes[5].value);

  EXPECT_EQ(
    (unsigned char) (header.widthInPixels() >> 16), bytes[6].value);

  EXPECT_EQ(
    (unsigned char) (header.widthInPixels() >> 24), bytes[7].value);

  // Height in pixels.
  EXPECT_EQ(
    (unsigned char) (header.heightInPixels()), bytes[8].value);

  EXPECT_EQ(
    (unsigned char) (header.heightInPixels() >> 8), bytes[9].value);

  EXPECT_EQ(
    (unsigned char) (header.heightInPixels() >> 16), bytes[10].value);

  EXPECT_EQ(
    (unsigned char) (header.heightInPixels() >> 24), bytes[11].value);

  // Number of colour planes.
  EXPECT_EQ(
    (unsigned char) (header.numberOfColorPlanes()), bytes[12].value);

  EXPECT_EQ(
    (unsigned char) (header.numberOfColorPlanes() >> 8), bytes[13].value);

  // Colour depth.
  EXPECT_EQ(
    (unsigned char) (header.colorDepth()), bytes[14].value);

  EXPECT_EQ(
    (unsigned char) (header.colorDepth() >> 8), bytes[15].value);

  // Compression method.
  EXPECT_EQ(
    (unsigned char) (header.compressionMethod()), bytes[16].value);

  EXPECT_EQ(
    (unsigned char) (header.compressionMethod() >> 8), bytes[17].value);

  EXPECT_EQ(
    (unsigned char) (header.compressionMethod() >> 16), bytes[18].value);

  EXPECT_EQ(
    (unsigned char) (header.compressionMethod() >> 24), bytes[19].value);

  // Raw bitmap file size.
  EXPECT_EQ(
    (unsigned char) (header.rawBitmapDataSize()), bytes[20].value);

  EXPECT_EQ(
    (unsigned char) (header.rawBitmapDataSize() >> 8), bytes[21].value);

  EXPECT_EQ(
    (unsigned char) (header.rawBitmapDataSize() >> 16), bytes[22].value);

  EXPECT_EQ(
    (unsigned char) (header.rawBitmapDataSize() >> 24), bytes[23].value);

  // Horizontal pixels per metre.
  EXPECT_EQ(
    (unsigned char) (header.horizontalPixelsPerMetre()), bytes[24].value);

  EXPECT_EQ(
    (unsigned char) (header.horizontalPixelsPerMetre() >> 8), bytes[25].value);

  EXPECT_EQ(
    (unsigned char) (header.horizontalPixelsPerMetre() >> 16), bytes[26].value);

  EXPECT_EQ(
    (unsigned char) (header.horizontalPixelsPerMetre() >> 24), bytes[27].value);

  // Vertical pixels per metre.
  EXPECT_EQ(
    (unsigned char) (header.verticalPixelsPerMetre()), bytes[28].value);

  EXPECT_EQ(
    (unsigned char) (header.verticalPixelsPerMetre() >> 8), bytes[29].value);

  EXPECT_EQ(
    (unsigned char) (header.verticalPixelsPerMetre() >> 16), bytes[30].value);

  EXPECT_EQ(
    (unsigned char) (header.verticalPixelsPerMetre() >> 24), bytes[31].value);

  // Colour table entries.
  EXPECT_EQ(
    (unsigned char) (header.colorTableEntries()), bytes[32].value);

  EXPECT_EQ(
    (unsigned char) (header.colorTableEntries() >> 8), bytes[33].value);

  EXPECT_EQ(
    (unsigned char) (header.colorTableEntries() >> 16), bytes[34].value);

  EXPECT_EQ(
    (unsigned char) (header.colorTableEntries() >> 24), bytes[35].value);

  // Get important colours.
  EXPECT_EQ(
    (unsigned char) (header.importantColors()), bytes[36].value);

  EXPECT_EQ(
    (unsigned char) (header.importantColors() >> 8), bytes[37].value);

  EXPECT_EQ(
    (unsigned char) (header.importantColors() >> 16), bytes[38].value);

  EXPECT_EQ(
    (unsigned char) (header.importantColors() >> 24), bytes[39].value);
}

TEST(BitmapWriterTests, ShouldWritePixelArrayToByteArray)
{
  Pixels::PixelArray pixelArray = BitmapSetUp::setUpBluePixelArray();
  BitmapWriter writer {};
  ByteArray bytes = writer.writePixelArray(pixelArray);

  Pixels::RGBColours pixelRgbColours {};
  pixelRgbColours.setRed(100);
  pixelRgbColours.setGreen(255);
  pixelRgbColours.setBlue(255);

  int numberOfPixels = pixelArray.sizeInPixels();
  int numberOfBytes = bytes.size();

  // Row stride unaccounted for.
  // Only testing first 12 bytes for testing speed.
  for (int byteNo = 0; byteNo < 12; byteNo += 3) {
    Pixels::RGBPixel pixel = pixelArray.at(byteNo / 3);
    Pixels::RGBColours colours = pixel.getColours();

    EXPECT_EQ(colours.getBlue(), bytes[byteNo].value);
    EXPECT_EQ(colours.getGreen(), bytes[byteNo+1].value);
    EXPECT_EQ(colours.getRed(), bytes[byteNo+2].value);
  }
}

TEST(BitmapWriterTests, ShouldWritePixelToByteArray)
{
  Pixels::RGBColours redRgbColours = BitmapSetUp::getRedColours();
  Pixels::RGBPixel redPixel {redRgbColours};
  BitmapWriter writer {};
  ByteArray bytes = writer.writePixel(redPixel);

  // 24-bit pixel only atm. Alpha channel to come later.
  // Reverse ordering of bytes so BGR instead of RGB.
  EXPECT_EQ(redRgbColours.getBlue(), bytes[0].value);
  EXPECT_EQ(redRgbColours.getGreen(), bytes[1].value);
  EXPECT_EQ(redRgbColours.getRed(), bytes[2].value);
}