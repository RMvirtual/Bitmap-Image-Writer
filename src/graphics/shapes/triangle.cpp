#include "src/graphics/shapes/triangle.h"
#include "src/maths/vector/vector.h"

Shapes::Triangle::Triangle(std::vector<Maths::Vector> vertices)
{
  this->vertices = vertices;
}

