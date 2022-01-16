#ifndef RGB_COLOURS_H
#define RGB_COLOURS_H

#include <cstdint>

namespace Pixels {
class RGBColours
{
public:
  RGBColours();
  
  void setRed(uint8_t value);
  void setGreen(uint8_t value);
  void setBlue(uint8_t value);
  uint8_t red() const;
  uint8_t green() const;
  uint8_t blue() const;
  
private:
  uint8_t _red;
  uint8_t _green;
  uint8_t _blue;
};}

#endif