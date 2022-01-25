#include "lib/nlohmann/json.hpp"
#include "src/utilities/json_reader.h"

#include <iostream>
#include <fstream>
#include <string>

Utilities::JSONReader::JSONReader()
{
  std::ifstream fileInput {"C://Users/rmvir/Desktop/scc300-Win3D/resources/pixel_formats.json"};

  std::string donkeh;

  while (std::getline(fileInput, donkeh))
    std::cout << donkeh; 
  
  fileInput.close();
}