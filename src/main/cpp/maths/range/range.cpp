#include "src/main/cpp/maths/range/range.h"

std::vector<Maths::Vector> Maths::cartesianProduct(
  std::vector<double> set1, std::vector<double> set2)
{
  std::vector<Maths::Vector> cartesianProduct;

  for (auto x : set1)
    for (auto y : set2)
      cartesianProduct.push_back({x,y});

  return cartesianProduct;
}

std::vector<double> Maths::range(double value1, double value2)
{
  auto lowerBound = Maths::lowerBound(value1, value2);
  auto upperBound = Maths::upperBound(value1, value2);

  std::vector<double> range;

  for (int i = lowerBound; i <= upperBound; i++)
    range.push_back(i);

  return range;
}

double Maths::lowerBound(double value1, double value2)
{
  return value1 < value2 ? value1 : value2;
}

double Maths::upperBound(double value1, double value2)
{
  return value1 > value2 ? value1 : value2;
}