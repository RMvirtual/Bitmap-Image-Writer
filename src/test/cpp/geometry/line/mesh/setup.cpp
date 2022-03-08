#include "src/test/cpp/geometry/line/mesh/fixture.h"

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

void LineMeshTest::setupScaledLineMeshFromDescendingOrigin()
{
//    [1.5, 2], [0.5, 2],
//    [0.0, 1.5], [0.0, 0.5],
//    [0.5, 0.0], [1.5, 0.0]

  this->lineMesh = {{
    {{1.5, 2}, {0.5, 2}},
    {{0.5, 2}, {0.0, 1.5}},
    {{0.0, 1.5}, {0.0, 0.5}},
    {{0.0, 0.5}, {0.5, 0.0}},
    {{0.5, 0.0}, {1.5, 0.0}}
  }};

  this->correctLineMesh = {{
    {{3, 4}, {1, 4}},
    {{1, 4}, {0.0, 3}},
    {{0.0, 3}, {0.0, 1}},
    {{0.0, 1}, {1, 0.0}},
    {{1, 0.0}, {3, 0.0}}
  }};
}

void LineMeshTest::setupScaledTranslatedLineMeshFromDescendingOrigin()
{
//    [1.5, 2], [0.5, 2],
//    [0.0, 1.5], [0.0, 0.5],
//    [0.5, 0.0], [1.5, 0.0]

  // scale of 2.

  this->lineMesh = {{
    {{1.5, 2}, {0.5, 2}},
    {{0.5, 2}, {0.0, 1.5}},
    {{0.0, 1.5}, {0.0, 0.5}},
    {{0.0, 0.5}, {0.5, 0.0}},
    {{0.5, 0.0}, {1.5, 0.0}}
  }};

  this->correctLineMesh = {{
    {{3, 4}, {1, 4}},
    {{1, 4}, {0.0, 3}},
    {{0.0, 3}, {0.0, 1}},
    {{0.0, 1}, {1, 0.0}},
    {{1, 0.0}, {3, 0.0}}
  }};
}