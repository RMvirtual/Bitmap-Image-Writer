#ifndef PIXEL_COLOURS_H
#define PIXEL_COLOURS_H

#include <initializer_list>
#include <string>
#include <unordered_map>
#include <vector>

namespace Pixels {
class Colours
{
public:
  Colours();
  Colours(std::initializer_list<std::string> colourNames);
  Colours(std::vector<std::string> colourNames);

  std::vector<std::string> names();
  int& operator [](std::string value);
  int operator [](std::string value) const;
  
private:
  std::unordered_map<std::string, int> _colours;
};}

#endif