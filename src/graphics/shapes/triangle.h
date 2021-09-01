#include <vector>
#include "src/maths/vector/vector.h"

namespace Shapes {
class Triangle
{
public:
  Triangle(std::vector<Maths::Vector> vertices);
  std::vector<Maths::Vector> vertices;
  
};
}