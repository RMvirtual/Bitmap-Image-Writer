#include "test/src/bitmaps/formats/fixture.h"

BitmapFormatsTest::BitmapFormatsTest()
{
  this->initialiseRgbaFormat();
}

BitmapFormatsTest::~BitmapFormatsTest()
{

}

void BitmapFormatsTest::initialiseRgbaFormat()
{
  this->format.setName("RGBA");
  this->format.setBitsPerPixel(32);
  this->format.setColourNames({"alpha", "blue", "green", "red"});
}

void BitmapFormatsTest::initialiseRgbFormat()
{
  this->format.setName("RGB");
  this->format.setBitsPerPixel(24);
  this->format.setColourNames({"blue", "green", "red"});
}