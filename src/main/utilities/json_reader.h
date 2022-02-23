#ifndef JSON_READER_H
#define JSON_READER_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

#include "lib/nlohmann/json.hpp"

namespace Utilities {
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

#endif