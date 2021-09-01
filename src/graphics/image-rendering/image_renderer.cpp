#include <cstdint>

#include "src/graphics/image-rendering/image_renderer.h"
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

  int imageWidth = 512, imageHeight = 512;
  int totalPixels = imageWidth * imageHeight;

  for (int pixelNo = 0; pixelNo < totalPixels; pixelNo++)
    pixels.push_back(pixel);

  PixelArray pixelArray = PixelArray{pixels, imageWidth, imageHeight};
  this->bitmapImage.setPixelArray(pixelArray);
}
