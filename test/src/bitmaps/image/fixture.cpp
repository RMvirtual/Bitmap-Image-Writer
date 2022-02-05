#include <gtest/gtest.h>

#include "test/src/bitmaps/image/fixture.h"
#include "src/bitmaps/packet/headers/headers.h"
#include "src/bitmaps/formats/formats.h"

BitmapImageTest::BitmapImageTest()
{
  this->setupRGBFormat();
  this->image = {this->format};
  this->image.fill(this->getBlueColours());

  this->filePath = {
    "C:\\Users\\rmvir\\Desktop\\scc300-Win3D\\test\\resources\\"
    "correct-resources\\blueImage10x10.bmp"
  };
}

BitmapImageTest::~BitmapImageTest()
{

}

void BitmapImageTest::setupRGBFormat()
{
  this->format = Bitmaps::format("RGB");
  this->format.setWidthInPixels(10);
  this->format.setHeightInPixels(12);
}

Bitmaps::Colours BitmapImageTest::getBlueColours()
{
  auto colours = this->format.colours();
  colours["blue"] = 255; 

  return colours;
}