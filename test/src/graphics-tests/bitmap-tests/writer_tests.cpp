#include <gtest/gtest.h>

#include "test/src/graphics-tests/utilities/bitmap_set_up.h"
#include "src/graphics/bitmaps/writer/writer.h"
#include "src/common/byte-array/byte_conversion.h"

TEST(BitmapWriterTests, ShouldConvertFileHeaderToBytes)
{
  auto fileHeader = BitmapSetUp::setUpBluePixelFileHeader();
  
  BitmapWriter::ImageWriter writer {};
  auto bytes = writer.convertToBytes(fileHeader);

  // Compare signature bytes.
  auto correctSignatureBytes = fileHeader.signatureBytes();
  auto signatureBytes = bytes.slice(0, 2);
  std::string returnedSignatureBytes = {};
  returnedSignatureBytes += signatureBytes[0].value;
  returnedSignatureBytes += signatureBytes[1].value;

  EXPECT_EQ(correctSignatureBytes, returnedSignatureBytes);

  // Compare size of bitmap file.
  auto correctFileSize = fileHeader.sizeOfBitmapFile();
  uint32_t fileSize = ByteConversion::convertTo32BitInt(bytes.slice(2,6));
    
  EXPECT_EQ(correctFileSize, fileSize);

  // Compare reserved bytes.
  auto correctReservedBytes = fileHeader.reservedBytes();

  uint32_t reservedBytes = ByteConversion::convertTo32BitInt(
    bytes.slice(6,10));

  EXPECT_EQ(correctReservedBytes, reservedBytes);

  // Compare pixel array offset.
  auto correctPixelArrayOffset = fileHeader.pixelDataOffset();
  uint32_t pixelArrayOffset = ByteConversion::convertTo32BitInt(
    bytes.slice(10,14));

  EXPECT_EQ(correctPixelArrayOffset, pixelArrayOffset);
}