#include <gtest/gtest.h>
#include <string>

#include "src/graphics/bitmaps/packet/pixels/pixel_array.h"
#include "src/graphics/bitmaps/packet/pixels/pixel.h"
#include "src/graphics/bitmaps/bitmap_image.h"
#include "src/graphics/shapes/triangle.h"
#include "src/graphics/shapes/straight_line.h"
#include "test/src/graphics-tests/utilities/bitmap_set_up.h"
#include "src/graphics/image-rendering/image_renderer.h"

TEST(StraightLineTests, ShouldDrawLine)
{  
  BitmapImage bitmapImage = BitmapSetUp::setUpBlueBitmapImage();

  Maths::Vector vertex1 {50, 100};
  Maths::Vector vertex2 {50, -100};
  Maths::Vector vertex3 {-100, 0};

  std::vector<Maths::Vector> vertices {vertex1, vertex2, vertex3};
  Shapes::Triangle triangle {vertices};

  Pixels::PixelArray pixelArray = bitmapImage.getPixelArray();

  int pixelWidth = pixelArray.getWidthInPixels();
  int pixelsHeight = pixelArray.getHeightInPixels();

  int totalPixels = pixelArray.sizeInPixels();

  ImageRendering::ImageRenderer imageRenderer;
  Shapes::StraightLine straightLine {{100, 100}};

  double x = 0, y = 0;

  Pixels::PixelData blackPixelData;
  blackPixelData.red = 0;
  blackPixelData.green = 0;
  blackPixelData.blue = 0;

  while (x < straightLine.endPoint[0]) {
    blackPixelData.columnNo = x;
    blackPixelData.rowNo = y;
    
    pixelArray.setPixel(blackPixelData);

    x++; y++;
  }

  bitmapImage.setPixelArray(pixelArray);

  char* imageToTestPath = 
    "C:\\Users\\rmvir\\Desktop\\scc300-Win3D\\test\\output\\straightLine.bmp";

  bitmapImage.writeToFile(imageToTestPath);
}