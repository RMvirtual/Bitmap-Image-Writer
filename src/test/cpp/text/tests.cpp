#include <memory>
#include <vector>

#include "gtest/gtest.h"
#include "src/test/cpp/text/fixture.h"
#include "src/main/cpp/bitmaps/writer/image/writer.h"
#include "src/main/cpp/text/2d/text.h"

TEST_F(TextTest, ShouldCreateTextWithNoPadding)
{
  Text::Text2D text {"haha"};

  Geometry::LineMesh letterA = {{
    {{0.0,0.0}, {1, 2}},
    {{1,2}, {2, 0.0}},
    {{2,0.0}, {0.5, 1}},
    {{0.5,1}, {1.5, 1}},
  }};

  Geometry::LineMesh letterH = {{
    {{0.0,0.0}, {0.0, 3}},
    {{0.0,3}, {0.0, 2}},
    {{0.0,2}, {2, 2}},
    {{2,2}, {2, 0.0}},
    {{2,0.0}, {2, 3}}
  }};


  std::vector<Geometry::LineMesh> correctLineMeshes = {
    letterH, letterA, letterH, letterA};

  EXPECT_TRUE(false);
}

TEST_F(TextTest, ShouldCreateTextImageFile)
{
  auto image = this->redImage();

  Text::Text2D text {"haha"};
  text.setPadding(50, 0);
  text.scale(25);
  text.translate({100,100});

  this->rasteriser.setWritableImage(image);
  this->rasteriser.draw(text);

  Bitmaps::ImageWriter writer;
  
  writer.writeToFile(
    *image,
    "C:/Users/rmvir/Desktop/scc300-Win3D/resources/test/output/text.bmp"
  );
}