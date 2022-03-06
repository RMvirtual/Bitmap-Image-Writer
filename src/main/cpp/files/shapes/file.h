#pragma once

#include <string>
#include <vector>

#include "src/main/cpp/files/json-reader/json_reader.h"

namespace Files {
class Alphabet
{
public:
  Alphabet();

  std::vector<std::vector<double>> letter(std::string letter);
  
private:
  Files::JSONReader reader;
};}