#include "gtest/gtest.h"
#include "src/test/cpp/geometry/line/mesh/fixture.h"

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

TEST_F(LineMeshTest, ShouldGetOriginOfMesh)
{
  this->setupScaledLineMeshFromDescendingOrigin();

  auto origin = this->lineMesh.origin();

  Maths::Vector correctOrigin = {0.0, 0.0};
  EXPECT_EQ(correctOrigin["x"], origin["x"]);
  EXPECT_EQ(correctOrigin["y"], origin["y"]);
}

TEST_F(LineMeshTest, ShouldScaleLineMeshFromNorthEast)
{
  this->setupScaledLineMeshFromDescendingOrigin();

  this->lineMesh.scale(2);
  this->compare();
}

TEST_F(LineMeshTest, ShouldScaleAndTranslateLineMesh)
{
  this->setupScaledTranslatedLineMeshFromDescendingOrigin();
  

}