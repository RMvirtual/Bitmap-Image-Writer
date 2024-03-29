#include <memory>

#include "src/test/cpp/rasterisation/rasteriser/fixture.h"
#include "src/main/cpp/bitmaps/formats/formats.h"
#include "src/main/cpp/bitmaps/image/image.h"
#include "src/main/cpp/bitmaps/writer/image/writer.h"

TEST_F(RasterisationTest, ShouldDrawTriangle)
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

  Geometry::Triangle triangle;
  triangle.translate({200,200});
  triangle.scale(100);

  Rasterisation::Rasteriser rasteriser {image};
  rasteriser.draw(triangle);

  Bitmaps::ImageWriter writer;
  
  writer.writeToFile(
    image, 
    "C:/Users/rmvir/Desktop/scc300-Win3D/resources/test/output/triangle.bmp"
  );
}