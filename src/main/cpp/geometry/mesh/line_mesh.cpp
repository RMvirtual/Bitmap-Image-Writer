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