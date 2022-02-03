#include <gtest/gtest.h>

#include "src/bitmaps/packet/packet.h"
#include "src/bitmaps/reader/bitmap_reader.h"
#include "test/src/bitmaps/test-utilities/set_up.h"
#include "src/bitmaps/formats/formats.h"

Bitmaps::Packet getBitmapPacket()
{
  auto imagePath = BitmapSetUp::blueImagePath();
  Bitmaps::ImageReader reader {};

  return reader.read(imagePath);
}

TEST(BitmapReader, ShouldReadFileHeader)
{
  auto header = getBitmapPacket().fileHeader;
  auto correctHeader = BitmapSetUp::bluePixelFileHeader();
 
  BitmapImageComparison::compare(correctHeader, header);
}

TEST(BitmapReader, ShouldReadDibHeader)
{
  auto header = getBitmapPacket().dibHeader;
  auto correctHeader = BitmapSetUp::bluePixelDibHeader();

  BitmapImageComparison::compare(correctHeader, header);
}

TEST(BitmapReader, ShouldReadPixelArray)
{
  auto pixelArray = getBitmapPacket().pixelArray;
  auto correctPixelArray = BitmapSetUp::bluePixelArray();

  BitmapImageComparison::compare(correctPixelArray, pixelArray);
}

TEST(BitmapReader, ShouldGetPixelArrayFormatFromHeaders)
{
  auto headers = BitmapSetUp::bluePixelHeaders();
  auto format = Bitmaps::format(headers);

  EXPECT_EQ("RGB", format.name());
  EXPECT_EQ(24, format.bitsPerPixel());
  
  std::vector<std::string> correctColours {"blue", "green", "red"};

  EXPECT_EQ(correctColours.size(), format.colourNames().size());

  for (int colourNo = 0; colourNo < correctColours.size(); colourNo++)
    EXPECT_EQ(correctColours[colourNo], format.colourNames()[colourNo]);
}