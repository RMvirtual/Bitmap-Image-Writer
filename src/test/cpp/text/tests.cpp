#include <memory>
#include <vector>

#include "gtest/gtest.h"
#include "src/test/cpp/text/fixture.h"
#include "src/main/cpp/bitmaps/writer/image/writer.h"
#include "src/main/cpp/text/2d/text.h"

TEST_F(TextTest, ShouldCreateTextWithNoPadding)
{
  this->setupCorrectUnpaddedText();
  Text::Text2D text {"haha"};
  this->compare(text);
}

TEST_F(TextTest, ShouldCreateTextWithPadding)
{
  this->setupCorrectPaddedText();
  Text::Text2D text {"haha"};
  text.setPadding(1,0);
  this->compare(text);
}

TEST_F(TextTest, ShouldCreateScaledTextWithNoPadding)
{
  this->setupCorrectScaledUnpaddedText();
  Text::Text2D text {"h"};
  text.scale(2);
  this->compare(text);
}

TEST_F(TextTest, ShouldCreateScaledTextWithPadding)
{
  this->setupCorrectScaledPaddedText();
  Text::Text2D text {"haha"};
  text.setPadding(1, 0.0);
  text.scale(2);

  this->compare(text);
}

TEST_F(TextTest, ShouldCreateTextImageFile)
{
  auto image = this->redImage();

  Text::Text2D text {"abch"};
  text.scale(20);
  text.translate({25, 100});
  this->rasteriser.setWritableImage(image);
  this->rasteriser.draw(text);

  Bitmaps::ImageWriter writer;
  
  writer.writeToFile(
    *image,
    "C:/Users/rmvir/Desktop/scc300-Win3D/resources/test/output/text.bmp"
  );
}