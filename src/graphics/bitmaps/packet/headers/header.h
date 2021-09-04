#ifndef BITMAP_HEADER_H
#define BITMAP_HEADER_H

namespace BitmapHeaders {
class Header
{
public:
  Header();
  Header(int sizeOfHeaderInBytes);
  
  virtual char* toBytes() = 0;
  int getSizeOfHeaderInBytes();
  void setSizeOfHeaderInBytes(int size);

private:
  int sizeOfHeaderInBytes;
};}

#endif