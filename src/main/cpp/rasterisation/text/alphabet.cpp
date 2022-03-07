#include "src/main/cpp/rasterisation/text/alphabet.h"
#include "src/main/cpp/files/alphabet-2d/file.h"

Geometry::LineMesh Rasterisation::letter(std::string letter)
{
  return Files::Alphabet2D::letter(letter);
}