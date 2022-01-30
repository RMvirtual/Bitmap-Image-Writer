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

std::string Utilities::JSONReader::getFormatName(int index)
{  
  auto object = this->json.at(index);
  
  return object.at("name");
}

int Utilities::JSONReader::getBitsPerPixel(int index)
{
  auto object = this->json.at(index);
  
  return object.at("bitsPerPixel");
}

std::vector<std::string> Utilities::JSONReader::getColours(int index)
{
  auto object = this->json.at(index);

  return object.at("colours"); 
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

nlohmann::json Utilities::JSONReader::readJsonFromFile(std::string filePath)
{
  std::ifstream fileStream {filePath};
  auto json = nlohmann::json::parse(fileStream);

  fileStream.close();

  return json;
}
