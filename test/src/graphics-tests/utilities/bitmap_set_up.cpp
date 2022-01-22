#include <string>

#include "test/src/graphics-tests/utilities/bitmap_set_up.h"
#include "test/src/graphics-tests/utilities/bitmap_image_comparators.h"
#include "src/graphics/bitmaps/packet/bitmap_packet.h"
#include "src/graphics/bitmaps/packet/pixel-array/rgb/colours.h"
#include "src/graphics/bitmaps/packet/pixel-array/rgb/pixel_array.h"
#include "src/graphics/bitmaps/packet/pixel-array/rgb/pixel.h"
#include "src/graphics/bitmaps/packet/pixel-array/rgb/pixel_array_values.h"

std::string BitmapSetUp::blueImagePath()
{
  return (
    "C:\\Users\\rmvir\\Desktop\\scc300-Win3D\\test\\resources\\"
    "correct-resources\\blueImage512x512.bmp"
  );
}

BitmapPacket BitmapSetUp::blueBitmapPacket()
{
  BitmapPacket packet;
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

Pixels::RGBPixelArray BitmapSetUp::bluePixelArray()
{
  Pixels::RGBPixelArrayValues values;
  values.widthInPixels = 512;
  values.heightInPixels = 512;
  values.defaultPixel = {BitmapSetUp::blueColours()};

  return {values};
}

Pixels::RGBPixelArray BitmapSetUp::redPixelArray()
{
  Pixels::RGBPixelArrayValues values;
  values.widthInPixels = 2;
  values.heightInPixels = 2;
  values.defaultPixel = {BitmapSetUp::redColours()};

  return {values};
}

Pixels::RGBPixel BitmapSetUp::greenRGBPixel()
{
  return {BitmapSetUp::greenColours()};
}

Pixels::RGBColours BitmapSetUp::redColours()
{
  Pixels::RGBColours colours;
  colours.red = 255;
  colours.green = 0;
  colours.blue = 0;

  return colours;
}

Pixels::RGBColours BitmapSetUp::greenColours()
{
  Pixels::RGBColours colours;
  colours.red = 0;
  colours.green = 255;
  colours.blue = 0;

  return colours;
}

Pixels::RGBColours BitmapSetUp::blueColours()
{
  Pixels::RGBColours colours;
  colours.red = 100;
  colours.green = 255;
  colours.blue = 255;

  return colours;
}

Pixels::RGBColours BitmapSetUp::whiteColours()
{
  Pixels::RGBColours colours;
  colours.red = 255;
  colours.green = 255;
  colours.blue = 255;

  return colours;
}