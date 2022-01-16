#include <gtest/gtest.h>
#include <string>

#include "src/graphics/bitmaps/packet/pixel-array/arrays/pixel_array.h"
#include "src/graphics/bitmaps/packet/pixel-array/pixels/rgb_pixel.h"
#include "src/graphics/shapes/triangle.h"
#include "src/graphics/shapes/straight_line.h"
#include "test/src/graphics-tests/utilities/bitmap_set_up.h"
#include "src/graphics/bitmaps/packet/pixel-array/pixels/colours/rgb_colours.h"

TEST(StraightLineTests, ShouldDrawLine)
{  
  BitmapPacket packet = BitmapSetUp::setUpBlueBitmapPacket();

  Maths::Vector vertex1 {50, 100};
  Maths::Vector vertex2 {50, -100};
  Maths::Vector vertex3 {-100, 0};

  std::vector<Maths::Vector> vertices {vertex1, vertex2, vertex3};
  Shapes::Triangle triangle {vertices};

  Pixels::PixelArray pixelArray = packet.pixelArray;

  int pixelWidth = packet.dibHeader.widthInPixels();
  int pixelsHeight = packet.dibHeader.heightInPixels();

  int totalPixels = pixelArray.sizeInPixels();

  Shapes::StraightLine straightLine {{100, 100}};

  double x = 0, y = 0;

  Pixels::RGBColours colours;
  colours.setRed(0);
  colours.setGreen(0);
  colours.setBlue(0);

  Pixels::RGBPixel pixel {colours};

  while (x < straightLine.endPoint[0]) {    
    pixelArray.set(pixel, x, y);
    x++; y++;
  }

  char* imageToTestPath = 
    "C:\\Users\\rmvir\\Desktop\\scc300-Win3D\\test\\output\\straightLine.bmp";

  // Needs a bitmap image writer method to replace below.
  // bitmapImage.writeToFile(imageToTestPath);

  ASSERT_TRUE(false);
}