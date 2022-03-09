#pragma once

#include "src/main/cpp/app/demo/interface/demo.h"
#include "src/main/cpp/gui/image_viewer.h"

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
};}