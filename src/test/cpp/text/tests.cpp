#include <memory>
#include <vector>

#include "gtest/gtest.h"
#include "src/test/cpp/text/fixture.h"
#include "src/main/cpp/bitmaps/writer/image/writer.h"
#include "src/main/cpp/text/2d/text.h"

TEST_F(TextTest, ShouldCreateUnpaddedText)
{
  this->setupUnpaddedText();
  Text::Text2D text {"haha"};
  this->compare(text);
}

TEST_F(TextTest, ShouldCreatePaddedText)
{
  this->setupPaddedText();
  Text::Text2D text {"haha"};
  text.setPadding(1,0);
  this->compare(text);
}

TEST_F(TextTest, ShouldCreateUnpaddedTranslatedText)
{
  this->setupUnpaddedTranslatedText();
  Text::Text2D text {"haha"};
  text.translate({5, 3});
  this->compare(text);
}

TEST_F(TextTest, ShouldCreatePaddedTranslatedText)
{
  this->setupPaddedTranslatedText();
  Text::Text2D text {"haha"};
  text.setPadding(1,0);
  text.translate({5, 3});
  this->compare(text);
}

TEST_F(TextTest, ShouldCreateUnpaddedScaledText)
{
  this->setupUnpaddedScaledText();
  Text::Text2D text {"h"};
  text.scale(2);
  this->compare(text);
}

TEST_F(TextTest, ShouldCreatePaddedScaledText)
{
  this->setupPaddedScaledPaddedText();
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