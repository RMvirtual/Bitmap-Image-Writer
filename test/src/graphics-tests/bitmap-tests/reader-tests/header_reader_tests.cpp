#include <gtest/gtest.h>

#include "src/graphics/bitmaps/packet/pixels/pixel.h"
#include "src/graphics/bitmaps/packet/pixels/pixel_array.h"
#include "src/graphics/bitmaps/reader/bitmap_reader.h"
#include "src/graphics/bitmaps/bitmap_image.h"
#include "test/src/graphics-tests/utilities/bitmap_image_comparators.h"
#include "test/src/graphics-tests/utilities/bitmap_set_up.h"

TEST(BitmapHeaderReaderTests, ShouldExtractFileHeaderFromFile)
{ 
  std::string imagePath = BitmapSetUp::getBlueImagePath();

  BitmapHeaders::FileHeader fileHeader = 
    BitmapReader::getBitmapFileHeader(imagePath);
  
  BitmapHeaders::FileHeader correctFileHeader = 
    BitmapSetUp::setUpBluePixelFileHeader();
  
  BitmapImageComparison::compareBitmapFileHeaders(
    correctFileHeader, fileHeader);
}

TEST(BitmapHeaderReaderTests, ShouldExtractDibHeaderFromFile)
{
  std::string imagePath = BitmapSetUp::getBlueImagePath();

  BitmapHeaders::DibHeader dibHeader =
    BitmapReader::getBitmapDibHeader(imagePath);
  
  BitmapHeaders::DibHeader correctDibHeader = 
    BitmapSetUp::setUpBluePixelDibHeader();

  BitmapImageComparison::compareBitmapDibHeaders(correctDibHeader, dibHeader);
}