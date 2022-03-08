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

  this->correctLetters[1].scaleIncludingOrigin(2);
  this->correctLetters[1].translate({2, 0.0});

  this->correctLetters[2].scaleIncludingOrigin(2);
  this->correctLetters[2].translate({6, 0.0});

  this->correctLetters[3].scaleIncludingOrigin(2);
  this->correctLetters[3].translate({8, 0.0});

  this->compare(this->correctLetters, text);
}

TEST_F(TextTest, ShouldScalePaddedText)
{
  this->text.setPadding(1, 0.0);
  this->text.scale(2);

  this->correctLetters[0].scale(2);

  this->correctLetters[1].scaleIncludingOrigin(2);
  this->correctLetters[1].translate({5, 0.0});

  this->correctLetters[2].scaleIncludingOrigin(2);
  this->correctLetters[2].translate({12, 0.0});

  this->correctLetters[3].scaleIncludingOrigin(2);
  this->correctLetters[3].translate({17, 0.0});

  this->compare(this->correctLetters, text);
}

TEST_F(TextTest, ShouldTranslateScaledText)
{
  this->text.scale(2);
  this->text.translate({5, 3});

  this->correctLetters[0].scale(2);
  this->correctLetters[0].translate({5, 3});    

  this->correctLetters[1].scaleIncludingOrigin(2);
  this->correctLetters[1].translate({7, 3});

  this->correctLetters[2].scaleIncludingOrigin(2);
  this->correctLetters[2].translate({11, 3});

  this->correctLetters[3].scaleIncludingOrigin(2);
  this->correctLetters[3].translate({13, 3});

  this->compare(this->correctLetters, text);
}

TEST_F(TextTest, ShouldScaleTranslatedText)
{
  this->text.translate({5, 3});
  this->text.scale(2);

  this->correctLetters[0].translate({5, 3});    
  this->correctLetters[0].scale(2);

  this->correctLetters[1].translate({6, 3});
  this->correctLetters[1].scaleIncludingOrigin(2);

  this->correctLetters[2].translate({8, 3});
  this->correctLetters[2].scaleIncludingOrigin(2);

  this->correctLetters[3].translate({9, 3});
  this->correctLetters[3].scaleIncludingOrigin(2);

  this->compare(this->correctLetters, text);
}

TEST_F(TextTest, ShouldCreateTextImageFile)
{
  auto image = this->redImage();

  Text::Text2D text {"abcdh"};
  text.setPadding(0.25, 0.0);
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