#include <memory>
#include <vector>

#include "gtest/gtest.h"
#include "src/test/cpp/text/textbox/fixture.h"
#include "src/main/cpp/bitmaps/writer/image/writer.h"

TEST_F(TextTest, ShouldSeparateUnpaddedTextLetters)
{
  this->correctLetters[1].translate({1, 0.0});
  this->correctLetters[2].translate({3, 0.0});
  this->correctLetters[3].translate({4, 0.0});

  this->compare(this->correctLetters, text);
}

TEST_F(TextTest, ShouldPadText)
{
  this->text.setPadding(1, 0);

  this->correctLetters[1].translate({2, 0.0});
  this->correctLetters[2].translate({5, 0.0});
  this->correctLetters[3].translate({7, 0.0});

  this->compare(this->correctLetters, text);
}

TEST_F(TextTest, ShouldTranslateUnpaddedText)
{
  this->text.translate({5, 3});

  this->correctLetters[0].translate({5, 3});
  this->correctLetters[1].translate({6, 3});
  this->correctLetters[2].translate({8, 3});
  this->correctLetters[3].translate({9, 3});

  this->compare(this->correctLetters, text);
}

TEST_F(TextTest, ShouldPadTranslatedText)
{
  this->text.translate({5, 3});
  this->text.setPadding(1, 0);

  this->correctLetters[0].translate({5, 3});
  this->correctLetters[1].translate({7, 3});
  this->correctLetters[2].translate({10, 3});
  this->correctLetters[3].translate({12, 3});

  this->compare(this->correctLetters, text);
}

TEST_F(TextTest, ShouldScaleUnpaddedText)
{
  this->text.scale(2);
  this->correctLetters[0].scale(2);

  this->correctLetters[1].scale(2);
  this->correctLetters[1].translate({2, 0.0});

  this->correctLetters[2].scale(2);
  this->correctLetters[2].translate({6, 0.0});

  this->correctLetters[3].scale(2);
  this->correctLetters[3].translate({8, 0.0});

  this->compare(this->correctLetters, text);
}

TEST_F(TextTest, ShouldScalePaddedText)
{
  this->text.setPadding(1, 0.0);
  this->text.scale(2);

  this->correctLetters[0].scale(2);             // 0-1 letter.

  this->correctLetters[1].scale(2);             // 3-4 space, 5-9 letter.
  this->correctLetters[1].translate({5, 0.0});

  this->correctLetters[2].scale(2);             // 10-11 space, 12-14 letter.
  this->correctLetters[2].translate({12, 0.0});

  this->correctLetters[3].scale(2);             // 15-16 space, 17-21 letter.
  this->correctLetters[3].translate({17, 0.0});

  this->compare(this->correctLetters, text);
}

TEST_F(TextTest, ShouldScaleTranslatedText)
{
  this->text.setPadding(1, 0.0);
  this->text.scale(2);

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