#include <memory>
#include <vector>

#include "gtest/gtest.h"
#include "src/test/cpp/text/textbox/fixture.h"
#include "src/main/cpp/bitmaps/writer/image/writer.h"

TEST_F(TextTest, ShouldCreateUnpaddedText)
{
  Text::Text2D text {"haha"};

  std::vector<Text::Letter> correctLetters {
    {"h"}, {"a"}, {"h"}, {"a"}};

  correctLetters[1].translate({1, 0.0});
  correctLetters[2].translate({3, 0.0});
  correctLetters[3].translate({4, 0.0});

  this->compare(correctLetters, text);
}

TEST_F(TextTest, ShouldCreatePaddedText)
{
  Text::Text2D text {"haha"};
  text.setPadding(1, 0);

  std::vector<Text::Letter> correctLetters {
    {"h"}, {"a"}, {"h"}, {"a"}};

  correctLetters[1].translate({2, 0.0});
  correctLetters[2].translate({5, 0.0});
  correctLetters[3].translate({7, 0.0});

  this->compare(correctLetters, text);
}

TEST_F(TextTest, ShouldCreateUnpaddedTranslatedText)
{
  Text::Text2D text {"haha"};
  text.translate({5, 3});
  EXPECT_TRUE(false);
}

TEST_F(TextTest, ShouldCreatePaddedTranslatedText)
{
  Text::Text2D text {"haha"};
  text.setPadding(1, 0.0);
  text.translate({5, 3});
  EXPECT_TRUE(false);
}

TEST_F(TextTest, ShouldCreateUnpaddedScaledText)
{
  Text::Text2D text {"h"};
  text.scale(2);
  EXPECT_TRUE(false);
}

TEST_F(TextTest, ShouldCreatePaddedScaledText)
{
  Text::Text2D text {"h"};
  text.setPadding(1, 0.0);
  text.scale(2);

  EXPECT_TRUE(false);
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