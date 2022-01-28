#include "src/graphics/bitmaps/packet/pixel-array/pixel/colours.h"

Pixels::Colours::Colours()
{

}

int& Pixels::Colours::operator [](std::string value)
{
  return this->_colours[value];
}
