#include <gtest/gtest.h>
#include "src/graphics/image-rendering/image_renderer.h"


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