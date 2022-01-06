#include <cstdint>

#include "src/graphics/image-rendering/image_renderer.h"
#include "src/graphics/bitmaps/packet/headers/file_header.h"
#include "src/graphics/bitmaps/packet/headers/dib_header.h"
#include "src/graphics/bitmaps/packet/pixels/pixel_array.h"
#include "src/graphics/bitmaps/packet/pixels/pixel.h"

ImageRendering::ImageRenderer::ImageRenderer()
{
  this->bitmapImage = {};
}

BitmapImage ImageRendering::ImageRenderer::toBitmap()
{
  return this->bitmapImage;
}

void ImageRendering::ImageRenderer::fill(
  uint8_t red, uint8_t green, uint8_t blue)
{
  std::vector<Pixels::Pixel> pixels;
  Pixels::Pixel pixel {red, green, blue};

  int widthInPixels = this->bitmapImage.getWidthInPixels();
  int heightInPixels = this->bitmapImage.getHeightInPixels();

  int totalPixels = this->bitmapImage.getNumberOfPixels();

  for (int rowNo = 0; rowNo < heightInPixels; rowNo++) {
    for (int columnNo = 0; columnNo < widthInPixels; columnNo++) {
      this->setPixel(rowNo, columnNo, pixel);
    }
  }
}

void ImageRendering::ImageRenderer::setPixel(
  int row, int column, Pixels::Pixel pixel)
{
  this->bitmapImage.setPixel(row, column, pixel);
}

void ImageRendering::ImageRenderer::setWidth(int widthInPixels)
{
  this->bitmapImage.setWidthInPixels(widthInPixels);
}

void ImageRendering::ImageRenderer::setHeight(int heightInPixels)
{
  this->bitmapImage.setHeightInPixels(heightInPixels);
}

int ImageRendering::ImageRenderer::getFileSize()
{
  BitmapHeaders::FileHeader fileHeader = this->bitmapImage.getFileHeader();
  
  return fileHeader.getSizeOfBitmapFile();
}