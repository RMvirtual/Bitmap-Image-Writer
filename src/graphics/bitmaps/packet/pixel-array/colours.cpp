#include <initializer_list>
#include <string>

#include "src/graphics/bitmaps/packet/pixel-array/colours.h"

Pixels::Colours::Colours()
{

}

Pixels::Colours::Colours(std::initializer_list<std::string> colourNames)
{
  for (auto name : colourNames)
    this->_colours[name] = 0;
}

Pixels::Colours::Colours(std::vector<std::string> colourNames)
{
  for (auto name : colourNames)
    this->_colours[name] = 0;
}

std::vector<std::string> Pixels::Colours::names()
{
  std::vector<std::string> names {};

  for (auto coloursAndValues : this->_colours)
    names.push_back(coloursAndValues.first);

  return names;
}

int& Pixels::Colours::operator [](std::string value)
{
  return this->_colours[value];
}
