#ifndef PIXEL_COLOURS_H
#define PIXEL_COLOURS_H

#include <initializer_list>
#include <string>
#include <map>
#include <vector>

namespace Bitmaps {
class Colours
{
public:
  Colours();
  Colours(std::initializer_list<std::string> colourNames);
  Colours(std::vector<std::string> colourNames);

  std::vector<std::string> names();
  int size();
  int& operator [](std::string value);
  int operator [](std::string value) const;
  std::map<std::string, int>::iterator begin();
  std::map<std::string, int>::iterator end();
  std::map<std::string, int>::const_iterator begin() const;
  std::map<std::string, int>::const_iterator end() const;

private:
  std::map<std::string, int> _colours;
};}

#endif