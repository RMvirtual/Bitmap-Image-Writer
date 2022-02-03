#include <gtest/gtest.h>

#include "test/src/bitmaps/reader/fixture.h"
#include "src/bitmaps/formats/formats.h"

TEST_F(BitmapReaderTest, ShouldReadFileHeader)
{
  this->loadBluePixelFileHeader();
  auto header = this->readPacket().fileHeader;
 
  this->compare(header);
}

TEST_F(BitmapReaderTest, ShouldReadDibHeader)
{
  this->loadBluePixelDibHeader();
  auto header = this->readPacket().dibHeader;

  this->compare(header);
}

TEST_F(BitmapReaderTest, ShouldReadPixelArray)
{
  this->loadBluePixelArray();
  auto pixelArray = this->readPacket().pixelArray;
  
  this->compare(pixelArray);
}

TEST_F(BitmapReaderTest, ShouldReadBitmapFormatFromHeaders)
{
  auto format = Bitmaps::format(this->bluePixelHeaders());

  EXPECT_EQ("RGB", format.name());
  EXPECT_EQ(24, format.bitsPerPixel());
  
  std::vector<std::string> correctColours {"blue", "green", "red"};

  EXPECT_EQ(correctColours.size(), format.colourNames().size());

  for (int colourNo = 0; colourNo < correctColours.size(); colourNo++)
    EXPECT_EQ(correctColours[colourNo], format.colourNames()[colourNo]);
}