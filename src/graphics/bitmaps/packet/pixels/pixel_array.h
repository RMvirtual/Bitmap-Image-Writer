#ifndef PIXEL_ARRAY_H
#define PIXEL_ARRAY_H

#include <vector>
#include "src/graphics/bitmaps/packet/pixels/pixel.h"
#include "src/common/byte_array.h"

namespace Pixels {
class PixelArray
{
public:
  std::vector<Pixels::Pixel> pixels;

  PixelArray();
  PixelArray(
    std::vector<Pixels::Pixel> pixels, int widthInPixels, int heightInPixels);
    
  char* toBytes();
  int sizeInBytes();
  int sizeInPixels();

  void setPixel(Pixels::Pixel pixel, int rowNumber, int columnNo);
  void setWidthInPixels(int width);
  void setHeightInPixels(int height);

  Pixels::Pixel getPixel(int rowNo, int columnNo);
  Pixels::Pixel getPixel(int index);
  int getWidthInPixels();
  int getHeightInPixels();

private:
  int widthInPixels;
  int heightInPixels;
  int rowSizeInBytes;
  int rowPadding;

  void initialisePixelArray(int widthInPixels, int heightInPixels);
  
  int getNumberOfMissingPixels();
  void addBlankPixels(int numberOfPixelsToAdd);
  void addBlankPixel();
  void populateMissingPixels();
  void calculateRowStride();
  char* getRowOfPixelsAsBytes(int rowNo);
  int convertRowAndColumnToIndex(int rowNo, int columnNo);
  int getRowStride();

  void addRowOfPixelsToByteArray(
    int rowNo, ByteArrayBuilder* byteArrayBuilder);

  void addPixelByIndexToByteArray(
    int rowNo, int columnNo, ByteArrayBuilder* byteArrayBuilder);

  void addPixelToByteArray(
    Pixels::Pixel pixel, ByteArrayBuilder* byteArrayBuilder);
  
  void addPaddingBytesToByteArray(ByteArrayBuilder* byteArrayBuilder);

};}

#endif