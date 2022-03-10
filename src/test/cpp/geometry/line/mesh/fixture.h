#pragma once

#include "gtest/gtest.h"
#include "src/main/cpp/geometry/line/mesh.h"

class LineMeshTest : public testing::Test
{
public:
  LineMeshTest();
  ~LineMeshTest();

  void compare();
  void compare(const Geometry::Line& correctLine, const Geometry::Line& line);
  void setupTranslatedLineMeshFromZeroOrigin();
  void setupScaledLineMeshFromZeroOrigin();
  void setupScaledLineMeshFromNonZeroOrigin();
  void setupScaledLineMeshFromDescendingOrigin();
  void setupScaledTranslatedLineMeshFromDescendingOrigin();
  
protected:
  Geometry::LineMesh lineMesh;
  Geometry::LineMesh correctLineMesh;
};