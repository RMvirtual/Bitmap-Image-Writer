#include <gtest/gtest.h>
#include <string>

#include "src/graphics/bitmaps/bitmap_image.h"
#include "test/src/graphics-tests/utilities/bitmap_image_comparators.h"
#include "test/src/graphics-tests/utilities/bitmap_set_up.h"

TEST(BitmapImageTests, ShouldWriteBitmap)
{
  /*
  char* imageToTestPath = 
    "C:\\Users\\rmvir\\Desktop\\scc300-Win3D\\test\\output\\myImage.bmp";

  char* correctImagePath =
    "C:\\Users\\rmvir\\Desktop\\scc300-Win3D\\test\\resources\\" \
    "correct-resources\\blueImage512x512.bmp";

  BitmapImage bitmapImage = BitmapSetUp::setUpBlueBitmapImage();
  bitmapImage.writeToFile(imageToTestPath);
  
  BitmapImage correctImage = BitmapImage::fromFile(correctImagePath);  
  BitmapImage imageToTest = BitmapImage::fromFile(imageToTestPath);

  BitmapImageComparison::compareBitmapImages(correctImage, imageToTest);
  */

  EXPECT_TRUE(false);
}