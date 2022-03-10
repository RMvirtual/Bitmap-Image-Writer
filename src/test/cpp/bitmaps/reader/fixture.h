#pragma once

#include <string>

#include "gtest/gtest.h"
#include "src/main/cpp/bitmaps/image/image.h"
#include "src/main/cpp/bitmaps/reader/image/reader.h"

class BitmapReaderTest : public testing::Test
{
public:
  BitmapReaderTest();
  ~BitmapReaderTest();

private:
  void setupCorrectImage();
  void setupFileHeader();
  void setupDibHeader();
  void setupPixelArray();
  void setupColours();

protected:
  std::shared_ptr<Bitmaps::Image> image;
  Bitmaps::ImageReader reader {};
  ByteArray fileContents;
  
  std::string blueImagePath();

  void compare(std::shared_ptr<Bitmaps::Image> image);
  void compare(std::shared_ptr<Bitmaps::FileHeader> header);
  void compare(std::shared_ptr<Bitmaps::DibHeader> header);
  void compare(std::shared_ptr<Bitmaps::PixelArray> array);
};