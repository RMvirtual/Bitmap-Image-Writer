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
  this->correctLetters[0].scaleIncludingOrigin(2);

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

  this->correctLetters[0].scaleIncludingOrigin(2);

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

  this->correctLetters[0].scaleIncludingOrigin(2);
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
  Maths::Vector origin {5, 3};
  this->text.translate(origin);
  this->text.scale(2);

  this->correctLetters[0].translate({5, 3});    
  this->correctLetters[0].scale(2, origin);

  this->correctLetters[1].translate({6, 3});
  this->correctLetters[1].scale(2, origin);

  this->correctLetters[2].translate({8, 3});
  this->correctLetters[2].scale(2, origin);

  this->correctLetters[3].translate({9, 3});
  this->correctLetters[3].scale(2, origin);

  this->compare(this->correctLetters, text);
}

TEST_F(TextTest, ShouldGetTranslatedOrigin)
{
  this->text.translate({5, 3});
  auto origin = this->text.origin();
  Maths::Vector correctOrigin {5, 3};

  this->compare(correctOrigin, origin);
}

TEST_F(TextTest, ShouldCreateTextImageFile)
{
  auto image = this->redImage();

  Text::Text2D text1 {"abcdefghijklm"};
  text1.setPadding(0.25, 0.0);
  text1.scale(20);
  text1.translate({10, 200});

  Text::Text2D text2 {"nopqrstuvwxyz"};
  text2.setPadding(0.25, 0.0);
  text2.scale(20);
  text2.translate({10, 100});

  Rasterisation::Rasteriser rasteriser {image};
  rasteriser.draw(text1);
  rasteriser.draw(text2);

  Bitmaps::ImageWriter writer;
  
  writer.writeToFile(
    image,
    "C:/Users/rmvir/Desktop/scc300-Win3D/resources/test/output/text.bmp"
  );

  EXPECT_TRUE(false);
}