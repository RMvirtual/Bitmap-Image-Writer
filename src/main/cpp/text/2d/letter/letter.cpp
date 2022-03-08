#include "src/main/cpp/text/2d/letter/letter.h"
#include "src/main/cpp/files/alphabet-2d/file.h"

Text::Letter::Letter(std::string letter)
{
  this->loadLetterFromFile(letter);
}

Text::Letter::Letter(char letter)
{
  this->loadLetterFromFile({letter});
}

void Text::Letter::loadLetterFromFile(std::string letter)
{
  this->templateMesh = Files::Alphabet2D::letter(letter);
  this->scaleFactor = 1;

  this->translationFromOrigin = {
    this->templateMesh.xLowerBound(), this->templateMesh.yLowerBound()};

  this->initialiseTransformedMesh();
}

void Text::Letter::initialiseTransformedMesh()
{
  this->transformedMesh = this->templateMesh;
}

void Text::Letter::scale(double scaleFactor)
{
  for (auto& line : this->transformedMesh)
    line.scaleIncludingOrigin(scaleFactor);
}

void Text::Letter::translate(Maths::Vector translation)
{
  for (auto& line : this->transformedMesh)
    line.translate(translation);
}

double Text::Letter::xUpperBound()
{
  return this->transformedMesh.xUpperBound();
}

double Text::Letter::xLowerBound()
{
  return this->transformedMesh.xLowerBound();
}

double Text::Letter::yUpperBound()
{
  return this->transformedMesh.yUpperBound();
}

double Text::Letter::yLowerBound()
{
  return this->transformedMesh.yLowerBound();
}

Geometry::Line& Text::Letter::operator [](int index)
{
  return this->transformedMesh[index];
}

std::vector<Geometry::Line>::iterator Text::Letter::begin()
{
  return this->transformedMesh.begin();
}

std::vector<Geometry::Line>::iterator Text::Letter::end()
{
  return this->transformedMesh.end();
}

std::vector<Geometry::Line>::const_iterator Text::Letter::begin() const
{
  return this->transformedMesh.begin();
}

std::vector<Geometry::Line>::const_iterator Text::Letter::end() const
{
  return this->transformedMesh.end();
}

int Text::Letter::noOfLines()
{
  return this->templateMesh.size();
}