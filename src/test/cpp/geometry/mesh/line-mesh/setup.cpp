#include "src/test/cpp/geometry/mesh/line-mesh/fixture.h"

void LineMeshTest::setupTranslatedLineMeshFromZeroOrigin()
{
  this->lineMesh = {{
    {{0.0, 0.0}, {2, 2}},
    {{2,2}, {5,5}}
  }};

  this->correctLineMesh = {{
    {{2, 2}, {4, 4}},
    {{4,4}, {7,7}}
  }};
}

void LineMeshTest::setupScaledLineMeshFromZeroOrigin()
{
  this->lineMesh = {{
    {{0.0, 0.0}, {2, 2}},
    {{2,2}, {5,5}}
  }};

  this->correctLineMesh = {{
    {{0.0, 0.0}, {4, 4}},
    {{4,4}, {10,10}}
  }};
}

void LineMeshTest::setupScaledLineMeshFromNonZeroOrigin()
{
  this->lineMesh = {{
    {{2, 2}, {5, 5}},
    {{5,5}, {8,8}}
  }};

  this->correctLineMesh = {{
    {{2, 2}, {8, 8}},
    {{8,8}, {14,14}}
  }};
}