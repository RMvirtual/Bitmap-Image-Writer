#include <gtest/gtest.h>

#include "test/src/bitmaps/reader/fixture.h"
#include "src/bitmaps/reader/headers/file_header_reader.h"
#include "src/bitmaps/reader/headers/dib_header_reader.h"
#include "src/bitmaps/reader/pixel-array/reader.h"

TEST_F(BitmapReaderTest, ShouldReadFileHeaderFromFile)
{
  Bitmaps::FileHeaderReader reader {};
  auto bytes = this->fileContents.slice(0, 14);
  auto header = reader.convertBytes(bytes);

  this->compare(header);
}

TEST_F(BitmapReaderTest, ShouldReadDibHeaderFromFile)
{
  EXPECT_TRUE(false);
}

TEST_F(BitmapReaderTest, ShouldReadPixelArrayFromFile)
{
  EXPECT_TRUE(false);
}