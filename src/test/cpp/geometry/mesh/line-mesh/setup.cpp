#include "src/test/cpp/geometry/mesh/line-mesh/fixture.h"

void LineMeshTest::setupLineMesh()
{
  this->lineMesh = {{
    {{0.0, 0.0}, {2, 2}},
    {{2,2}, {5,5}}
  }};

  this->correctLineMesh = {{
    {{0.0, 0.0}, {2, 2}},
    {{2,2}, {5,5}}
  }};
}