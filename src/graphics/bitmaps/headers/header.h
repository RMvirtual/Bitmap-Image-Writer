#ifndef BITMAP_HEADER_H
#define BITMAP_HEADER_H

class BitmapHeader
{
public:
  BitmapHeader();
  BitmapHeader(int sizeOfHeaderInBytes);
  
  virtual char* toBytes() = 0;
  int getSizeOfHeaderInBytes();
  void setSizeOfHeaderInBytes(int size);

private:
  int sizeOfHeaderInBytes;
};

#endif