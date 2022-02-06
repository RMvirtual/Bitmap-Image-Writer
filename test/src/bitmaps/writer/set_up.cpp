#include <gtest/gtest.h>

#include "src/bitmaps/formats/formats.h"
#include "src/bitmaps/writer/image/writer.h"
#include "test/src/bitmaps/writer/fixture.h"

void BitmapWriterTest::setup2x2Image()
{
  this->setOutputFilePath("blueImage2x2Write.bmp");
  this->setupBlueRGBImage(2, 2);
}

void BitmapWriterTest::setup1x4Image()
{
  this->setOutputFilePath("blueImage1x4Write.bmp");
  this->setupBlueRGBImage(1, 4);
}

void BitmapWriterTest::setup3x5Image()
{
  this->setOutputFilePath("blueImage3x5Write.bmp");
  this->setupBlueRGBImage(3, 5);
}

void BitmapWriterTest::setupBlueRGBImage(int widthInPixels, int heightInPixels)
{
  auto format = Bitmaps::format("RGB");
  format.setWidthInPixels(widthInPixels);
  format.setHeightInPixels(heightInPixels);
  
  this->image = {format};

  auto colours = format.colours();
  colours["red"] = 100;
  colours["green"] = 255;
  colours["blue"] = 255;

  this->image.fill(colours);
}

void BitmapWriterTest::setOutputFilePath(std::string fileName)
{
  this->filePath = {
    "C:\\Users\\rmvir\\Desktop\\scc300-Win3D\\test\\resources\\"
    "correct-resources\\" + fileName
  };
}