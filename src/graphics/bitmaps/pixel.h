#include <cstdint>

class Pixel
{
public:
  Pixel(uint8_t red, uint8_t green, uint8_t blue);
  char* toBytes();

private:
  uint8_t red;
  uint8_t green;
  uint8_t blue;
};