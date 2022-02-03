#include <gtest/gtest.h>
#include "test/src/bitmaps/reader/fixture.h"

TEST_F(BitmapReaderTest, ShouldReadFileHeader)
{
  auto header = this->readPacket().fileHeader;
  auto correctHeader = this->bluePixelFileHeader();
 
  this->compare(correctHeader, header);
}

TEST_F(BitmapReaderTest, ShouldReadDibHeader)
{
  auto header = getBitmapPacket().dibHeader;
  auto correctHeader = this->bluePixelDibHeader();

  this->compare(correctHeader, header);
}

TEST_F(BitmapReaderTest, ShouldReadPixelArray)
{
  auto pixelArray = getBitmapPacket().pixelArray;
  auto correctPixelArray = this->bluePixelArray();

  this->compare(correctPixelArray, pixelArray);
}

TEST_F(BitmapReaderTest, ShouldGetPixelArrayFormatFromHeaders)
{
  auto headers = this->bluePixelHeaders();
  auto format = Bitmaps::format(headers);

  EXPECT_EQ("RGB", format.name());
  EXPECT_EQ(24, format.bitsPerPixel());
  
  std::vector<std::string> correctColours {"blue", "green", "red"};

  EXPECT_EQ(correctColours.size(), format.colourNames().size());

  for (int colourNo = 0; colourNo < correctColours.size(); colourNo++)
    EXPECT_EQ(correctColours[colourNo], format.colourNames()[colourNo]);
}