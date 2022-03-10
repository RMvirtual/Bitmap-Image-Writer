#pragma once

#include <cstdint>
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

  void set(std::string name, uint8_t value);
  std::vector<std::string> names();
  int size() const;
  uint8_t& operator [](std::string value);
  uint8_t operator [](std::string value) const;
  uint8_t& operator [](int index);
  uint8_t operator [](int index) const;
  std::map<std::string, uint8_t>::iterator begin();
  std::map<std::string, uint8_t>::iterator end();
  std::map<std::string, uint8_t>::const_iterator begin() const;
  std::map<std::string, uint8_t>::const_iterator end() const;

private:
  std::map<std::string, uint8_t> _colours;
};}