#include "lib/nlohmann/json.hpp"
#include "src/utilities/json_reader.h"

#include <iostream>
#include <fstream>
#include <string>

Utilities::JSONReader::JSONReader()
{
  // pass.
}

std::string Utilities::JSONReader::getFormatName(int index)
{
  std::string filePath {
    "C://Users/rmvir/Desktop/scc300-Win3D/resources/pixel_formats.json"};
  
  auto json = this->readJsonFromFile(filePath);
  auto object = json.at(index);
  
  return object.at("shortName");
}

nlohmann::json Utilities::JSONReader::readJsonFromFile(std::string filePath)
{
  std::ifstream fileStream {filePath};
  auto json = nlohmann::json::parse(fileStream);

  fileStream.close();

  return json;
}