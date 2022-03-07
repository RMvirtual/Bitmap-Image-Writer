#include <algorithm>
#include "src/main/cpp/geometry/mesh/line_mesh.h"

Geometry::LineMesh::LineMesh()
{
  // pass.
}

Geometry::LineMesh::LineMesh(std::vector<Geometry::Line> lines)
{
  this->lines = lines;
}

Geometry::Line& Geometry::LineMesh::operator [](int index)
{
  return this->lines[index];
}

std::vector<Geometry::Line>::iterator Geometry::LineMesh::begin()
{
  return this->lines.begin();
}

std::vector<Geometry::Line>::iterator Geometry::LineMesh::end()
{
  return this->lines.end();
}

std::vector<Geometry::Line>::const_iterator Geometry::LineMesh::begin() const
{
  return this->lines.begin();
}

std::vector<Geometry::Line>::const_iterator Geometry::LineMesh::end() const
{
  return this->lines.end();
}

int Geometry::LineMesh::size()
{
  return this->lines.size();
}

void Geometry::LineMesh::add(Geometry::Line line)
{
  this->lines.push_back(line);
}

Maths::Vector Geometry::LineMesh::origin()
{
  return this->lines[0].origin();  
}

void Geometry::LineMesh::translateToZeroOrigin()
{
  Maths::Vector zeroOrigin = {0.0,0.0};

  auto translationToOrigin = zeroOrigin - this->origin();
  this->translate(translationToOrigin);
}

void Geometry::LineMesh::scale(double scaleFactor)
{
  auto origin = this->origin();
  this->translateToZeroOrigin();

  int noOfLines = this->lines.size();

  for (auto& line : this->lines)
    line.scaleIncludingOrigin(scaleFactor);
}

void Geometry::LineMesh::translate(Maths::Vector translation)
{
  for (auto& line : this->lines)
    line.translate(translation);
}

double Geometry::LineMesh::xMinimum()
{
  double minimum = this->lines[0].xMinimum();

  for (auto line : this->lines)
    minimum = std::min(minimum, line.xMinimum());

  return minimum;
}

double Geometry::LineMesh::xMaximum()
{
  double maximum = this->lines[0].xMaximum();

  for (auto line : this->lines)
    maximum = std::max(maximum, line.xMaximum());

  return maximum;
}

double Geometry::LineMesh::yMinimum()
{
  double minimum = this->lines[0].yMinimum();

  for (auto line : this->lines)
    minimum = std::min(minimum, line.yMinimum());

  return minimum;
}

double Geometry::LineMesh::yMaximum()
{
  double maximum = this->lines[0].yMaximum();

  for (auto line : this->lines)
    maximum = std::min(maximum, line.yMaximum());

  return maximum;
}