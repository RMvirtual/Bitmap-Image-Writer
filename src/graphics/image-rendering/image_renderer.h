#ifndef IMAGE_RENDERER_H
#define IMAGE_RENDERER_H

#include <cstdint>

#include "src/graphics/bitmaps/bitmap_image.h"

namespace ImageRendering
{
  class ImageRenderer
  {
  public:
    ImageRenderer();
    BitmapImage toBitmap();
    void fill(uint8_t red, uint8_t green, uint8_t blue);
    void setWidth(int widthInPixels);
    void setHeight(int heightInPixels);
    int getFileSize();

  private:
    BitmapImage bitmapImage;
  };
}

#endif