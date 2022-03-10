#pragma once

#include <memory>
#include "src/main/cpp/app/demo/interface/demo.h"
#include "src/main/cpp/gui/image_viewer.h"
#include "src/main/cpp/text/2d/textbox/text.h"
#include "src/main/cpp/rasterisation/rasteriser/rasteriser.h"

namespace Demo {
class TextDemo : public Demo
{
public:
  TextDemo();
  ~TextDemo();

  void start();
  void updateImage();

private:
  GUI::ImageViewer* viewer;

  std::shared_ptr<Bitmaps::Image> redImage();
  Text::Text2D textBox();
};}