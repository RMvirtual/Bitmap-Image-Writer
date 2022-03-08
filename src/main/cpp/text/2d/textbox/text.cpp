#include "src/main/cpp/text/2d/textbox/text.h"
#include "src/main/cpp/files/alphabet-2d/file.h"

Text::Text2D::Text2D()
{
  this->_text = "";
  this->scaleFactor = 1;
}

Text::Text2D::Text2D(std::string text)
{
  this->origin = {0.0, 0.0};
  this->scaleFactor = 1;
  this->setText(text);
}

void Text::Text2D::setPadding(double x, double y)
{
  this->_padding.x = x;
  this->_padding.y = y;

  if (this->_text != "")
    this->renderLetters();
}

void Text::Text2D::setText(std::string text)
{
  this->_text = text;

  this->loadBaseLetters();
  this->renderLetters();
}

void Text::Text2D::loadBaseLetters()
{
  this->baseLetters.clear();

  for (auto character : this->_text) {
    auto letter = Files::Alphabet2D::letter({character});
    this->baseLetters.push_back(letter);
  }
}

void Text::Text2D::renderLetters()
{
  this->renderedLetters.clear();

  double xCursor = this->origin["x"];
  double yCursor = this->origin["y"];

  for (auto letter : this->baseLetters) {
    letter.translate({xCursor, yCursor});
    letter.scale(this->scaleFactor);
    
    auto scaledPadding = this->_padding.x * this->scaleFactor;
    xCursor = letter.xUpperBound() + scaledPadding;
    this->renderedLetters.push_back(letter);
  }
}

void Text::Text2D::scale(double scaleFactor)
{
  this->scaleFactor *= scaleFactor;
  this->renderLetters();
}

void Text::Text2D::translate(Maths::Vector translation)
{
  this->origin = this->origin + translation;
  this->renderLetters();
}

std::string Text::Text2D::text()
{
  return this->_text;
}

std::vector<Geometry::LineMesh>::iterator Text::Text2D::begin()
{
  return this->renderedLetters.begin();
}

std::vector<Geometry::LineMesh>::iterator Text::Text2D::end()
{
  return this->renderedLetters.end();
}

std::vector<Geometry::LineMesh>::const_iterator Text::Text2D::begin() const
{
  return this->renderedLetters.begin();
}

std::vector<Geometry::LineMesh>::const_iterator Text::Text2D::end() const
{
  return this->renderedLetters.end();
}

Geometry::LineMesh Text::Text2D::operator [](int index)
{
  return this->renderedLetters[index];
}

int Text::Text2D::size()
{
  return this->renderedLetters.size();
}