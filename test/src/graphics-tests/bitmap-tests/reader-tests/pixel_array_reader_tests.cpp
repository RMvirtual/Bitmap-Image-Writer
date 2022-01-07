#include <gtest/gtest.h>

#include "test/src/graphics-tests/utilities/bitmap_image_comparators.h"
#include "test/src/graphics-tests/utilities/bitmap_set_up.h"
#include "src/graphics/bitmaps/reader/bitmap_reader.h"

TEST(PixelArrayReaderTests, ShouldReadPixelArraySizeInBytesFromFile)
{ 
  std::string filePath = BitmapSetUp::getBlueImagePath();

  const int correctSize = 786432;
  int payloadSizeInBytes = BitmapReader::getPixelArraySizeInBytes(filePath);

  EXPECT_EQ(correctSize, payloadSizeInBytes);
}

TEST(PixelArrayReaderTests, ShouldReadPixelArrayFromFile)
{
  std::string imagePath = BitmapSetUp::getBlueImagePath();

  Pixels::PixelArray pixelArrayToTest = BitmapReader::getPixelArray(imagePath);
  Pixels::PixelArray correctPixelArray = BitmapSetUp::setUpBluePixelArray();

  BitmapImageComparison::comparePixelArrays(
    correctPixelArray, pixelArrayToTest);
}