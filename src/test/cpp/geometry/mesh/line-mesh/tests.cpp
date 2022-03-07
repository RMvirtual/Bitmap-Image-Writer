#include "gtest/gtest.h"
#include "src/test/cpp/geometry/mesh/line-mesh/fixture.h"

TEST_F(LineMeshTest, ShouldTranslateLineMesh)
{
  this->setupTranslatedLineMeshFromZeroOrigin();

  this->lineMesh.translate({2,2});
  this->compare();
}

TEST_F(LineMeshTest, ShouldScaleLineMesh)
{
  this->setupScaledLineMeshFromZeroOrigin();

  this->lineMesh.scale(2);
  this->compare();
}

TEST_F(LineMeshTest, ShouldScaleLineMeshFromNonZeroOrigin)
{
  this->setupScaledLineMeshFromNonZeroOrigin();

  this->lineMesh.scale(2);
  this->compare();
}