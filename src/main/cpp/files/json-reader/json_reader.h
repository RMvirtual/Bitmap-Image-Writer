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

  static JSONReader fromObjectFile(std::string filePath);
  static JSONReader fromArrayFile(std::string filePath);

  void read(std::string filePath);
  std::vector<std::string> fieldNames();
  int numberOfObjects();

  template <class T>
  T value(std::string fieldName)
  {
    return this->json[fieldName];
  }

  template <class T>
  T value(int index, std::string fieldName)
  {
    auto object = this->json[index];
    
    return object[fieldName];
  }

protected:
  nlohmann::json json;

private:
  nlohmann::json readJsonFromFile(std::string filePath);
};}