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

  // Compare reserved bytes.
  auto correctReservedBytes = fileHeader.reservedBytes();
  
  uint32_t reservedBytes = ByteConversion::convertTo32BitInt(
    bytes.slice(2, 6));

  EXPECT_EQ(correctReservedBytes, reservedBytes);
}