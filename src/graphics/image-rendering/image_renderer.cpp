#include <cstdint>

#include "src/graphics/image-rendering/image_renderer.h"
#include "src/graphics/bitmaps/packet/headers/file_header.h"
#include "src/graphics/bitmaps/packet/headers/dib_header.h"
#include "src/graphics/bitmaps/packet/pixels/pixel_array.h"
#include "src/graphics/bitmaps/packet/pixels/pixel.h"

ImageRendering::ImageRenderer::ImageRenderer()
{
  this->bitmapImage;

  this->widthInPixels = 0;
  this->heightInPixels = 0;
}

BitmapImage ImageRendering::ImageRenderer::toBitmap()
{
  return this->bitmapImage;
}

void ImageRendering::ImageRenderer::fill(
  uint8_t red, uint8_t green, uint8_t blue)
{
  this->calculateFileSize();

  std::vector<Pixel> pixels;
  Pixel pixel {red, green, blue};

  int totalPixels = this->widthInPixels * this->heightInPixels;

  for (int pixelNo = 0; pixelNo < totalPixels; pixelNo++)
    pixels.push_back(pixel);
  

  PixelArray pixelArray = PixelArray {
    pixels, this->widthInPixels, this->heightInPixels};
  
  this->bitmapImage.setPixelArray(pixelArray);
}

void ImageRendering::ImageRenderer::setWidth(int widthInPixels)
{
  this->widthInPixels = widthInPixels;
  BitmapDibHeader dibHeader = this->bitmapImage.getDibHeader();
  dibHeader.setWidthInPixels(widthInPixels);
  
  this->bitmapImage.setDibHeader(dibHeader);

  this->calculateFileSize();
}

void ImageRendering::ImageRenderer::setHeight(int heightInPixels)
{
  this->heightInPixels = heightInPixels;

  BitmapDibHeader dibHeader = this->bitmapImage.getDibHeader();
  dibHeader.setHeightInPixels(heightInPixels);
  
  this->bitmapImage.setDibHeader(dibHeader);

  this->calculateFileSize();
}

void ImageRendering::ImageRenderer::calculateFileSize()
{
  BitmapFileHeader fileHeader = this->bitmapImage.getFileHeader();

  int pixelArraySize = this->widthInPixels * this->heightInPixels * 3;
  fileHeader.setSizeOfBitmapFile(54 + pixelArraySize);

  this->bitmapImage.setFileHeader(fileHeader);
}

int ImageRendering::ImageRenderer::getFileSize()
{
  BitmapFileHeader fileHeader = this->bitmapImage.getFileHeader();
  
  return fileHeader.getSizeOfBitmapFile();
}