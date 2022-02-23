#include "src/main/bitmaps/formats/colours/colours.h"

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

int Bitmaps::Colours::size() const
{
  return this->_colours.size();
}

uint8_t Bitmaps::Colours::operator [](std::string colourName) const
{
  return this->_colours.at(colourName);
}

uint8_t& Bitmaps::Colours::operator [](std::string colourName)
{
  return this->_colours[colourName];
}

uint8_t Bitmaps::Colours::operator [](int index) const
{
  auto iterator = this->_colours.begin();

  for (int i = 0; i < index; i++)
    iterator++;
  
  return iterator->second;
}

uint8_t& Bitmaps::Colours::operator [](int index)
{
  auto iterator = this->_colours.begin();

  for (int i = 0; i < index; i++)
    iterator++;
  
  return iterator->second;
}

std::map<std::string, uint8_t>::iterator Bitmaps::Colours::begin()
{
  return this->_colours.begin();
}

std::map<std::string, uint8_t>::iterator Bitmaps::Colours::end()
{
  return this->_colours.end();
}

std::map<std::string, uint8_t>::const_iterator Bitmaps::Colours::begin() const
{
  return this->_colours.begin();
}

std::map<std::string, uint8_t>::const_iterator Bitmaps::Colours::end() const
{
  return this->_colours.end();
}