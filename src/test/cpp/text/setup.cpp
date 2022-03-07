#include "src/main/cpp/files/alphabet-2d/file.h"

#include "src/main/cpp/bitmaps/formats/formats.h"
#include "src/main/cpp/bitmaps/image/image.h"
#include "src/test/cpp/text/fixture.h"

std::shared_ptr<Bitmaps::Image> TextTest::redImage()
{
  auto format = Bitmaps::format("RGB24");
  format.setHeightInPixels(500);
  format.setWidthInPixels(500);

  auto redColours = format.colours();
  redColours["red"] = 255;
  redColours["green"] = 0;
  redColours["blue"] = 0;

  auto image = std::make_shared<Bitmaps::Image>(format);
  image->fill(redColours);

  return image;
}

void TextTest::setupCorrectUnpaddedText()
{
  this->correctLineMeshes = this->correctHahaLineMeshes();

  this->correctLineMeshes[1].translate({2, 0.0});
  this->correctLineMeshes[2].translate({4, 0.0});
  this->correctLineMeshes[3].translate({6, 0.0});
}

void TextTest::setupCorrectPaddedText()
{
  this->correctLineMeshes = this->correctHahaLineMeshes();

  this->correctLineMeshes[1].translate({3, 0.0});
  this->correctLineMeshes[2].translate({6, 0.0});
  this->correctLineMeshes[3].translate({9, 0.0});
}

void TextTest::setupCorrectScaledUnpaddedText()
{
  this->correctLineMeshes = this->correctHahaLineMeshes();

  for (auto& mesh : this->correctLineMeshes)
    mesh.scale(2);

  this->correctLineMeshes[1].translate({4, 0.0});
  this->correctLineMeshes[2].translate({8, 0.0});
  this->correctLineMeshes[3].translate({12, 0.0});
}

void TextTest::setupCorrectScaledPaddedText()
{
  this->correctLineMeshes = this->correctHahaLineMeshes();

  for (auto& mesh : this->correctLineMeshes)
    mesh.scale(2);

  this->correctLineMeshes[1].translate({6, 0.0});
  this->correctLineMeshes[2].translate({12, 0.0});
  this->correctLineMeshes[3].translate({18, 0.0});
}

std::vector<Geometry::LineMesh> TextTest::correctHahaLineMeshes()
{
  auto letterH = Files::Alphabet2D::letter("h");
  auto letterA = Files::Alphabet2D::letter("a");

  return {letterH, letterA, letterH, letterA};
}