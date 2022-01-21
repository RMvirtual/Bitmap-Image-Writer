#include <string>

#include "test/src/graphics-tests/utilities/bitmap_set_up.h"
#include "test/src/graphics-tests/utilities/bitmap_image_comparators.h"
#include "src/graphics/bitmaps/packet/bitmap_packet.h"
#include "src/graphics/bitmaps/packet/pixel-array/colours/rgb.h"
#include "src/graphics/bitmaps/packet/pixel-array/pixel_array.h"
#include "src/graphics/bitmaps/packet/pixel-array/pixel.h"
#include "src/graphics/bitmaps/packet/pixel-array/pixel_array_values.h"

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

Pixels::RGBColours BitmapSetUp::blueColours()
{
  Pixels::RGBColours colours;
  colours.setRed(100);
  colours.setGreen(255);
  colours.setBlue(255);

  return colours;
}

Pixels::PixelArray <Pixels::Pixel<Pixels::RGBColours>> BitmapSetUp::bluePixelArray()
{
  Pixels::PixelArrayValues<Pixels::Pixel<Pixels::RGBColours>> values {};
  values.widthInPixels = 512;
  values.heightInPixels = 512;
  values.defaultPixel = {blueColours()};

  return Pixels::PixelArray <Pixels::Pixel<Pixels::RGBColours>> {values};
}

Pixels::Pixel<Pixels::RGBColours> BitmapSetUp::greenRGBPixel()
{
  auto greenColours = BitmapSetUp::greenColours();

  return {greenColours};
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

Pixels::PixelArray<Pixels::Pixel<Pixels::RGBColours>> BitmapSetUp::redPixelArray()
{
  Pixels::PixelArrayValues<Pixels::Pixel<Pixels::RGBColours>> values {};
  values.widthInPixels = 2;
  values.heightInPixels = 2;
  values.defaultPixel = {BitmapSetUp::redColours()};

  return {values};
}
