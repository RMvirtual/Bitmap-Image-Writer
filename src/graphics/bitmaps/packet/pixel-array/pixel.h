#ifndef PIXEL_H
#define PIXEL_H

namespace Pixels {
template <class Colours>
class Pixel
{
public:
  Pixel();
  Pixel(const Colours& colours);
  
  void setColours(const Colours& colours);
  Colours colours() const;

private:
  Colours _colours;
};}

template <class Colours>
Pixels::Pixel::Pixel()
{
  // pass.
}

template <class Colours>
Pixels::Pixel::Pixel(const Colours& colours)
{
  this->_colours = colours;
}

template <class Colours>
void Pixels::Pixel::setColours(const Colours& colours);
{
  this->_colours = colours;
}

template <class Colours>
Colours Pixels::Pixel::colours() const;
{
  return this->colours;
}

#endif