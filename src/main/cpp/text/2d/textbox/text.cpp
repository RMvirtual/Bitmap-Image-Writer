#include "src/main/cpp/text/2d/textbox/text.h"
#include "src/main/cpp/files/alphabet-2d/file.h"

Text::Text2D::Text2D()
{
  this->_text = "";
}

Text::Text2D::Text2D(std::string text)
{
  this->_origin = {0.0, 0.0};
  this->setText(text);
}

void Text::Text2D::setPadding(double x, double y)
{
  this->removePadding();
  
  this->_padding.x = x;
  this->_padding.y = y;

  this->addPadding();
}

void Text::Text2D::scalePadding(double scaleFactor)
{
  this->removePadding();

  this->_padding.x *= scaleFactor;
  this->_padding.y *= scaleFactor;

  this->addPadding();
}

void Text::Text2D::setText(std::string text)
{
  this->_text = text;
  this->loadLetters();
}

void Text::Text2D::loadLetters()
{
  this->letters.clear();

  double xCursor = 0.0;
  double yCursor = 0.0;
  
  for (auto character : this->_text) {
    Text::Letter letter {character};
    letter.translate({xCursor, yCursor});

    this->letters.push_back(letter);
    xCursor = letter.xUpperBound();
  }
}

void Text::Text2D::addPadding()
{
  int noOfLetters = this->letters.size();

  for (int letterNo = 0; letterNo < noOfLetters; letterNo++) {
    auto& letter = this->letters[letterNo];
    
    letter.translate(
      {this->_padding.x * letterNo, this->_padding.y * letterNo});
  }
}

void Text::Text2D::removePadding()
{
  int noOfLetters = this->letters.size();

  for (int letterNo = 0; letterNo < noOfLetters; letterNo++) {
    auto& letter = this->letters[letterNo];
    
    letter.translate(
      {0.0 - this->_padding.x * letterNo, 0.0 - this->_padding.y * letterNo});
  }
}

void Text::Text2D::scale(double scaleFactor)
{
  int noOfLetters = this->letters.size();

  // Should be scale, but changing to scaleIncludingOrigin fixes the
  // text 1st character messing up.
  
  // Get the origin x and y for this entire container.

  this->letters[0].scaleIncludingOrigin(scaleFactor);

  for (int letterNo = 1; letterNo < noOfLetters; letterNo++) {
    auto& letter = this->letters[letterNo];
    
    letter.scaleIncludingOrigin(scaleFactor);
  }

  this->scalePadding(scaleFactor);
}

void Text::Text2D::translate(Maths::Vector translation)
{
  for (auto& letter : this->letters)
    letter.translate(translation);
}

Maths::Vector Text::Text2D::origin()
{
  auto xOrigin = this->letters[0].xLowerBound();
  auto yOrigin = this->letters[0].yLowerBound();

  for (auto& letter : this->letters) {
    xOrigin = std::min(xOrigin, letter.xLowerBound());
    yOrigin = std::min(yOrigin, letter.yLowerBound());
  }

  return {xOrigin, yOrigin};
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