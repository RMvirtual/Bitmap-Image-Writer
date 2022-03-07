#include "src/main/cpp/text/2d/text.h"
#include "src/main/cpp/files/alphabet-2d/file.h"

Text::Text2D::Text2D()
{
  this->scaleFactor = 1;
}

Text::Text2D::Text2D(std::string text)
{
  this->scaleFactor = 1;
  this->setText(text);
}

void Text::Text2D::setPadding(double x, double y)
{
  this->_padding.x = x;
  this->_padding.y = y;

  this->setText(this->_text);
}

void Text::Text2D::setText(std::string text)
{
  this->letters.clear();
  this->_text = text;

  double xCursor = 0;
  double yCursor = 0;

  bool isFirstLetter = true;

  for (auto character : this->_text) {
    auto letter = Files::Alphabet2D::letter({character});

    if (isFirstLetter)
      isFirstLetter = false;
    
    else {
      letter.translate({xCursor, yCursor});
      letter.translate({this->_padding.x, this->_padding.y});
    }

    letter.scale(this->scaleFactor);
    
    xCursor = letter.xMaximum();
    yCursor = letter.yMinimum();

    this->letters.push_back(letter);
  }
}

void Text::Text2D::scale(double scaleFactor)
{
  this->scaleFactor = scaleFactor;

  for (auto& letter : this->letters)
    letter.scale(this->scaleFactor);

  this->setText(this->_text);
}

void Text::Text2D::translate(Maths::Vector translation)
{
  for (auto& letter : this->letters)
    letter.translate(translation);
}

std::string Text::Text2D::text()
{
  return this->_text;
}

std::vector<Geometry::LineMesh>::iterator Text::Text2D::begin()
{
  return this->letters.begin();
}

std::vector<Geometry::LineMesh>::iterator Text::Text2D::end()
{
  return this->letters.end();
}

std::vector<Geometry::LineMesh>::const_iterator Text::Text2D::begin() const
{
  return this->letters.begin();
}

std::vector<Geometry::LineMesh>::const_iterator Text::Text2D::end() const
{
  return this->letters.end();
}

Geometry::LineMesh Text::Text2D::operator [](int index)
{
  return this->letters[index];
}

int Text::Text2D::size()
{
  return this->letters.size();
}