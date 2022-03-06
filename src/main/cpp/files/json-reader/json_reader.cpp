#include "lib/nlohmann/json.hpp"
#include "src/main/cpp/files/json-reader/json_reader.h"

Files::JSONReader::JSONReader()
{
  // pass.
}

Files::JSONReader Files::JSONReader::fromObjectFile(std::string filePath)
{
  std::ifstream fileStream {filePath};
  auto json = nlohmann::json::parse(fileStream);

  fileStream.close();

  Files::JSONReader jsonReader {};
  jsonReader.json = json;

  return jsonReader;
}

Files::JSONReader Files::JSONReader::fromArrayFile(std::string filePath)
{
  std::ifstream fileStream {filePath};
  auto json = nlohmann::json::parse(fileStream);

  fileStream.close();

  Files::JSONReader jsonReader {};
  jsonReader.json = json;

  return jsonReader;
}

nlohmann::json Files::JSONReader::readJsonFromFile(std::string filePath)
{
  std::ifstream fileStream {filePath};
  auto json = nlohmann::json::parse(fileStream);

  fileStream.close();

  return json;
}

void Files::JSONReader::read(std::string filePath)
{
  this->json = this->readJsonFromFile(filePath);
}

std::vector<std::string> Files::JSONReader::fieldNames()
{
  std::vector<std::string> fields {};
  auto array = this->json.get<nlohmann::json::array_t>();

  for (auto object : array)
    for (auto keyAndValue : object.items())
      fields.push_back(keyAndValue.key());

  return fields;
}

int Files::JSONReader::numberOfObjects()
{
  auto array = this->json.get<nlohmann::json::array_t>();
  
  return array.size();
}