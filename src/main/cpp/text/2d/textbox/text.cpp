#include "src/main/cpp/text/2d/textbox/text.h"
#include "src/main/cpp/files/alphabet-2d/file.h"

Text::Text2D::Text2D()
{
  this->_text = "";
}

Text::Text2D::Text2D(std::string text)
{
  this->origin = {0.0, 0.0};
  this->setText(text);
}

void Text::Text2D::setPadding(double x, double y)
{
  this->removePadding();
  
  this->_padding.x = x;
  this->_padding.y = y;

  this->addPadding();
}

void Text::Text2D::setText(std::string text)
{
  this->_text = text;
  this->loadBaseLetters();
}

void Text::Text2D::loadBaseLetters()
{
  this->letters.clear();

  double xCursor = 0.0;
  double yCursor = 0.0;
  
  for (auto character : this->_text) {
    Text::Letter letter {character};
    letter.translate({xCursor, yCursor});

    this->letters.push_back(letter);
    xCursor = letter.xUpperBound() + this->_padding.x;
  }
}

void Text::Text2D::recalculatePadding(double scaleFactor)
{
  this->removePadding();

  this->_padding.x *= scaleFactor;
  this->_padding.y *= scaleFactor;

  this->addPadding();
}

void Text::Text2D::addPadding()
{
  int noOfLetters = this->letters.size();

  for (int letterNo = 1; letterNo < noOfLetters; letterNo++) {
    auto& letter = this->letters[letterNo];
    letter.translate({this->_padding.x, this->_padding.y});
  }
}

void Text::Text2D::removePadding()
{
  int noOfLetters = this->letters.size();

  for (int letterNo = 1; letterNo < noOfLetters; letterNo++) {
    auto& letter = this->letters[letterNo];
    letter.translate({0.0 - this->_padding.x, 0.0 - this->_padding.y});
  }
}

void Text::Text2D::scale(double scaleFactor)
{
  for (auto& letter : this->letters)
    letter.scale(scaleFactor);

  this->recalculatePadding(scaleFactor);
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

std::vector<Text::Letter>::iterator Text::Text2D::begin()
{
  return this->letters.begin();
}

std::vector<Text::Letter>::iterator Text::Text2D::end()
{
  return this->letters.end();
}

std::vector<Text::Letter>::const_iterator Text::Text2D::begin() const
{
  return this->letters.begin();
}

std::vector<Text::Letter>::const_iterator Text::Text2D::end() const
{
  return this->letters.end();
}

Text::Letter Text::Text2D::operator [](int index)
{
  return this->letters[index];
}

int Text::Text2D::size()
{
  return this->letters.size();
}