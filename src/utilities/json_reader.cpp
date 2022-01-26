#include "lib/nlohmann/json.hpp"
#include "src/utilities/json_reader.h"

#include <iostream>
#include <fstream>
#include <string>

Utilities::JSONReader::JSONReader()
{
  this->pixelFormatsFilePath = {
    "C://Users/rmvir/Desktop/scc300-Win3D/resources/pixel_formats.json"};
}

std::string Utilities::JSONReader::getFormatName(int index)
{  
  auto json = this->readJsonFromFile(this->pixelFormatsFilePath);
  auto object = json.at(index);
  
  return object.at("shortName");
}

int Utilities::JSONReader::getBitsPerPixel(int index)
{
  auto json = this->readJsonFromFile(this->pixelFormatsFilePath);
  auto object = json.at(index);
  
  return object.at("bitsPerPixel");
}

nlohmann::json Utilities::JSONReader::readJsonFromFile(std::string filePath)
{
  std::ifstream fileStream {filePath};
  auto json = nlohmann::json::parse(fileStream);

  fileStream.close();

  return json;
}