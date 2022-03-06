#include "src/main/cpp/files/shapes/file.h"
#include "src/main/cpp/files/paths/file.h"

#include <iostream>

Files::Alphabet::Alphabet()
{
  std::string systemPath {"C://Users/rmvir/Desktop/scc300-Win3D/"};

  Files::FilePaths files {};
  auto filePath = files.filePath("alphabet_2d");

  this->reader = Files::JSONReader::fromObjectFile(systemPath + filePath);
}

std::vector<std::vector<double>> Files::Alphabet::letter(std::string letter)
{
  return this->reader.value<std::vector<std::vector<double>>>(letter);
}