#include "src/graphics/bitmaps/packet/pixels/pixel.h"
#include "src/graphics/bitmaps/packet/pixels/pixel_array.h"
#include "src/graphics/bitmaps/bitmap_image.h"
#include "test/src/graphics-tests/utilities/bitmap_image_comparators.h"
#include "test/src/graphics-tests/utilities/bitmap_set_up.h"

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
  BitmapHeaders::DibHeader dibHeader;

  dibHeader.setSizeOfHeaderInBytes(40);
  dibHeader.setWidthInPixels(512);
  dibHeader.setHeightInPixels(512);
  dibHeader.setNumberOfColourPlanes(1);

  return dibHeader;
}

Pixels::PixelArray BitmapSetUp::setUpBluePixelArray()
{
  std::vector<Pixels::Pixel> pixels;
  Pixels::Pixel bluePixel{100, 255, 255};

  int imageWidth = 512, imageHeight = 512;
  int totalPixels = imageWidth * imageHeight;

  for (int pixelNo = 0; pixelNo < totalPixels; pixelNo++)
    pixels.push_back(bluePixel);

  return Pixels::PixelArray {pixels, imageWidth, imageHeight};
}

BitmapImage BitmapSetUp::setUpBlueBitmapImage()
{
  BitmapImageHeaders headers;
  headers.fileHeader = setUpBluePixelFileHeader();
  headers.dibHeader = setUpBluePixelDibHeader();
  headers.pixelArray = setUpBluePixelArray();

  return BitmapImage::fromHeaders(headers);
}

std::string BitmapSetUp::getBlueImagePath()
{
  return (
      "C:\\Users\\rmvir\\Desktop\\scc300-Win3D\\test\\resources\\"
      "correct-resources\\blueImage512x512.bmp"
  );
}