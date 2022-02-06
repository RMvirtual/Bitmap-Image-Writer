#include <gtest/gtest.h>

#include "test/src/bitmaps/image/fixture.h"
#include "src/bitmaps/packet/headers/headers.h"
#include "src/bitmaps/formats/formats.h"

BitmapImageTest::BitmapImageTest()
{

}

BitmapImageTest::~BitmapImageTest()
{

}

void BitmapImageTest::setup2x2Image()
{
  this->filePath = {
    "C:\\Users\\rmvir\\Desktop\\scc300-Win3D\\test\\resources\\"
    "correct-resources\\blueImage2x2Write.bmp"
  };

  this->setupRGBFormat(2,2);
}

void BitmapImageTest::setup1x4Image()
{
  this->filePath = {
    "C:\\Users\\rmvir\\Desktop\\scc300-Win3D\\test\\resources\\"
    "correct-resources\\blueImage1x4Write.bmp"
  };

  this->setupRGBFormat(1,4);
}

void BitmapImageTest::setup3x5Image()
{
  this->filePath = {
    "C:\\Users\\rmvir\\Desktop\\scc300-Win3D\\test\\resources\\"
    "correct-resources\\blueImage3x5Write.bmp"
  };

  this->setupRGBFormat(3,5);
}

void BitmapImageTest::setupRGBFormat(int widthInPixels, int heightInPixels)
{
  this->format = Bitmaps::format("RGB");
  this->format.setWidthInPixels(widthInPixels);
  this->format.setHeightInPixels(heightInPixels);

  this->image = {this->format};
  this->image.fill(this->getBlueColours());
}

Bitmaps::Colours BitmapImageTest::getBlueColours()
{
  auto colours = this->format.colours();
  colours["red"] = 100;
  colours["green"] = 255;
  colours["blue"] = 255;

  return colours;
}