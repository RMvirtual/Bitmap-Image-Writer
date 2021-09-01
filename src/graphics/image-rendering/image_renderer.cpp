#include <cstdint>

#include "src/graphics/image-rendering/image_renderer.h"
#include "src/graphics/bitmaps/packet/headers/file_header.h"
#include "src/graphics/bitmaps/packet/headers/dib_header.h"
#include "src/graphics/bitmaps/packet/pixels/pixel_array.h"
#include "src/graphics/bitmaps/packet/pixels/pixel.h"

ImageRendering::ImageRenderer::ImageRenderer()
{
  this->bitmapImage;
}

BitmapImage ImageRendering::ImageRenderer::toBitmap()
{
  return this->bitmapImage;
}

void ImageRendering::ImageRenderer::fill(
  uint8_t red, uint8_t green, uint8_t blue)
{
  std::vector<Pixel> pixels;
  Pixel pixel {red, green, blue};

  int widthInPixels = this->bitmapImage.getWidthInPixels();
  int heightInPixels = this->bitmapImage.getHeightInPixels();

  int totalPixels = this->bitmapImage.getNumberOfPixels();

  for (int pixelNo = 0; pixelNo < totalPixels; pixelNo++)
    pixels.push_back(pixel);
  

  PixelArray pixelArray = PixelArray {
    pixels, widthInPixels, heightInPixels};
  
  this->bitmapImage.setPixelArray(pixelArray);
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
  BitmapFileHeader fileHeader = this->bitmapImage.getFileHeader();
  
  return fileHeader.getSizeOfBitmapFile();
}