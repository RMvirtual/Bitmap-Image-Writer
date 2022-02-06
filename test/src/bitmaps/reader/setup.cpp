#include "test/src/bitmaps/reader/fixture.h"
#include "src/bitmaps/formats/formats.h"

void BitmapReaderTest::setupCorrectImage()
{
  auto format = Bitmaps::format(24);
  format.setWidthInPixels(2);
  format.setHeightInPixels(2); 

  this->image = {format};

  Bitmaps::Colours colours = format.colours();
  colours["red"] = 100;
  colours["green"] = 255;
  colours["blue"] = 255;

  this->image.fill(colours);
}