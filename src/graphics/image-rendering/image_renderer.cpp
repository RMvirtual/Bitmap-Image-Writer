#include <cstdint>

#include "src/graphics/colours/colours.h"
#include "src/graphics/image-rendering/image_renderer.h"
#include "src/graphics/bitmaps/packet/headers/file_header.h"
#include "src/graphics/bitmaps/packet/headers/dib_header.h"
#include "src/graphics/bitmaps/packet/pixels/pixel_array.h"
#include "src/graphics/bitmaps/packet/pixels/pixel_data.h"
#include "src/graphics/bitmaps/packet/pixels/pixel.h"

ImageRendering::ImageRenderer::ImageRenderer()
{
  this->bitmapImage = {};
}

BitmapImage ImageRendering::ImageRenderer::toBitmap()
{
  return this->bitmapImage;
}

void ImageRendering::ImageRenderer::fill(Colours colours)
{
  std::vector<Pixels::RGBPixel> pixels;

  int widthInPixels = this->bitmapImage.getWidthInPixels();
  int heightInPixels = this->bitmapImage.getHeightInPixels();

  int totalPixels = this->bitmapImage.getNumberOfPixels();

  Pixels::PixelData pixelData;
  pixelData.colours = colours;

  for (int rowNo = 0; rowNo < heightInPixels; rowNo++) {
    for (int columnNo = 0; columnNo < widthInPixels; columnNo++) {
      pixelData.rowNo = rowNo;
      pixelData.columnNo = columnNo;
      
      this->setPixel(pixelData);
    }
  }
}

void ImageRendering::ImageRenderer::setPixel(Pixels::PixelData pixelData)
{
  this->bitmapImage.setPixel(pixelData);
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