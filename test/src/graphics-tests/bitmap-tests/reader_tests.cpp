#include <gtest/gtest.h>

#include "src/graphics/bitmaps/packet/packet.h"
#include "src/graphics/bitmaps/reader/bitmap_reader.h"
#include "test/src/graphics-tests/utilities/bitmap_set_up.h"
#include "src/graphics/bitmaps/formats/formats.h"

BitmapPacket getBitmapPacket()
{
  auto imagePath = BitmapSetUp::blueImagePath();
  BitmapReader::ImageReader reader {};

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
  auto format = Pixels::format(headers);

  EXPECT_EQ("RGB", format.name());
  EXPECT_EQ(24, format.bitsPerPixel());
  
  std::vector<std::string> correctColours {"blue", "green", "red"};

  EXPECT_EQ(correctColours.size(), format.colourNames().size());

  for (int colourNo = 0; colourNo < correctColours.size(); colourNo++)
    EXPECT_EQ(correctColours[colourNo], format.colourNames()[colourNo]);
}