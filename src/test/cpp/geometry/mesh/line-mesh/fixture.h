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
  void setupTranslatedLineMeshFromZeroOrigin();
  void setupScaledLineMeshFromZeroOrigin();
  void setupScaledLineMeshFromNonZeroOrigin();
  void setupScaledLineMeshFromDescendingOrigin();
  void setupScaledTranslatedLineMeshFromDescendingOrigin();
  
protected:
  Geometry::LineMesh lineMesh;
  Geometry::LineMesh correctLineMesh;
};