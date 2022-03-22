#include "src/main/cpp/geometry/cartesian-index/axis.h"

Geometry::Axis::Axis()
{
  this->initialiseAxisStrings();
  this->axisName = Geometry::AxisName::x;
}

Geometry::Axis::Axis(const Geometry::AxisName& name)
{
  this->initialiseAxisStrings();
  this->axisName = name;
}

void Geometry::Axis::initialiseAxisStrings()
{
  this->axisStrings = {
    {Geometry::AxisName::x, "x"}, {Geometry::AxisName::y, "y"},
    {Geometry::AxisName::z, "z"}, {Geometry::AxisName::w, "w"}
  };
}

bool Geometry::Axis::operator ==(const Geometry::Axis& otherAxis) const
{
  return this->toString() == otherAxis.toString();
}

bool Geometry::Axis::operator ==(const Geometry::AxisName& name) const
{
  return this->axisName == name;
}

std::string Geometry::Axis::toString() const
{
  return this->axisStrings.at(this->axisName);
}