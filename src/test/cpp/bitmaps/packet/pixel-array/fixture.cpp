#include "src/main/cpp/bitmaps/packet/packet.h"
#include "src/main/cpp/bitmaps/packet/headers/headers.h"
#include "src/main/cpp/bitmaps/formats/format/format.h"
#include "src/main/cpp/bitmaps/packet/pixel-array/array.h"
#include "src/main/cpp/bitmaps/formats/colours/colours.h"
#include "src/test/cpp/bitmaps/packet/pixel-array/fixture.h"

PixelArrayTest::PixelArrayTest()
{
  this->setupRedPixelArray(2, 2);
}

PixelArrayTest::~PixelArrayTest()
{
  // pass.
}