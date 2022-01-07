#ifndef PIXEL_ARRAY_H
#define PIXEL_ARRAY_H

#include <vector>
#include "src/graphics/bitmaps/packet/pixels/pixel.h"
#include "src/common/byte_array_builder.h"
#include "src/graphics/bitmaps/packet/pixels/pixel_data.h"

namespace Pixels {
  class PixelArray
  {
  public:
    std::vector<Pixels::Pixel> pixels;

    PixelArray();
    PixelArray(
      std::vector<Pixels::Pixel> pixels, int widthInPixels, int heightInPixels);
      
    unsigned char* toBytes();

    void setPixel(Pixels::PixelData pixelData);
    void setWidthInPixels(int width);
    void setHeightInPixels(int height);

    Pixels::Pixel getPixel(int rowNo, int columnNo);
    Pixels::Pixel getPixel(int index);
    int getWidthInPixels();
    int getHeightInPixels();
    int sizeInBytes();
    int sizeInPixels();

  private:
    int widthInPixels;
    int heightInPixels;
    int rowSizeInBytes;
    int rowPadding;

    void addAllPixelsToByteArray(ByteArrayBuilder* byteArrayBuilder);
    void addRowOfPixelsToByteArray(int rowNo, ByteArrayBuilder* byteArray);

    void addPixelByIndexToByteArray(
      int rowNo, int columnNo, ByteArrayBuilder* byteArray);

    void addPixelToByteArray(Pixels::Pixel pixel, ByteArrayBuilder* byteArray);
    void addPaddingBytesToByteArray(ByteArrayBuilder* byteArray);
    unsigned char* getRowOfPixelsAsBytes(int rowNo);

    void initialisePixelArray(int widthInPixels, int heightInPixels);
    void populateMissingPixels();
    void addBlankPixels(int numberOfPixelsToAdd);
    void addBlankPixel();
    void calculateRowStride();
    int convertToIndex(int rowNo, int columnNo);
    bool isIndexOutOfBounds(int index);
    int getRowStride();
    int getNumberOfMissingPixels();
  };
}

#endif