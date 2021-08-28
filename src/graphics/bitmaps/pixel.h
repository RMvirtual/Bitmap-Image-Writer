#ifndef PIXEL_H
#define PIXEL_H

#include <cstdint>

class Pixel
{
public:
  Pixel(uint8_t red, uint8_t green, uint8_t blue);
  char* toBytes();

  void setRed(uint8_t value);
  void setGreen(uint8_t value);
  void setBlue(uint8_t value);

  uint8_t getRed();
  uint8_t getGreen();
  uint8_t getBlue();

private:
  uint8_t red;
  uint8_t green;
  uint8_t blue;
};

#endif