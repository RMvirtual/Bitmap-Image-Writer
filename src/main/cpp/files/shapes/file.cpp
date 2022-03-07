#include <vector>

#include "src/main/cpp/files/shapes/file.h"
#include "src/main/cpp/files/paths/file.h"

Files::Alphabet::Alphabet()
{
  std::string systemPath {"C://Users/rmvir/Desktop/scc300-Win3D/"};

  Files::FilePaths files {};
  auto filePath = files.filePath("alphabet_2d");

  this->reader = Files::JSONReader::fromObjectFile(systemPath + filePath);
}

Geometry::LineMesh Files::Alphabet::letter(std::string letter)
{
  auto lineValues = this->reader.value<std::vector<std::vector<double>>>(
    letter);

  std::vector<Maths::Vector> vectors {};

  for (auto point : lineValues)
    vectors.push_back({point});

  int noOfVectors = vectors.size();
  Geometry::LineMesh lineMesh;

  for (int vectorNo = 1; vectorNo < noOfVectors; vectorNo++) {
    Geometry::Line line = {vectors[vectorNo-1], vectors[vectorNo]};
    lineMesh.add(line);
  }

  return lineMesh;
}