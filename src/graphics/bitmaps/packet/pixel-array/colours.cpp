#include <initializer_list>
#include <string>

#include "src/graphics/bitmaps/packet/pixel-array/colours.h"

Bitmaps::Colours::Colours()
{

}

Bitmaps::Colours::Colours(std::initializer_list<std::string> colourNames)
{
  for (auto name : colourNames)
    this->_colours[name] = 0;
}

Bitmaps::Colours::Colours(std::vector<std::string> colourNames)
{
  for (auto name : colourNames)
    this->_colours[name] = 0;
}

std::vector<std::string> Bitmaps::Colours::names()
{
  std::vector<std::string> names {};

  for (auto coloursAndValues : this->_colours)
    names.push_back(coloursAndValues.first);

  return names;
}

int Bitmaps::Colours::size()
{
  return this->_colours.size();
}

int Bitmaps::Colours::operator [](std::string colourName) const
{
  return this->_colours.at(colourName);
}

int& Bitmaps::Colours::operator [](std::string colourName)
{
  return this->_colours[colourName];
}

std::unordered_map<std::string, int>::iterator Bitmaps::Colours::begin()
{
  return this->_colours.begin();
}

std::unordered_map<std::string, int>::iterator Bitmaps::Colours::end()
{
  return this->_colours.end();
}

std::unordered_map<std::string, int>::const_iterator
Bitmaps::Colours::begin() const
{
  return this->_colours.begin();
}

std::unordered_map<std::string, int>::const_iterator
Bitmaps::Colours::end() const
{
  return this->_colours.end();
}