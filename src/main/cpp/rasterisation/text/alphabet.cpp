#include "src/main/cpp/rasterisation/text/alphabet.h"
#include "src/main/cpp/files/shapes/file.h"

Geometry::LineMesh Rasterisation::letter(std::string letter)
{
  Files::Alphabet alphabet {};
  auto points = alphabet.letter(letter);
  
  return {points};
}