#include <gtest/gtest.h>

#include "src/graphics/bitmaps/packet/pixels/pixel.h"
#include "src/graphics/bitmaps/packet/pixels/pixel_array.h"
#include "src/graphics/bitmaps/reader/bitmap_reader.h"
#include "src/graphics/bitmaps/bitmap_image.h"
#include "test/src/graphics-tests/utilities/bitmap_image_comparators.h"
#include "test/src/graphics-tests/utilities/bitmap_set_up.h"

TEST(BitmapImageReaderTests, ShouldExtractBitmapImageObjectFromFile)
{
  std::string imagePath = BitmapSetUp::getBlueImagePath();

  BitmapImage imageToTest = BitmapImage::fromFile(imagePath);
  BitmapImage correctImage = BitmapSetUp::setUpBlueBitmapImage();

  BitmapImageComparison::compareBitmapImages(correctImage, imageToTest);
}