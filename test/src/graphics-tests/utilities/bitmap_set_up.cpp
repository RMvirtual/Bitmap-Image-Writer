#include <string>

#include "src/bitmaps/packet/packet.h"
#include "src/bitmaps/formats/format.h"
#include "src/bitmaps/packet/pixel-array/array.h"
#include "src/bitmaps/packet/pixel-array/colours.h"
#include "test/src/graphics-tests/utilities/bitmap_set_up.h"
#include "test/src/graphics-tests/utilities/bitmap_image_comparators.h"

std::string BitmapSetUp::blueImagePath()
{
  return (
    "C:\\Users\\rmvir\\Desktop\\scc300-Win3D\\test\\resources\\"
    "correct-resources\\blueImage512x512.bmp"
  );
}

Bitmaps::Packet BitmapSetUp::blueBitmapPacket()
{
  Bitmaps::Packet packet;
  packet.fileHeader = bluePixelFileHeader();
  packet.dibHeader = bluePixelDibHeader();
  packet.pixelArray = bluePixelArray();

  return packet;
}

Bitmaps::Headers BitmapSetUp::bluePixelHeaders()
{
  Bitmaps::Headers headers {};
  headers.fileHeader = bluePixelFileHeader();
  headers.dibHeader = bluePixelDibHeader();

  return headers;
}

Bitmaps::FileHeader BitmapSetUp::bluePixelFileHeader()
{
  Bitmaps::FileHeader fileHeader;

  fileHeader.setSignatureBytes("BM");
  fileHeader.setFileSizeInBytes(786486);
  fileHeader.setReservedBytes(0);
  fileHeader.setPixelArrayOffsetInBytes(54);

  return fileHeader;
}

Bitmaps::DibHeader BitmapSetUp::bluePixelDibHeader()
{
  Bitmaps::DibHeader dibHeader {};

  dibHeader.setWidthInPixels(512);
  dibHeader.setHeightInPixels(512);
  dibHeader.setNumberOfColourPlanes(1);
  dibHeader.setBitsPerPixel(24);

  return dibHeader;
}

Bitmaps::PixelArray BitmapSetUp::bluePixelArray()
{
  Bitmaps::Format format;
  format.setWidthInPixels(512);
  format.setHeightInPixels(512);
  format.setName("RGB");
  format.setBitsPerPixel(24);
  format.setColourNames({"red", "blue", "green"});

  Bitmaps::PixelArray pixelArray {format};
  pixelArray.fill(BitmapSetUp::blueColours());

  return pixelArray;
}

Bitmaps::PixelArray BitmapSetUp::redPixelArray()
{
  Bitmaps::Format format;
  format.setWidthInPixels(2);
  format.setHeightInPixels(2);
  format.setName("RGB");
  format.setBitsPerPixel(24);
  format.setColourNames({"red", "blue", "green"});

  Bitmaps::PixelArray pixelArray {format};
  pixelArray.fill(BitmapSetUp::redColours());

  return pixelArray;
}

Bitmaps::Colours BitmapSetUp::redColours()
{
  Bitmaps::Colours colours;
  colours["red"] = 255;
  colours["green"] = 0;
  colours["blue"] = 0;

  return colours;
}

Bitmaps::Colours BitmapSetUp::greenColours()
{
  Bitmaps::Colours colours;
  colours["red"] = 0;
  colours["green"] = 255;
  colours["blue"] = 0;

  return colours;
}

Bitmaps::Colours BitmapSetUp::blueColours()
{
  Bitmaps::Colours colours;
  colours["red"] = 100;
  colours["green"] = 255;
  colours["blue"] = 255;

  return colours;
}

Bitmaps::Colours BitmapSetUp::whiteColours()
{
  Bitmaps::Colours colours;
  colours["red"] = 255;
  colours["green"] = 255;
  colours["blue"] = 255;

  return colours;
}