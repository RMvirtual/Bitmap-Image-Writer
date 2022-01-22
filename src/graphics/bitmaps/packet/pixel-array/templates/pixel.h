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
Pixels::Pixel<Colours>::Pixel()
{
  // pass.
}

template <class Colours>
Pixels::Pixel<Colours>::Pixel(const Colours& colours)
{
  this->_colours = colours;
}

template <class Colours>
void Pixels::Pixel<Colours>::setColours(const Colours& colours)
{
  this->_colours = colours;
}

template <class Colours>
Colours Pixels::Pixel<Colours>::colours() const
{
  return this->_colours;
}

#endif