#include "src/main/cpp/files/shapes/file.h"
#include "src/main/cpp/files/paths/file.h"

Files::Alphabet::Alphabet()
{
  // Hardcoding system path here till a reader is developed.
  std::string systemPath {"C://Users/rmvir/Desktop/scc300-Win3D/"};

  Files::FilePaths files {};
  auto filePath = files.filePath("alphabet_2d");

  this->reader = {};
  this->reader.read(systemPath + filePath);
}

std::vector<std::vector<double>> Files::Alphabet::letter(std::string letter)
{
  int noOfLetters = this->reader.numberOfObjects();

  return {};
}