#include "src/test/cpp/bitmaps/reader/fixture.h"
#include "src/main/cpp/bitmaps/reader/headers/file_header_reader.h"
#include "src/main/cpp/bitmaps/reader/headers/dib_header_reader.h"
#include "src/main/cpp/bitmaps/reader/pixel-array/reader.h"

TEST_F(BitmapReaderTest, ShouldReadImageFromFile)
{
  Bitmaps::ImageReader reader;
  auto image = reader.read(this->blueImagePath());
  
  this->compare(image);
}

TEST_F(BitmapReaderTest, ShouldReadFileHeaderFromFile)
{
  Bitmaps::FileHeaderReader reader;
  auto bytes = this->fileContents.slice(0, 14);
  auto header = reader.convertBytes(bytes);

  this->compare(header);
}

TEST_F(BitmapReaderTest, ShouldReadDibHeaderFromFile)
{
  Bitmaps::DibHeaderReader reader;

  auto bytes = this->fileContents.slice(14, 54);
  auto header = reader.convertBytes(bytes);

  this->compare(header);
}

TEST_F(BitmapReaderTest, ShouldReadPixelArrayFromFile)
{
  Bitmaps::PixelArrayReader reader {this->image->pixelArray()->format()};

  auto pixelBytes = this->fileContents.slice(54, this->fileContents.size());
  auto bytesPointer = std::make_shared<ByteArray>(pixelBytes);
  
  auto pixelArray = reader.convertBytes(bytesPointer);

  this->compare(pixelArray);
}