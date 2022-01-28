#ifndef PIXEL_COLOURS_H
#define PIXEL_COLOURS_H

#include <unordered_map>

namespace Pixels {
class Colours
{
public:
  Colours();
  int& operator [](std::string value);

private:
  std::unordered_map<std::string, int> _colours;
};}

#endif