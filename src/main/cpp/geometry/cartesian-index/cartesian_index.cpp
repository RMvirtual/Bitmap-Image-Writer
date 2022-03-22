#include "src/main/cpp/geometry/cartesian-index/cartesian_index.h"

Geometry::CartesianIndex::CartesianIndex(IndexBase indexBase)
{
  this->indexBase = 0;

  if (indexBase == IndexBase::OneIndex)
    this->indexBase = 1;
}

void Geometry::CartesianIndex::setPoint(const double point)
{
  this->_point = point;
}

double Geometry::CartesianIndex::point() const
{
  return this->_point;
}

void Geometry::CartesianIndex::setAxis(const Geometry::AxisName& axis)
{
  this->_axis = {axis};
}

Geometry::Axis Geometry::CartesianIndex::axis() const
{
  return this->_axis;
}