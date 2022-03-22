#pragma once

#include <string>
#include <unordered_map>

#include "src/main/cpp/geometry/cartesian-index/axis_names.h"

namespace Geometry {
class Axis
{
public:
  Axis();
  Axis(const Geometry::AxisName& axisName);
  
  std::string toString() const;
  bool operator ==(const Geometry::Axis& otherAxis) const;
  bool operator ==(const Geometry::AxisName& name) const;

private:
  Geometry::AxisName axisName;
  std::unordered_map<AxisName, std::string> axisStrings;

  void initialiseAxisStrings();
};}