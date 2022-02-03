#include <gtest/gtest.h>
#include <src/bitmaps/formats/formats.h>

class BitmapFormatsTest : public ::testing::Test
{
public:
  BitmapFormatsTest()
  {
    this->initialiseRgbaFormat();
    this->initialiseRgbFormat();
  }

  ~BitmapFormatsTest() {}

protected:
  Bitmaps::Format correctRGBAFormat;
  Bitmaps::Format correctRGBFormat;

  void compare(Bitmaps::Format& correctFormat, Bitmaps::Format& format)
  {
    EXPECT_EQ(correctFormat.name(), format.name());
    EXPECT_EQ(correctFormat.bitsPerPixel(), format.bitsPerPixel());
    EXPECT_EQ(correctFormat.colourNames().size(), format.colourNames().size());

    for (int colour = 0; colour < correctFormat.colourNames().size(); colour++)
      EXPECT_EQ(
        correctFormat.colourNames()[colour], format.colourNames()[colour]);
  }

private:
  void initialiseRgbaFormat()
  {
    this->correctRGBAFormat.setName("RGBA");
    this->correctRGBAFormat.setBitsPerPixel(32);
    this->correctRGBAFormat.setColourNames({"alpha", "blue", "green", "red"});
  }

  void initialiseRgbFormat()
  {
    this->correctRGBFormat.setName("RGB");
    this->correctRGBFormat.setBitsPerPixel(24);
    this->correctRGBFormat.setColourNames({"blue", "green", "red"});
  }
};

TEST_F(BitmapFormatsTest, ShouldGetRGBAFormat)
{
  this->compare(this->correctRGBAFormat, Bitmaps::format("RGBA"));
}

TEST_F(BitmapFormatsTest, ShouldGetRGBFormat)
{
  compare(this->correctRGBFormat, Bitmaps::format("RGB"));
}

TEST_F(BitmapFormatsTest, ShouldGet32BitPerPixelFormat)
{
  compare(this->correctRGBAFormat, Bitmaps::format(32));
}

TEST_F(BitmapFormatsTest, ShouldGet24BitPerPixelFormat)
{
  compare(this->correctRGBFormat, Bitmaps::format(24));
}

TEST_F(BitmapFormatsTest, ShouldCalculatePixelArrayRowPadding)
{
  auto format = Bitmaps::format(24);
  format.setWidthInPixels(2);
  format.setHeightInPixels(1);

  int actualPadding = format.rowPaddingInBytes();
  int correctPadding = 2;

  EXPECT_EQ(correctPadding, actualPadding);
}

TEST_F(BitmapFormatsTest, ShouldCalculatePixelArrayRowSizeInBytes)
{
  auto format = Bitmaps::format(24);
  format.setWidthInPixels(6);
  format.setHeightInPixels(1);

  int actualSize = format.rowSizeInBytes();
  int correctSize = 20;
  
  EXPECT_EQ(correctSize, actualSize);
}