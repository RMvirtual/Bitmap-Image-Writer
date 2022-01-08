#include <iostream>

#include "src/graphics/bitmaps/packet/pixels/pixel.h"
#include "src/graphics/bitmaps/packet/pixels/pixel_array.h"
#include "src/graphics/bitmaps/bitmap_image.h"
#include "test/src/graphics-tests/utilities/bitmap_image_comparators.h"
#include "test/src/graphics-tests/utilities/bitmap_set_up.h"
#include "src/graphics/colours/colours.h"

std::string BitmapSetUp::getBlueImagePath()
{
  return (
    "C:\\Users\\rmvir\\Desktop\\scc300-Win3D\\test\\resources\\"
    "correct-resources\\blueImage512x512.bmp"
  );
}

BitmapImage BitmapSetUp::setUpBlueBitmapImage()
{
  BitmapPacket packet;
  packet.fileHeader = setUpBluePixelFileHeader();
  packet.dibHeader = setUpBluePixelDibHeader();
  packet.pixelArray = setUpBluePixelArray();

  return BitmapImage::fromPacket(packet);
}

BitmapHeaders::FileHeader BitmapSetUp::setUpBluePixelFileHeader()
{
  BitmapHeaders::FileHeader fileHeader;

  fileHeader.setSignatureBytes("BM");
  fileHeader.setSizeOfBitmapFile(786486);
  fileHeader.setReservedBytes(0);
  fileHeader.setPixelDataOffset(54);

  return fileHeader;
}

BitmapHeaders::DibHeader BitmapSetUp::setUpBluePixelDibHeader()
{
  BitmapHeaders::DibHeader dibHeader {};

  dibHeader.setWidthInPixels(512);
  dibHeader.setHeightInPixels(512);
  dibHeader.setNumberOfColourPlanes(1);

  return dibHeader;
}

Pixels::PixelArray BitmapSetUp::setUpBluePixelArray()
{
  std::vector<Pixels::Pixel> pixels;

  Colours blueColours;
  blueColours.red = 100;
  blueColours.green = 255;
  blueColours.blue = 255;

  Pixels::Pixel bluePixel {blueColours};

  int imageWidth = 512, imageHeight = 512;
  int totalPixels = imageWidth * imageHeight;

  for (int pixelNo = 0; pixelNo < totalPixels; pixelNo++)
    pixels.push_back(bluePixel);

  std::cout << "Gets here."; 

  return Pixels::PixelArray {pixels, imageWidth, imageHeight};
}

Colours BitmapSetUp::getRedColours()
{
  Colours colours;
  colours.red = 255;
  colours.green = 0;
  colours.blue = 0;

  return colours;
}

Colours BitmapSetUp::getGreenColours()
{
  Colours colours;
  colours.red = 0;
  colours.green = 255;
  colours.blue = 0;

  return colours;
}

Colours BitmapSetUp::getWhiteColours()
{
  Colours colours;
  colours.red = 255;
  colours.green = 255;
  colours.blue = 255;

  return colours;
}
