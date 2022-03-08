#include "src/main/cpp/text/2d/letter/letter.h"
#include "src/main/cpp/files/alphabet-2d/file.h"

Text::Letter::Letter(std::string letter)
{
  this->initialiseDefaults(letter);
}

Text::Letter::Letter(char letter)
{
  this->initialiseDefaults({letter});
}

void Text::Letter::initialiseDefaults(std::string letter)
{
  this->loadLetterFromFile({letter});
  this->scaleFactor = 1;

  this->translationFromOrigin = {
    this->templateMesh.xLowerBound(), this->templateMesh.yLowerBound()};

  this->transformMesh();
}

void Text::Letter::loadLetterFromFile(std::string letter)
{
  this->templateMesh = Files::Alphabet2D::letter(letter);
}

void Text::Letter::transformMesh()
{
  this->transformedMesh = {};

  for (auto line : this->templateMesh) {
    line.scale(this->scaleFactor);
    line.translate(this->translationFromOrigin);

    this->transformedMesh.add(line);
  }
}

void Text::Letter::scale(double scaleFactor)
{
  this->scaleFactor *= scaleFactor;
  this->transformMesh();
}

void Text::Letter::translate(Maths::Vector translation)
{
  this->translationFromOrigin = this->translationFromOrigin + translation;
  this->transformMesh();
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