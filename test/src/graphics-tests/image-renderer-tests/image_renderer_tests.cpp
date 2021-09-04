#include <gtest/gtest.h>
#include "src/graphics/image-rendering/image_renderer.h"
#include "test/src/graphics-tests/utilities/bitmap_image_comparators.h"

TEST(ImageRendererTests, ShouldFillImageRed)
{
  ImageRendering::ImageRenderer imageRenderer;

  imageRenderer.setWidth(512);
  imageRenderer.setHeight(512);
  
  imageRenderer.fill(255, 0, 0);
  
  BitmapImage bmpImage = imageRenderer.toBitmap();

  char* outputFile =
    "C:\\Users\\rmvir\\Desktop\\scc300-Win3D\\test\\output\\redFill.bmp";

  bmpImage.writeToFile(outputFile);

  char* correctFile = 
    "C:\\Users\\rmvir\\Desktop\\scc300-Win3D\\test\\resources\\" \
    "correct-resources\\redFill512x512.bmp";
  
  BitmapImage correctImage = BitmapImage::fromFile(correctFile);
  BitmapImageComparison::compareBitmapImages(bmpImage, correctImage);
}

TEST(ImageRendererTests, ShouldCalculateFileSize)
{
  int correctFileSize = 786486;

  ImageRendering::ImageRenderer imageRenderer;

  imageRenderer.setWidth(512);
  imageRenderer.setHeight(512);

  int fileSize = imageRenderer.getFileSize();

  EXPECT_EQ(correctFileSize, fileSize);
}