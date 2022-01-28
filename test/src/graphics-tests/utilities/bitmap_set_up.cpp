#include <string>

#include "test/src/graphics-tests/utilities/bitmap_set_up.h"
#include "test/src/graphics-tests/utilities/bitmap_image_comparators.h"
#include "src/graphics/bitmaps/packet/packet.h"
#include "src/graphics/bitmaps/packet/pixel-array/pixel/format.h"
#include "src/graphics/bitmaps/packet/pixel-array/array/array.h"
#include "src/graphics/bitmaps/packet/pixel-array/pixel/pixel.h"
#include "src/graphics/bitmaps/packet/pixel-array/array/values.h"

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

BitmapHeaders::Headers BitmapSetUp::bluePixelHeaders()
{
  BitmapHeaders::Headers headers {};
  headers.fileHeader = bluePixelFileHeader();
  headers.dibHeader = bluePixelDibHeader();

  return headers;
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
  dibHeader.setBitsPerPixel(24);

  return dibHeader;
}

Pixels::Array BitmapSetUp::bluePixelArray()
{
  Pixels::ArrayValues values;
  values.widthInPixels = 512;
  values.heightInPixels = 512;
  values.pixelFormat.name = "RGB";
  values.pixelFormat.bitsPerPixel = 24;
  values.pixelFormat.colourNames = {"red", "blue", "green"};

  Pixels::Array pixelArray {values};
  pixelArray.fill(BitmapSetUp::blueColours());

  return pixelArray;
}

Pixels::Array BitmapSetUp::redPixelArray()
{
  Pixels::ArrayValues values;
  values.widthInPixels = 2;
  values.heightInPixels = 2;
  values.pixelFormat.name = "RGB";
  values.pixelFormat.bitsPerPixel = 24;
  values.pixelFormat.colourNames = {"red", "blue", "green"};

  Pixels::Array pixelArray {values};
  pixelArray.fill(BitmapSetUp::redColours());

  return pixelArray;
}

Pixels::Pixel BitmapSetUp::greenPixel()
{
  Pixels::Format format;
  format.name = "RGB";
  format.bitsPerPixel = 24;
  format.colourNames = {"red", "blue", "green"};

  Pixels::Pixel pixel {format.colourNames};
  pixel.setColours(BitmapSetUp::greenColours());

  return pixel;
}

Pixels::Colours BitmapSetUp::redColours()
{
  Pixels::Colours colours;
  colours["red"] = 255;
  colours["green"] = 0;
  colours["blue"] = 0;

  return colours;
}

Pixels::Colours BitmapSetUp::greenColours()
{
  Pixels::Colours colours;
  colours["red"] = 0;
  colours["green"] = 255;
  colours["blue"] = 0;

  return colours;
}

Pixels::Colours BitmapSetUp::blueColours()
{
  Pixels::Colours colours;
  colours["red"] = 100;
  colours["green"] = 255;
  colours["blue"] = 255;

  return colours;
}

Pixels::Colours BitmapSetUp::whiteColours()
{
  Pixels::Colours colours;
  colours["red"] = 255;
  colours["green"] = 255;
  colours["blue"] = 255;

  return colours;
}