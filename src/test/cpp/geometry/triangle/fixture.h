#pragma once

#include "gtest/gtest.h"
#include "src/main/cpp/geometry/triangle/triangle.h"

class TriangleTest : public testing::Test
{
public:
  TriangleTest();
  ~TriangleTest();

protected:
  Geometry::Triangle triangle;

  void compare(
    Geometry::Triangle& correctTriangle, Geometry::Triangle triangle);

  void compare(
    Maths::Vector& correctVector, Maths::Vector& vector);
};