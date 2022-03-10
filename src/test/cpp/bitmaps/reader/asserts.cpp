#include "src/test/cpp/bitmaps/reader/fixture.h"

void BitmapReaderTest::compare(std::shared_ptr<Bitmaps::Image> image)
{
  this->compare(image->fileHeader());
  this->compare(image->dibHeader());
  this->compare(image->pixelArray());
}

void BitmapReaderTest::compare(std::shared_ptr<Bitmaps::FileHeader> header)
{
  auto& correctHeader = this->image->fileHeader();

  EXPECT_EQ(correctHeader->signatureBytes(), header->signatureBytes());

  // 54 header bytes + 16 pixel bytes = 70 bytes.
  // Pixel bytes = (2row x 2column x 3pixelSize + (2row x 2 row padding bytes))
  EXPECT_EQ(70, header->fileSizeInBytes());
  EXPECT_EQ(correctHeader->reservedBytes(), header->reservedBytes());

  EXPECT_EQ(
    correctHeader->pixelArrayOffsetInBytes(), header->pixelArrayOffsetInBytes());
}

void BitmapReaderTest::compare(std::shared_ptr<Bitmaps::DibHeader> header)
{
  auto correctHeader = this->image->dibHeader();

  EXPECT_EQ(correctHeader->headerSizeInBytes(), header->headerSizeInBytes());
  EXPECT_EQ(correctHeader->widthInPixels(), header->widthInPixels());
  EXPECT_EQ(correctHeader->heightInPixels(), header->heightInPixels());
  EXPECT_EQ(correctHeader->numberOfColorPlanes(), header->numberOfColorPlanes());
  EXPECT_EQ(correctHeader->bitsPerPixel(), header->bitsPerPixel());
  EXPECT_EQ(correctHeader->compressionMethod(), header->compressionMethod());
  
  /* Commented these out for now */
  
  // EXPECT_EQ(correctHeader->sizeOfPixelArray(), header.sizeOfPixelArray());
  // EXPECT_EQ(correctHeader->horizontalResolution(), header.horizontalResolution());
  // EXPECT_EQ(correctHeader->verticalResolution(), header.verticalResolution());
  EXPECT_EQ(correctHeader->colorTableEntries(), header->colorTableEntries());
  EXPECT_EQ(correctHeader->importantColors(), header->importantColors());
}

void BitmapReaderTest::compare(std::shared_ptr<Bitmaps::PixelArray> array)
{
  auto correctArray = this->image->pixelArray();
  int noOfPixels = array->sizeInPixels();

  ASSERT_EQ(correctArray->sizeInPixels(), noOfPixels);

  for (int pixelNo = 0; pixelNo < noOfPixels; pixelNo++) {
    auto correctColours = correctArray->at(pixelNo);
    auto colours = correctArray->at(pixelNo);

    int noOfColours = correctColours->size();

    for (int colourNo = 0; colourNo < noOfColours; colourNo++)
      EXPECT_EQ((*correctColours)[colourNo], (*colours)[colourNo]);
  }  
}