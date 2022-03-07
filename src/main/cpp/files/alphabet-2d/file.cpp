#include <vector>

#include "src/main/cpp/files/alphabet-2d/file.h"
#include "src/main/cpp/files/paths/file.h"

Geometry::LineMesh Files::Alphabet2D::letter(std::string letter)
{
  std::string systemPath {"C://Users/rmvir/Desktop/scc300-Win3D/"};

  Files::FilePaths files {};
  auto filePath = files.filePath("alphabet_2d");

  auto reader = Files::JSONReader::fromObjectFile(systemPath + filePath);
  
  auto lineValues = reader.value<std::vector<std::vector<double>>>(
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