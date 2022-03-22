#pragma once

#include <string>
#include "src/main/cpp/geometry/cartesian-index/axis.h"
#include "src/main/cpp/geometry/cartesian-index/axis_names.h"

namespace Geometry {
class CartesianIndex
{
public:
  enum IndexBase {ZeroIndex, OneIndex};

  CartesianIndex(IndexBase indexBase);

  void setPoint(const double point);
  double point() const;
  void setAxis(const Geometry::AxisName& axis);
  Geometry::Axis axis() const;

private:
  int indexBase;
  Geometry::Axis _axis;
  double _point;
};}