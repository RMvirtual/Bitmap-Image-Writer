#include <string>

#include "src/graphics/bitmaps/packet/rgb_bitmap_packet.h"
#include "src/graphics/bitmaps/packet/pixel-array/rgb/rgb_pixel.h"
#include "src/graphics/bitmaps/packet/pixel-array/rgb/rgb_pixel_array.h"
#include "test/src/graphics-tests/utilities/bitmap_image_comparators.h"
#include "test/src/graphics-tests/utilities/bitmap_set_up.h"
#include "src/graphics/bitmaps/packet/pixel-array/rgb/rgb_colours.h"
#include "src/graphics/bitmaps/packet/pixel-array/rgb/rgb_pixel_array_values.h"

std::string BitmapSetUp::blueImagePath()
{
  return (
    "C:\\Users\\rmvir\\Desktop\\scc300-Win3D\\test\\resources\\"
    "correct-resources\\blueImage512x512.bmp"
  );
}

RGBBitmapPacket BitmapSetUp::blueBitmapPacket()
{
  RGBBitmapPacket packet;
  packet.fileHeader = bluePixelFileHeader();
  packet.dibHeader = bluePixelDibHeader();
  packet.pixelArray = bluePixelArray();

  return packet;
}

BitmapHeaders::FileHeader BitmapSetUp::bluePixelFileHeader()
{
  BitmapHeaders::FileHeader fileHeader;

  fileHeader.setSignatureBytes("BM");
  fileHeader.setFileSizeInBytes(786486);
  fileHeader.setReservedBytes(0);
  fileHeader.setPixelArrayOffsetInBytes(54);

  return fileHeader;
}

BitmapHeaders::DibHeader BitmapSetUp::bluePixelDibHeader()
{
  BitmapHeaders::DibHeader dibHeader {};

  dibHeader.setWidthInPixels(512);
  dibHeader.setHeightInPixels(512);
  dibHeader.setNumberOfColourPlanes(1);

  return dibHeader;
}

Pixels::RGBColours BitmapSetUp::blueColours()
{
  Pixels::RGBColours colours;
  colours.setRed(100);
  colours.setGreen(255);
  colours.setBlue(255);

  return colours;
}

Pixels::RGBPixelArray BitmapSetUp::bluePixelArray()
{
  Pixels::RGBPixelArrayValues values {};
  values.widthInPixels = 512;
  values.heightInPixels = 512;
  values.defaultPixel = {blueColours()};

  return Pixels::RGBPixelArray {values};
}

Pixels::RGBColours BitmapSetUp::redColours()
{
  Pixels::RGBColours colours;
  colours.setRed(255);
  colours.setGreen(0);
  colours.setBlue(0);

  return colours;
}

Pixels::RGBColours BitmapSetUp::greenColours()
{
  Pixels::RGBColours colours;
  colours.setRed(0);
  colours.setGreen(255);
  colours.setBlue(0);

  return colours;
}

Pixels::RGBColours BitmapSetUp::whiteColours()
{
  Pixels::RGBColours colours;
  colours.setRed(255);
  colours.setGreen(255);
  colours.setBlue(255);

  return colours;
}

Pixels::RGBPixelArray BitmapSetUp::redPixelArray()
{
  Pixels::RGBPixelArrayValues values;
  values.widthInPixels = 2;
  values.heightInPixels = 2;
  values.defaultPixel = {BitmapSetUp::redColours()};

  return {values};
}
