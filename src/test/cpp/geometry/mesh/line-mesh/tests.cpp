#include "gtest/gtest.h"
#include "src/test/cpp/geometry/mesh/line-mesh/fixture.h"

TEST_F(LineMeshTest, ShouldTranslateLineMesh)
{
  this->lineMesh.translate({2,2});
  this->compare();
}
