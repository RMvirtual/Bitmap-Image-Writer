#include <gtest/gtest.h>

#include "test/src/bitmaps/image/fixture.h"
#include "src/bitmaps/packet/headers/headers.h"
#include "src/bitmaps/formats/formats.h"

BitmapImageTest::BitmapImageTest()
{
  this->setupRGBFormat();
  this->image = {this->format};
  this->image.fill(this->getBlueColours());
}

BitmapImageTest::~BitmapImageTest()
{

}

void BitmapImageTest::setupRGBFormat()
{
  this->format = Bitmaps::format("RGB");
  this->format.setWidthInPixels(2);
  this->format.setHeightInPixels(2);

  auto colours = this->format.colours();
  colours["blue"] = 255; 
}

Bitmaps::Colours BitmapImageTest::getBlueColours()
{
  auto colours = this->format.colours();
  colours["blue"] = 255; 

  return colours;
}