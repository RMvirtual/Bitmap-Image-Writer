#include <vector>
#include "src/maths/vector/vector.h"

namespace Shapes {
  class StraightLine
  {
  public:
    StraightLine();
    StraightLine(Maths::Vector endPoint);
    Maths::Vector endPoint;
  };
}