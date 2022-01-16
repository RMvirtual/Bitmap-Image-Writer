#include "src/graphics/bitmaps/packet/bitmap_packet.h"
#include "src/graphics/bitmaps/packet/pixel-array/pixels/rgb_pixel.h"
#include "src/graphics/bitmaps/packet/pixel-array/arrays/pixel_array.h"
#include "test/src/graphics-tests/utilities/bitmap_image_comparators.h"
#include "test/src/graphics-tests/utilities/bitmap_set_up.h"
#include "src/graphics/bitmaps/packet/pixel-array/pixels/colours/rgb_colours.h"
#include "src/graphics/bitmaps/packet/pixel-array/arrays/pixel_array_values.h"

std::string BitmapSetUp::getBlueImagePath()
{
  return (
    "C:\\Users\\rmvir\\Desktop\\scc300-Win3D\\test\\resources\\"
    "correct-resources\\blueImage512x512.bmp"
  );
}

BitmapPacket BitmapSetUp::setUpBlueBitmapPacket()
{
  BitmapPacket packet;
  packet.fileHeader = setUpBluePixelFileHeader();
  packet.dibHeader = setUpBluePixelDibHeader();
  packet.pixelArray = setUpBluePixelArray();

  return packet;
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

Pixels::RGBColours BitmapSetUp::getBlueColours()
{
  Pixels::RGBColours colours;
  colours.setRed(100);
  colours.setGreen(255);
  colours.setBlue(255);

  return colours;
}

Pixels::PixelArray BitmapSetUp::setUpBluePixelArray()
{
  Pixels::PixelArrayValues values {};
  values.widthInPixels = 512;
  values.heightInPixels = 512;
  values.defaultPixel = {getBlueColours()};

  return Pixels::PixelArray {values};
}