#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "lib/nlohmann/json.hpp"

namespace Files {
class JSONReader
{
public:
  JSONReader();

  void read(std::string filePath);
  std::vector<std::string> fieldNames();
  int numberOfObjects();
    
  template <class T>
  T value(std::string fieldName)
  {
    auto object = this->json.at(0);

    return object.at(fieldName);
  }

  template <class T>
  T value(int index, std::string fieldName)
  {
    auto object = this->json.at(index);
    
    return object.at(fieldName);
  }
 
protected:
  nlohmann::json json;

private:
  nlohmann::json readJsonFromFile(std::string filePath);
};}