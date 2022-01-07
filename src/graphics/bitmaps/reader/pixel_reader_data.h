#ifndef PIXEL_READER_DATA_H
#define PIXEL_READER_DATA_H

struct PixelReaderData
{
  char* pixelPointer;
  int widthInPixels;
  int heightInPixels;
  int rowSizeInBytes;
  int pixelDataOffset;    
};

#endif