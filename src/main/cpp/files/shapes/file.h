#pragma once

#include <string>
#include "src/main/cpp/files/json-reader/json_reader.h"
#include "src/main/cpp/geometry/mesh/line_mesh.h"

namespace Files {
class Alphabet
{
public:
  Alphabet();

  Geometry::LineMesh letter(std::string letter);

private:
  Files::JSONReader reader;
};}