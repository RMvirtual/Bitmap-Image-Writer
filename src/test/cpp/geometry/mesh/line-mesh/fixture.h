#pragma once

#include "gtest/gtest.h"
#include "src/main/cpp/geometry/mesh/line_mesh.h"

class LineMeshTest : public testing::Test
{
public:
  LineMeshTest();
  ~LineMeshTest();

protected:
  Geometry::LineMesh lineMesh;

  void setupNorthEastLine();
  void setupNorthWestLine();
  void setupSouthEastLine();
  void setupSouthWestLine();
};