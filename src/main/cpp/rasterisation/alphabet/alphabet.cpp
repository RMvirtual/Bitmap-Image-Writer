#include "src/main/cpp/rasterisation/alphabet/alphabet.h"

std::vector<Geometry::Line> Rasterisation::letterH(double scale)
{
  Geometry::Line leftEdge {{0.0, 0.0}, {0.0, 3 * scale}};
  Geometry::Line middleEdge {{0.0, 2 * scale}, {2 * scale, 2 * scale}};
  Geometry::Line rightEdge {{2 * scale, 0.0}, {2 * scale, 3 * scale}};

  return {leftEdge, middleEdge, rightEdge};
}