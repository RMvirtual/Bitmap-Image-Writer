#include <gtest/gtest.h>

#include "src/graphics/bitmaps/writer/writer.h"
#include "src/graphics/bitmaps/packet/headers/file-header/file_header.h"
#include "test/src/graphics-tests/utilities/bitmap_set_up.h"

TEST(BitmapWriterTests, ShouldWriteFileHeaderToByteArray)
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

TEST(BitmapWriterTests, ShouldWriteDibHeaderToByteArray)
{ 
  BitmapHeaders::DibHeader header = BitmapSetUp::setUpBluePixelDibHeader();
  BitmapWriter writer {};
  ByteArray bytes = writer.writeDibHeader(header);

  // Header size in bytes.
  EXPECT_EQ(
    (unsigned char) (header.getHeaderSizeInBytes()), bytes[0].value);

  EXPECT_EQ(
    (unsigned char) (header.getHeaderSizeInBytes() >> 8), bytes[1].value);

  EXPECT_EQ(
    (unsigned char) (header.getHeaderSizeInBytes() >> 16), bytes[2].value);

  EXPECT_EQ(
    (unsigned char) (header.getHeaderSizeInBytes() >> 24), bytes[3].value);

  // Width in pixels.
  EXPECT_EQ(
    (unsigned char) (header.getWidthInPixels()), bytes[4].value);

  EXPECT_EQ(
    (unsigned char) (header.getWidthInPixels() >> 8), bytes[5].value);

  EXPECT_EQ(
    (unsigned char) (header.getWidthInPixels() >> 16), bytes[6].value);

  EXPECT_EQ(
    (unsigned char) (header.getWidthInPixels() >> 24), bytes[7].value);

  // Height in pixels.
  EXPECT_EQ(
    (unsigned char) (header.getHeightInPixels()), bytes[8].value);

  EXPECT_EQ(
    (unsigned char) (header.getHeightInPixels() >> 8), bytes[9].value);

  EXPECT_EQ(
    (unsigned char) (header.getHeightInPixels() >> 16), bytes[10].value);

  EXPECT_EQ(
    (unsigned char) (header.getHeightInPixels() >> 24), bytes[11].value);

  // Number of colour planes.
  EXPECT_EQ(
    (unsigned char) (header.getNumberOfColorPlanes()), bytes[12].value);

  EXPECT_EQ(
    (unsigned char) (header.getNumberOfColorPlanes() >> 8), bytes[13].value);

  // Colour depth.
  EXPECT_EQ(
    (unsigned char) (header.getColorDepth()), bytes[14].value);

  EXPECT_EQ(
    (unsigned char) (header.getColorDepth() >> 8), bytes[15].value);

  // Compression method.
  EXPECT_EQ(
    (unsigned char) (header.getCompressionMethod()), bytes[16].value);

  EXPECT_EQ(
    (unsigned char) (header.getCompressionMethod() >> 8), bytes[17].value);

  EXPECT_EQ(
    (unsigned char) (header.getCompressionMethod() >> 16), bytes[18].value);

  EXPECT_EQ(
    (unsigned char) (header.getCompressionMethod() >> 24), bytes[19].value);

  // Raw bitmap file size.
  EXPECT_EQ(
    (unsigned char) (header.getRawBitmapDataSize()), bytes[20].value);

  EXPECT_EQ(
    (unsigned char) (header.getRawBitmapDataSize() >> 8), bytes[21].value);

  EXPECT_EQ(
    (unsigned char) (header.getRawBitmapDataSize() >> 16), bytes[22].value);

  EXPECT_EQ(
    (unsigned char) (header.getRawBitmapDataSize() >> 24), bytes[23].value);

  // Horizontal pixels per metre.
  EXPECT_EQ(
    (unsigned char) (header.getHorizontalPixelsPerMetre()), bytes[24].value);

  EXPECT_EQ(
    (unsigned char) (header.getHorizontalPixelsPerMetre() >> 8), bytes[25].value);

  EXPECT_EQ(
    (unsigned char) (header.getHorizontalPixelsPerMetre() >> 16), bytes[26].value);

  EXPECT_EQ(
    (unsigned char) (header.getHorizontalPixelsPerMetre() >> 24), bytes[27].value);

  // Vertical pixels per metre.
  EXPECT_EQ(
    (unsigned char) (header.getVerticalPixelsPerMetre()), bytes[28].value);

  EXPECT_EQ(
    (unsigned char) (header.getVerticalPixelsPerMetre() >> 8), bytes[29].value);

  EXPECT_EQ(
    (unsigned char) (header.getVerticalPixelsPerMetre() >> 16), bytes[30].value);

  EXPECT_EQ(
    (unsigned char) (header.getVerticalPixelsPerMetre() >> 24), bytes[31].value);

  // Colour table entries.
  EXPECT_EQ(
    (unsigned char) (header.getColorTableEntries()), bytes[32].value);

  EXPECT_EQ(
    (unsigned char) (header.getColorTableEntries() >> 8), bytes[33].value);

  EXPECT_EQ(
    (unsigned char) (header.getColorTableEntries() >> 16), bytes[34].value);

  EXPECT_EQ(
    (unsigned char) (header.getColorTableEntries() >> 24), bytes[35].value);

  // Get important colours.
  EXPECT_EQ(
    (unsigned char) (header.getImportantColors()), bytes[36].value);

  EXPECT_EQ(
    (unsigned char) (header.getImportantColors() >> 8), bytes[37].value);

  EXPECT_EQ(
    (unsigned char) (header.getImportantColors() >> 16), bytes[38].value);

  EXPECT_EQ(
    (unsigned char) (header.getImportantColors() >> 24), bytes[39].value);
}

TEST(BitmapWriterTests, ShouldWritePixelArrayToByteArray)
{
  Pixels::PixelArray pixelArray = BitmapSetUp::setUpBluePixelArray();
  BitmapWriter writer {};
  ByteArray bytes = writer.writePixelArray(pixelArray);

  Colours pixelRgbColours {};
  pixelRgbColours.red = 100;
  pixelRgbColours.green = 255;
  pixelRgbColours.blue = 255;

  int numberOfPixels = pixelArray.sizeInPixels();
  int numberOfBytes = bytes.size();

  // Row stride unaccounted for.
  // Only testing first 12 bytes for testing speed.
  for (int byteNo = 0; byteNo < 12; byteNo += 3) {
    Pixels::RGBPixel pixel = pixelArray.getPixel(byteNo / 3);

    EXPECT_EQ(pixel.getBlue(), bytes[byteNo].value);
    EXPECT_EQ(pixel.getGreen(), bytes[byteNo+1].value);
    EXPECT_EQ(pixel.getRed(), bytes[byteNo+2].value);
  }
}

TEST(BitmapWriterTests, ShouldWritePixelToByteArray)
{
  Colours redRgbColours = BitmapSetUp::getRedColours();
  Pixels::RGBPixel redPixel {redRgbColours};
  BitmapWriter writer {};
  ByteArray bytes = writer.writePixel(redPixel);

  // 24-bit pixel only atm. Alpha channel to come later.
  // Reverse ordering of bytes so BGR instead of RGB.
  EXPECT_EQ(redRgbColours.blue, bytes[0].value);
  EXPECT_EQ(redRgbColours.green, bytes[1].value);
  EXPECT_EQ(redRgbColours.red, bytes[2].value);
}