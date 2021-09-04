#include "src/graphics/bitmaps/packet/pixels/pixel.h"
#include "src/graphics/bitmaps/packet/pixels/pixel_array.h"
#include "src/graphics/bitmaps/reader/bitmap_reader.h"
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

PixelArray BitmapSetUp::setUpBluePixelArray()
{
  std::vector<Pixel> pixels;
  Pixel bluePixel{100, 255, 255};

  int imageWidth = 512, imageHeight = 512;
  int totalPixels = imageWidth * imageHeight;

  for (int pixelNo = 0; pixelNo < totalPixels; pixelNo++)
    pixels.push_back(bluePixel);

  PixelArray pixelArray = PixelArray{pixels, imageWidth, imageHeight};

  return pixelArray;
}

BitmapImage BitmapSetUp::setUpBlueBitmapImage()
{
  BitmapHeaders::FileHeader fileHeader = setUpBluePixelFileHeader();
  BitmapHeaders::DibHeader dibHeader = setUpBluePixelDibHeader();
  PixelArray pixelArray = setUpBluePixelArray();

  BitmapImage bitmapImage{fileHeader, dibHeader, pixelArray};

  return bitmapImage;
}

std::string BitmapSetUp::getBlueImagePath()
{
  std::string imagePath =
      "C:\\Users\\rmvir\\Desktop\\scc300-Win3D\\test\\resources\\"
      "correct-resources\\blueImage512x512.bmp";

  return imagePath;
}