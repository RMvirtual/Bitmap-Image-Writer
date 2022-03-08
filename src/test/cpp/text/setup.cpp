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

void TextTest::setupUnpaddedText()
{
  this->correctLineMeshes = this->correctHahaLineMeshes();

  this->correctLineMeshes[1].translate({1, 0.0});
  this->correctLineMeshes[2].translate({3, 0.0});
  this->correctLineMeshes[3].translate({4, 0.0});
}

void TextTest::setupPaddedText()
{
  this->correctLineMeshes = this->correctHahaLineMeshes();

  this->correctLineMeshes[1].translate({2, 0.0});
  this->correctLineMeshes[2].translate({5, 0.0});
  this->correctLineMeshes[3].translate({7, 0.0});
}

void TextTest::setupUnpaddedTranslatedText()
{
  this->correctLineMeshes = this->correctHahaLineMeshes();

  this->correctLineMeshes[0].translate({5, 3});
  this->correctLineMeshes[1].translate({6, 3});
  this->correctLineMeshes[2].translate({8, 3});
  this->correctLineMeshes[3].translate({9, 3});
}

void TextTest::setupPaddedTranslatedText()
{
  // translate 5,3
  // add padding of 1, 0
  this->correctLineMeshes = this->correctHahaLineMeshes();

  this->correctLineMeshes[0].translate({5, 3});
  this->correctLineMeshes[1].translate({7, 3});
  this->correctLineMeshes[2].translate({10, 3});
  this->correctLineMeshes[3].translate({12, 3});
}

void TextTest::setupUnpaddedScaledText()
{
  this->correctLineMeshes = {Files::Alphabet2D::letter("h")};

  for (auto& mesh : this->correctLineMeshes)
    mesh.scale(2);
}

void TextTest::setupPaddedScaledPaddedText()
{
  this->correctLineMeshes = this->correctHahaLineMeshes();

  // padding = 2.
  // h = 2 / 4
  // a = 4 / 6

  this->correctLineMeshes[1].translate({4, 0.0});
  this->correctLineMeshes[2].translate({10, 0.0});
  this->correctLineMeshes[3].translate({14, 0.0});

  for (auto& mesh : this->correctLineMeshes)
    mesh.scale(2);
}

std::vector<Geometry::LineMesh> TextTest::correctHahaLineMeshes()
{
  auto letterH = Files::Alphabet2D::letter("h");
  auto letterA = Files::Alphabet2D::letter("a");

  return {letterH, letterA, letterH, letterA};
}