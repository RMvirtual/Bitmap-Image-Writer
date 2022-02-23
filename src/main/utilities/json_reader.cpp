#include "lib/nlohmann/json.hpp"
#include "src/main/utilities/json_reader.h"

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

nlohmann::json Utilities::JSONReader::readJsonFromFile(std::string filePath)
{
  std::ifstream fileStream {filePath};
  auto json = nlohmann::json::parse(fileStream);

  fileStream.close();

  return json;
}

int Utilities::JSONReader::numberOfObjects()
{
  auto array = this->json.get<nlohmann::json::array_t>();
  
  return array.size();
}