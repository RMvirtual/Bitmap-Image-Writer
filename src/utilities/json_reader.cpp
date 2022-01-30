#include "lib/nlohmann/json.hpp"
#include "src/utilities/json_reader.h"

#include <iostream>
#include <fstream>
#include <string>

Utilities::JSONReader::JSONReader()
{
  // pass.
}

void Utilities::JSONReader::read(std::string filePath)
{
  this->json = this->readJsonFromFile(filePath);
}

std::vector<std::string> Utilities::JSONReader::fieldNames()
{
  std::vector<std::string> fields {};
  auto array = this->json.get<nlohmann::json::array_t>();

  for (auto object : array)
    for (auto keyAndValue : object.items())
      fields.push_back(keyAndValue.key());

  return fields;
}

std::string Utilities::JSONReader::value(std::string fieldName)
{
  auto object = this->json.at(0);
  
  return object.at(fieldName);
}

nlohmann::json Utilities::JSONReader::readJsonFromFile(std::string filePath)
{
  std::ifstream fileStream {filePath};
  auto json = nlohmann::json::parse(fileStream);

  fileStream.close();

  return json;
}