#ifndef IMAGE_RENDERER_H
#define IMAGE_RENDERER_H

#include <cstdint>

#include "src/graphics/bitmaps/bitmap_image.h"
#include "src/graphics/bitmaps/packet/pixels/pixel.h"
#include "src/graphics/colours/colours.h"

namespace ImageRendering
{
  class ImageRenderer
  {
  public:
    ImageRenderer();
    
    BitmapImage toBitmap();
    void fill(Colours colours);
    
    void setPixel(Pixels::PixelData pixelData);
    void setWidth(int widthInPixels);
    void setHeight(int heightInPixels);
    int getFileSize();

  private:
    BitmapImage bitmapImage;
  };
}

#endif