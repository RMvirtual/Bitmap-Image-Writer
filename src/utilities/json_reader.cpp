#include "lib/nlohmann/json.hpp"
#include "src/utilities/json_reader.h"

#include <iostream>
#include <fstream>
#include <string>

Utilities::JSONReader::JSONReader()
{
}

std::string Utilities::JSONReader::getFormatName(int index)
{
  using json = nlohmann::json;

  std::ifstream fileInput {"C://Users/rmvir/Desktop/scc300-Win3D/resources/pixel_formats.json"};
  auto jsonReading = json::parse(fileInput);

  fileInput.close();

  auto object = jsonReading.at(0);
  auto value = object.at("shortName");

  return value;
}