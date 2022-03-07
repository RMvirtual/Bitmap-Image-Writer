#pragma once

#include "gtest/gtest.h"
#include "src/main/cpp/geometry/mesh/line_mesh.h"

class LineMeshTest : public testing::Test
{
public:
  LineMeshTest();
  ~LineMeshTest();

  void compare();
  void compare(Geometry::Line correctLine, Geometry::Line line);
  void setupLineMesh();

protected:
  Geometry::LineMesh lineMesh;
  Geometry::LineMesh correctLineMesh;
};