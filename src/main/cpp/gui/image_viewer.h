#pragma once

#include <string>
#include "src/main/cpp/gui/python_interface.h"

namespace GUI {
class ImageViewer
{
public:
  ImageViewer();

  void loadImage(std::string imagePath);
  void refresh();
  void show();
  
private:
  GUI::PythonInterface interface;
};}