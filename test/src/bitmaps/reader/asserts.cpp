#include "test/src/bitmaps/reader/fixture.h"
#include "src/bitmaps/reader/headers/file_header_reader.h"
#include "src/bitmaps/reader/headers/dib_header_reader.h"
#include "src/bitmaps/reader/pixel-array/reader.h"

void BitmapReaderTest::compare(const Bitmaps::FileHeader& header)
{
  EXPECT_TRUE(false);  
}

void BitmapReaderTest::compare(const Bitmaps::DibHeader& header)
{
  EXPECT_TRUE(false);
}

void BitmapReaderTest::compare(Bitmaps::PixelArray& array)
{
  EXPECT_TRUE(false);
}