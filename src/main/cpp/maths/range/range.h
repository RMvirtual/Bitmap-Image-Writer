#pragma once

#include <vector>
#include <src/main/cpp/maths/vector/vector.h>

namespace Maths
{
  std::vector<Maths::Vector> cartesianProduct(
    std::vector<double> set1, std::vector<double> set2);
  
  std::vector<double> range(double lowerBound, double upperBound);
  double lowerBound(double value1, double value2);
  double upperBound(double value1, double value2);
}